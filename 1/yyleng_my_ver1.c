#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <limits.h>

#define NELEMS(arr) (sizeof(arr) / sizeof(arr[0]))
 
#define da_dim(name, type)  type *name = NULL;          \
                            int _qy_ ## name ## _p = 0;  \
                            int _qy_ ## name ## _max = 0
#define da_rewind(name)     _qy_ ## name ## _p = 0
#define da_redim(name)      do {if (_qy_ ## name ## _p >= _qy_ ## name ## _max) \
                                name = realloc(name, (_qy_ ## name ## _max += 32) * sizeof(name[0]));} while (0)
#define da_append(name, x)  do {da_redim(name); name[_qy_ ## name ## _p++] = x;} while (0)
#define da_len(name)        _qy_ ## name ## _p
 
typedef enum {
    tk_EOI, tk_Mul, tk_Div, tk_Mod, tk_Add, tk_Sub, tk_Negate, tk_Not, tk_Lss, tk_Leq,
    tk_Gtr, tk_Geq, tk_Eq, tk_Neq, tk_Assign, tk_And, tk_Or, tk_If, tk_Else, tk_While,
    tk_Print, tk_Putc, tk_Lparen, tk_Rparen, tk_Lbrace, tk_Rbrace, tk_Semi, tk_Comma,
    tk_Ident, tk_Integer, tk_Hash, tk_dot, tk_Lsqbr, tk_Rsqbr, tk_do, tk_break, tk_Continue,
    tk_Float, tk_Double, tk_return, tk_Char, tk_Case, tk_Sizeof, tk_Long, tk_Short, tk_Typedef, 
    tk_Switch, tk_Unsigned, tk_Void, tk_static, tk_struct, tk_goto, tk_BitwiseAnd, tk_BitwiseOr, tk_String
} TokenType;
 
typedef struct {
    TokenType tok;
    int err_ln, err_col;
    union {
        int n;                 
        char *text;             
    };
} tok_s;
 
//GLOBAL VAR
FILE *source_fp, *dest_fp;
int line = 1, col = 0, the_ch = ' ';
da_dim(text, char);
//////////////////


//API declarations
void init_io(FILE **fp, FILE *std, const char mode[], const char fn[]);
void run();
tok_s gettok();
int next_ch();
tok_s division_or_comment(int, int);
void error(int, int, const char *, ... ); 
tok_s character_literal(int, int, int);
tok_s follow(int, TokenType, TokenType, int, int);
tok_s str_literal(int, int, int); 
tok_s identifier_or_integer(int, int);
TokenType get_ident_type(const char *);
int word_comparison(const void*, const void*);
///////////

int main(int argc, char *argv[]) {
    init_io(&source_fp, stdin,  "r",  argc > 1 ? argv[1] : "");
    init_io(&dest_fp,   stdout, "wb", argc > 2 ? argv[2] : "");
    run();
    return 0;
}

//APIs
void init_io(FILE **fp, FILE *std, const char mode[], const char fn[]) {
    if (fn[0] == '\0')
        *fp = std;
    else if ((*fp = fopen(fn, mode)) == NULL)
        error(0, 0, "Can't open %s\n", fn);
}

void run() {    /* tokenize the given input */
    tok_s tok;
    do {
        tok = gettok();
        fprintf(dest_fp, "%5d  %5d %.15s",
            tok.err_ln, tok.err_col,
            &"End_of_input     Op_multiply      Op_divide        Op_mod           Op_add           "
             "Op_subtract      Op_negate        Op_not           Op_less          Op_lessequal     "
             "Op_greater       Op_greaterequal  Op_equal         Op_notequal      Op_assign        "
             "Op_and           Op_or            Keyword_if       Keyword_else     Keyword_while    "
             "Keyword_print    Keyword_putc     LeftParen        RightParen       LeftBrace        "
             "RightBrace       Semicolon        Comma            Identifier       Integer          "
             "Hash             Dot              LeftSquareBr     RightSquareBr    Keyword_Do       "
             "Keyword_Break    Keyword_Continue Float            Double           Keyword_Return   "
             "Keyword_Char     Keyword_Case     Keyword_SizeOf   Keyword_long     KeyWord_Short    "
             "Keyword_Typedef  Keyword_Switch   Keyword_Unsigned Keyword_Void     Keyword_Static   "
             "Keyword_Struct   Keyword_Goto     BitWiseAnd       BitWiseOr        Keyword_String"
            [tok.tok * 17]);
        if (tok.tok == tk_Integer)     fprintf(dest_fp, "  %4d",   tok.n);
        else if (tok.tok == tk_Ident)  fprintf(dest_fp, " %s",     tok.text);
        else if (tok.tok == tk_String) fprintf(dest_fp, " \"%s\"", tok.text);
        fprintf(dest_fp, "\n");
    } while (tok.tok != tk_EOI);
    if (dest_fp != stdout)
        fclose(dest_fp);
}

tok_s gettok() {       
    while (isspace(the_ch))
        next_ch();
    int err_line = line;
    int err_col  = col;
    /*
    tk_EOI, tk_Mul, tk_Div, tk_Mod, tk_Add, tk_Sub, tk_Negate, tk_Not, tk_Lss, tk_Leq,
    tk_Gtr, tk_Geq, tk_Eq, tk_Neq, tk_Assign, tk_And, tk_Or, tk_If, tk_Else, tk_While,
    tk_Print, tk_Putc, tk_Lparen, tk_Rparen, tk_Lbrace, tk_Rbrace, tk_Semi, tk_Comma,
    tk_Ident, tk_Integer, tk_Hash, tk_dot, tk_Lsqbr, tk_Rsqbr, tk_do, tk_break, tk_Continue,
    tk_Float, tk_Double, tk_return, tk_Char, tk_Case, tk_Sizeof, tk_Long, tk_Short, tk_Typedef, 
    tk_Switch, tk_Unsigned, tk_Void, tk_static, tk_struct, tk_goto, tk_BitwiseAnd, tk_BitwiseOr, tk_String
     */
    switch (the_ch) {
        case '{':  next_ch(); return (tok_s){tk_Lbrace, err_line, err_col, {0}};
        case '}':  next_ch(); return (tok_s){tk_Rbrace, err_line, err_col, {0}};
        case '(':  next_ch(); return (tok_s){tk_Lparen, err_line, err_col, {0}};
        case ')':  next_ch(); return (tok_s){tk_Rparen, err_line, err_col, {0}};
        case '[':  next_ch(); return (tok_s){tk_Lsqbr, err_line, err_col, {0}};
        case ']':  next_ch(); return (tok_s){tk_Rsqbr, err_line, err_col, {0}};
        case '+':  next_ch(); return (tok_s){tk_Add, err_line, err_col, {0}};
        case '-':  next_ch(); return (tok_s){tk_Sub, err_line, err_col, {0}};
        case '*':  next_ch(); return (tok_s){tk_Mul, err_line, err_col, {0}};
        case '%':  next_ch(); return (tok_s){tk_Mod, err_line, err_col, {0}};
        case ';':  next_ch(); return (tok_s){tk_Semi, err_line, err_col, {0}};
        case ',':  next_ch(); return (tok_s){tk_Comma,err_line, err_col, {0}};
        case '#':  next_ch(); return (tok_s){tk_Hash,err_line, err_col, {0}};
        case '.':  next_ch(); return (tok_s){tk_dot,err_line, err_col, {0}};
        case '/':  next_ch(); return division_or_comment(err_line, err_col);
        case '\'': next_ch(); return character_literal(the_ch, err_line, err_col);
        case '<':  next_ch(); return follow('=', tk_Leq, tk_Lss,    err_line, err_col);
        case '>':  next_ch(); return follow('=', tk_Geq, tk_Gtr,    err_line, err_col);
        case '=':  next_ch(); return follow('=', tk_Eq,  tk_Assign, err_line, err_col);
        case '!':  next_ch(); return follow('=', tk_Neq, tk_Not,    err_line, err_col);
        case '&':  next_ch(); return follow('&', tk_And, tk_BitwiseAnd,    err_line, err_col);
        case '|':  next_ch(); return follow('|', tk_Or,  tk_BitwiseOr,    err_line, err_col);
        case '"' : return str_literal(the_ch, err_line, err_col);
        default:   return identifier_or_integer(err_line, err_col);
        case EOF:  return (tok_s){tk_EOI, err_line, err_col, {0}};
    }
}

////////////////////////////
void error(int err_line, int err_col, const char *fmt, ... ) {
    char buf[1000];
    va_list ap;
 
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    va_end(ap);
    printf("(%d,%d) error: %s\n", err_line, err_col, buf);
    exit(1);
}
 
int next_ch() {
    the_ch = getc(source_fp);
    ++col;
    if (the_ch == '\n') {
        ++line;
        col = 0;
    }
    return the_ch;
}
 
tok_s character_literal(int n, int err_line, int err_col) {   
    if (the_ch == '\'')
        error(err_line, err_col, "gettok: empty character constant");
    if (the_ch == '\\') {
        next_ch();
        if (the_ch == 'n')
            n = 10;
        else if (the_ch == '\\')
            n = '\\';
    }
    if (next_ch() != '\'')
        error(err_line, err_col, "multi-character constant");
    next_ch();
    return (tok_s){tk_Integer, err_line, err_col, {n}};
}
 
tok_s division_or_comment(int err_line, int err_col) { 
    if (the_ch != '*')
        return (tok_s){tk_Div, err_line, err_col, {0}};
 
    next_ch();
    for (;;) {
        if (the_ch == '*') {
            if (next_ch() == '/') {
                next_ch();
                return gettok();
            }
        } else if (the_ch == EOF)
            error(err_line, err_col, "EOF in comment");
        else
            next_ch();
    }
}
 
tok_s str_literal(int start, int err_line, int err_col) { 
    da_rewind(text);
 
    while (next_ch() != start) {
        if (the_ch == '\n') error(err_line, err_col, "EOL in string");
        if (the_ch == EOF)  error(err_line, err_col, "EOF in string");
        da_append(text, (char)the_ch);
    }
    da_append(text, '\0');
 
    next_ch();
    return (tok_s){tk_String, err_line, err_col, {.text=text}};
}
 
int word_comparison(const void *p1, const void *p2) {
    return strcmp(*(char **)p1, *(char **)p2);
}
 
TokenType get_ident_type(const char *ident) {
    static struct {
        char *s;
        TokenType sym;
    } kwds[] = {
        {"else",  tk_Else},
        {"if",    tk_If},
        {"printf", tk_Print},
        {"putc",  tk_Putc},
        {"while", tk_While},
        {"do", tk_do},
        {"break", tk_break},
        {"continue", tk_Continue},
        {"return", tk_return},
        {"char", tk_Char},
        {"sizeof", tk_Sizeof},
        {"case", tk_Case},
        {"typedef", tk_Typedef},
        {"switch", tk_Switch}, 
        {"unsigned", tk_Unsigned},
        {"void", tk_Void},
        {"static", tk_static},
        {"struct", tk_struct},
        {"goto", tk_goto},
        {"float", tk_Float},
        {"double", tk_Double},
        {"long", tk_Long},
        {"short", tk_Short},
    }, *kwp;
 
    return (kwp = bsearch(&ident, kwds, NELEMS(kwds), sizeof(kwds[0]), word_comparison)) == NULL ? tk_Ident : kwp->sym;
}
 
tok_s identifier_or_integer(int err_line, int err_col) {
    int n, is_number = true;
 
    da_rewind(text);
    while (isalnum(the_ch) || the_ch == '_') {
        da_append(text, (char)the_ch);
        if (!isdigit(the_ch))
            is_number = false;
        next_ch();
    }
    if (da_len(text) == 0)
        error(err_line, err_col, "gettok: unrecognized character (%d) '%c'\n", the_ch, the_ch);
    da_append(text, '\0');
    if (isdigit(text[0])) {
        if (!is_number)
            error(err_line, err_col, "invalid number: %s\n", text);
        n = strtol(text, NULL, 0);
        if (n == LONG_MAX && errno == ERANGE)
            error(err_line, err_col, "Number exceeds maximum value");
        return (tok_s){tk_Integer, err_line, err_col, {n}};
    }
    return (tok_s){get_ident_type(text), err_line, err_col, {.text=text}};
}
 
tok_s follow(int expect, TokenType ifyes, TokenType ifno, int err_line, int err_col) { 
    if (the_ch == expect) {
        next_ch();
        return (tok_s){ifyes, err_line, err_col, {0}};
    }
    if (ifno == tk_EOI)
        error(err_line, err_col, "follow: unrecognized character '%c' (%d)\n", the_ch, the_ch);
    return (tok_s){ifno, err_line, err_col, {0}};
}

