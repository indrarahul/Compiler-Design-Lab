/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "symbY.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "error.h"
#include "lex.yy.c"
#define DEBUG_INFO 0
#define MAX_FUNCTION 10
int yylex(void);
extern char* yytext;
extern FILE* yyin;
extern int yylineno;
int global_scope = 0;
int var_buffer[100];
int var_buffer_index = 0;
int scope_adjust = 0;
int function_index = 0;
struct entry{
	int entry_index;
	char var_name;
	int type[10];
	int scope[10];
	int line_no[10];
	int scope_array_index;
	int global_flag;
}symbol_table[MAX_FUNCTION][122],temp_table[122]; 

void insert_by_name(char *name);
int found(char *name);
void display_table(int table_index);
int check_for_same_scope(struct entry node1,struct entry node2);
void check_scope_declaration(char *name,int scope);
int check_type(char *name1,char *name2);
int is_number(const char *s);
void init_symbol_table(void);
void check_type_assign(char *name,int type,int scope);
void invalidate_scope_var(int target_scope);
void success(void);
void yyerror(char *s);
void assign_type(int t,int flag);

#line 55 "symbY.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{

	struct s1{
    	int i_type;
    	char *i_val;
    }p;

	struct s2{
		char *name;
		int i_type;
		char *i_val;
	}n;

    struct s3{
    	int i_type;
    }t;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 88 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define FOR_TOK 257
#define WHILE_TOK 258
#define SWITCH_TOK 259
#define CASE_TOK 260
#define IF_TOK 261
#define ELSE_TOK 262
#define BREAK_TOK 263
#define DEFAULT_TOK 264
#define RETURN_TOK 265
#define INCLUDE_TOK 266
#define DEFINE_TOK 267
#define MAIN_TOK 268
#define SEMICOLON_TOK 269
#define COMMA_TOK 270
#define DOT_TOK 271
#define LCURLY_TOK 272
#define RCURLY_TOK 273
#define RPAREN_TOK 274
#define LPAREN_TOK 275
#define ARRAY_BRACKET_LTOK 276
#define ARRAY_BRACKET_RTOK 277
#define ADDITION_TOK 278
#define INCREMENT_TOK 279
#define ADDITION_EQUAL_TOK 280
#define MINUS_TOK 281
#define DECREMENT_TOK 282
#define MINUS_EQUAL_TOK 283
#define MULTIPLICATION_TOK 284
#define MULTIPLICATION_EQUAL_TOK 285
#define DIVISION_EQUAL_TOK 286
#define DIVISION_TOK 287
#define MODULO_TOK 288
#define MODULO_EQUAL_TOK 289
#define RIGHT_SHIFT_TOK 290
#define GREATER_THAN_EQUAL_TOK 291
#define GREATER_TOK 292
#define LEFT_SHIFT_TOK 293
#define LESS_THAN_EQUAL_TOK 294
#define LESS_TOK 295
#define EQUAL_COMPARE_TOK 296
#define EQUAL_TOK 297
#define NOT_EQUAL_TOK 298
#define NOT_TOK 299
#define BIT_OR_EQUAL_TOK 300
#define BIT_OR_TOK 301
#define OR_TOK 302
#define AND_TOK 303
#define BIT_AND_EQUAL_TOK 304
#define BIT_AND_TOK 305
#define XOR_TOK 306
#define XOR_EQUAL_TOK 307
#define SPACE_TOK 308
#define COLON_TOK 309
#define ID_TOK 310
#define INT_CONST_TOK 311
#define INTEGER_TOK 312
#define FLOATING_TOK 313
#define DOUBLE_TOK 314
#define CHAR_TOK 315
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    5,    9,    5,    5,   11,   10,   10,    7,    7,
    7,    1,    1,    1,    1,   13,   15,    8,   14,   14,
   12,   12,   16,   16,   16,   16,   16,   16,   16,   16,
   23,   24,   20,   22,   22,   22,   25,   25,   21,   21,
   21,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,   18,   18,   18,   18,   18,   18,   18,   18,   19,
   19,   19,   19,    3,    3,    6,   17,    2,    2,
};
static const YYINT yylen[] = {                            2,
    1,    3,    0,    8,    0,    0,    8,    0,    4,    2,
    0,    1,    1,    1,    1,    0,    0,    6,    3,    0,
    2,    0,    2,    5,   11,    7,    5,    5,    1,    2,
    0,    0,    5,    6,    4,    0,    2,    0,    4,    4,
    4,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    3,    3,    3,    3,    3,    3,    3,    2,
    2,    2,    2,    1,    1,    2,    2,    3,    1,
};
static const YYINT yydefred[] = {                         0,
   12,   13,   14,   15,    0,    0,    1,    0,    0,   69,
    0,    0,    0,    0,    2,    0,    0,   68,   10,    0,
    3,    0,    0,    9,   16,    0,   22,    0,    4,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   22,
   17,   21,    0,    0,   29,    0,    0,    0,    0,    0,
   62,   63,   60,   61,    0,    0,    0,    0,   23,    0,
   30,    0,    0,    0,   64,   65,    0,    0,    0,    0,
    0,    0,    0,   19,   18,    0,    6,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   41,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   39,   40,    0,    0,   59,   53,   54,   55,   56,   57,
   58,   24,   31,   28,    0,   51,   42,   43,   44,   45,
   46,   47,   48,   49,   50,    0,    0,    0,    0,    7,
    0,    0,    0,   32,   26,    0,    0,   22,    0,    0,
    0,   22,    0,   33,    0,    0,    0,   35,   25,    0,
   37,   34,
};
static const YYINT yydgoto[] = {                          5,
   39,   11,   67,   73,    7,    8,   17,   40,   23,   29,
  103,   30,   27,   41,   58,   42,   43,   68,   44,  114,
   45,  134,  128,  139,  148,
};
static const YYINT yysindex[] = {                      -216,
    0,    0,    0,    0,    0, -262,    0, -266, -265,    0,
 -253, -216, -216, -284,    0, -282, -213,    0,    0, -216,
    0, -276, -226,    0,    0, -216,    0, -261,    0, -220,
 -217, -207, -199, -192, -184, -201, -200, -274, -198,    0,
    0,    0, -247, -158,    0, -216, -196, -268, -194, -268,
    0,    0,    0,    0, -255, -253, -220, -160,    0, -193,
    0, -210, -182, -268,    0,    0, -225, -157, -155, -154,
 -255, -114, -148,    0,    0, -144,    0, -183, -145, -222,
 -222, -222, -222, -222, -222, -226, -142, -226,  -98, -143,
    0, -222, -222, -222, -222, -222, -222, -222, -222, -222,
    0,    0, -226, -137,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -123,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -216, -268, -186, -226,    0,
 -129, -170, -167,    0,    0, -270, -166,    0, -113, -263,
 -130,    0, -156,    0, -226, -156, -108,    0,    0, -186,
    0,    0,
};
static const YYINT yyrindex[] = {                       162,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -106,  162, -195,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  165,    0,    0,    0, -107,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -195,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -244, -107,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -197,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -228,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  165,    0, -105,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -104,    0,    0, -249,    0,    0,    0, -105,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    1,  132,   53,  101,  163,    0,  131,  -23,    0,   52,
    0,  -38,    0,  124,    0,    0,    0,  -46,   46,    0,
    0,   34,    0,    0,   39,
};
#define YYTABLESIZE 207
static const YYINT yytable[] = {                         26,
    6,   57,   12,   70,   53,    9,   64,   54,   36,   13,
   38,   37,    6,   16,   38,   53,   14,   79,   54,   71,
   22,   59,   55,   38,   67,   18,   28,   19,   27,   27,
   27,   27,   27,   24,   27,   27,   32,   33,   34,  140,
   35,   65,   66,   27,   27,   25,   16,   10,   31,   60,
   27,   25,   67,   27,   65,   66,   20,   46,   36,   20,
   21,   37,  112,   77,  115,   80,   81,   47,   82,   83,
   84,   52,   85,  132,   11,   48,   52,  133,   11,  126,
  131,   27,   49,   27,   27,   27,   27,   65,   66,   38,
   50,    1,    2,    3,    4,    1,    2,    3,    4,  143,
   32,   33,   34,  146,   35,  135,  147,   72,   51,   52,
   61,   10,   75,   63,   78,   69,   86,   76,   87,   88,
  101,  149,   36,   89,  102,   37,   28,  104,  105,  113,
  116,  127,  106,  107,  108,  109,  110,  111,  129,  136,
  137,  138,  142,  145,  117,  118,  119,  120,  121,  122,
  123,  124,  125,   38,   91,    1,    2,    3,    4,  144,
  151,    5,   66,   92,    8,   20,   93,   36,   38,   94,
   56,   90,   95,   96,   15,   97,   62,  130,   98,   92,
   74,  141,   93,  152,  150,   94,   99,    0,   95,   96,
  100,   97,    0,    0,   98,    0,    0,    0,    0,    0,
    0,    0,   99,    0,    0,    0,  100,
};
static const YYINT yycheck[] = {                         23,
    0,   40,  269,   50,  279,  268,  275,  282,  279,  275,
  260,  282,   12,   13,  264,  279,  270,   64,  282,  275,
   20,  269,  297,  273,  269,  310,   26,  310,  257,  258,
  259,  260,  261,  310,  263,  264,  257,  258,  259,  310,
  261,  310,  311,  272,  273,  272,   46,  310,  310,  297,
  279,  272,  297,  282,  310,  311,  270,  275,  279,  270,
  274,  282,   86,  274,   88,  291,  292,  275,  294,  295,
  296,  269,  298,  260,  270,  275,  274,  264,  274,  103,
  127,  310,  275,  312,  313,  314,  315,  310,  311,  310,
  275,  312,  313,  314,  315,  312,  313,  314,  315,  138,
  257,  258,  259,  142,  261,  129,  263,   55,  310,  310,
  269,  310,  273,  310,  297,  310,  274,  311,  274,  274,
  269,  145,  279,   71,  269,  282,  126,  311,  274,  272,
  274,  269,   80,   81,   82,   83,   84,   85,  262,  269,
  311,  309,  309,  274,   92,   93,   94,   95,   96,   97,
   98,   99,  100,  310,  269,  312,  313,  314,  315,  273,
  269,    0,  269,  278,    0,  273,  281,  273,  273,  284,
   39,   71,  287,  288,   12,  290,   46,  126,  293,  278,
   57,  136,  281,  150,  146,  284,  301,   -1,  287,  288,
  305,  290,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  301,   -1,   -1,   -1,  305,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 315
#define YYUNDFTOKEN 343
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"FOR_TOK","WHILE_TOK",
"SWITCH_TOK","CASE_TOK","IF_TOK","ELSE_TOK","BREAK_TOK","DEFAULT_TOK",
"RETURN_TOK","INCLUDE_TOK","DEFINE_TOK","MAIN_TOK","SEMICOLON_TOK","COMMA_TOK",
"DOT_TOK","LCURLY_TOK","RCURLY_TOK","RPAREN_TOK","LPAREN_TOK",
"ARRAY_BRACKET_LTOK","ARRAY_BRACKET_RTOK","ADDITION_TOK","INCREMENT_TOK",
"ADDITION_EQUAL_TOK","MINUS_TOK","DECREMENT_TOK","MINUS_EQUAL_TOK",
"MULTIPLICATION_TOK","MULTIPLICATION_EQUAL_TOK","DIVISION_EQUAL_TOK",
"DIVISION_TOK","MODULO_TOK","MODULO_EQUAL_TOK","RIGHT_SHIFT_TOK",
"GREATER_THAN_EQUAL_TOK","GREATER_TOK","LEFT_SHIFT_TOK","LESS_THAN_EQUAL_TOK",
"LESS_TOK","EQUAL_COMPARE_TOK","EQUAL_TOK","NOT_EQUAL_TOK","NOT_TOK",
"BIT_OR_EQUAL_TOK","BIT_OR_TOK","OR_TOK","AND_TOK","BIT_AND_EQUAL_TOK",
"BIT_AND_TOK","XOR_TOK","XOR_EQUAL_TOK","SPACE_TOK","COLON_TOK","ID_TOK",
"INT_CONST_TOK","INTEGER_TOK","FLOATING_TOK","DOUBLE_TOK","CHAR_TOK",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programe",
"programe : function",
"function : global_declaration_statement SEMICOLON_TOK function",
"$$1 :",
"function : data_type MAIN_TOK LPAREN_TOK func_args RPAREN_TOK $$1 statement_block function_declr",
"function :",
"$$2 :",
"function_declr : data_type ID_TOK LPAREN_TOK func_args RPAREN_TOK $$2 statement_block function_declr",
"function_declr :",
"func_args : func_args COMMA_TOK data_type ID_TOK",
"func_args : data_type ID_TOK",
"func_args :",
"data_type : INTEGER_TOK",
"data_type : FLOATING_TOK",
"data_type : DOUBLE_TOK",
"data_type : CHAR_TOK",
"$$3 :",
"$$4 :",
"statement_block : LCURLY_TOK $$3 statement nested_blocks $$4 RCURLY_TOK",
"nested_blocks : statement_block statement nested_blocks",
"nested_blocks :",
"statement : statement actual_statement",
"statement :",
"actual_statement : declaration_statement SEMICOLON_TOK",
"actual_statement : WHILE_TOK LPAREN_TOK relational_expression RPAREN_TOK statement_block",
"actual_statement : FOR_TOK LPAREN_TOK ID_TOK EQUAL_TOK INT_CONST_TOK SEMICOLON_TOK relational_expression SEMICOLON_TOK unary_expression RPAREN_TOK statement_block",
"actual_statement : IF_TOK LPAREN_TOK relational_expression RPAREN_TOK statement_block ELSE_TOK statement_block",
"actual_statement : IF_TOK LPAREN_TOK relational_expression RPAREN_TOK statement_block",
"actual_statement : SWITCH_TOK LPAREN_TOK ID_TOK RPAREN_TOK switch_block",
"actual_statement : assignment_expression",
"actual_statement : unary_expression SEMICOLON_TOK",
"$$5 :",
"$$6 :",
"switch_block : LCURLY_TOK $$5 case_blocks $$6 RCURLY_TOK",
"case_blocks : CASE_TOK INT_CONST_TOK COLON_TOK statement optional_break case_blocks",
"case_blocks : DEFAULT_TOK COLON_TOK statement optional_break",
"case_blocks :",
"optional_break : BREAK_TOK SEMICOLON_TOK",
"optional_break :",
"assignment_expression : ID_TOK EQUAL_TOK arith_expression SEMICOLON_TOK",
"assignment_expression : declaration_statement EQUAL_TOK INT_CONST_TOK SEMICOLON_TOK",
"assignment_expression : ID_TOK EQUAL_TOK operand SEMICOLON_TOK",
"arith_expression : operand ADDITION_TOK operand",
"arith_expression : operand MINUS_TOK operand",
"arith_expression : operand MULTIPLICATION_TOK operand",
"arith_expression : operand DIVISION_TOK operand",
"arith_expression : operand MODULO_TOK operand",
"arith_expression : operand RIGHT_SHIFT_TOK operand",
"arith_expression : operand LEFT_SHIFT_TOK operand",
"arith_expression : operand BIT_OR_TOK operand",
"arith_expression : operand BIT_AND_TOK operand",
"arith_expression : LPAREN_TOK arith_expression RPAREN_TOK",
"relational_expression : operand",
"relational_expression : operand GREATER_THAN_EQUAL_TOK operand",
"relational_expression : operand GREATER_TOK operand",
"relational_expression : operand LESS_THAN_EQUAL_TOK operand",
"relational_expression : operand LESS_TOK operand",
"relational_expression : operand EQUAL_COMPARE_TOK operand",
"relational_expression : operand NOT_EQUAL_TOK operand",
"relational_expression : LPAREN_TOK relational_expression RPAREN_TOK",
"unary_expression : ID_TOK INCREMENT_TOK",
"unary_expression : ID_TOK DECREMENT_TOK",
"unary_expression : INCREMENT_TOK ID_TOK",
"unary_expression : DECREMENT_TOK ID_TOK",
"operand : ID_TOK",
"operand : INT_CONST_TOK",
"global_declaration_statement : data_type inline_declaration",
"declaration_statement : data_type inline_declaration",
"inline_declaration : inline_declaration COMMA_TOK ID_TOK",
"inline_declaration : ID_TOK",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 312 "symbY.y"

int main(int argc,const char* argv[]){
	init_symbol_table();
	yyin = fopen(argv[1],"r");
	yyparse();
	return 0;
}
void success(void){
	for(int i=0;i <= function_index;i++){
		display_table(i);
	}
	printf("\n\n\t\t\tSUCCESSFULLY PARSED :)\n");
}
void yyerror(char *s){
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,s);
	for(int i=0;i <= function_index;i++){
		display_table(i);
	}
	exit(1);
}
void init_symbol_table(void){
	for(int table_index = 0;table_index <= MAX_FUNCTION;table_index++){
		for(int i=0;i <= 122;i++){
			symbol_table[table_index][i].entry_index = -1;
		}
	}
	if(DEBUG_INFO){
		printf("Symbol table initialised with NULL\n");
		printf("Each node size of Symbol table is: %ld\n",sizeof(symbol_table[function_index][0]));
	}
}
void insert_by_name(char *name){

	int index = name[0];
	temp_table[index].entry_index = index;
	temp_table[index].var_name = name[0];
	memset((void*)temp_table[index].type,-1,sizeof(int)*10);
	temp_table[index].scope[0] = global_scope;
	temp_table[index].line_no[0] = yylineno;
	temp_table[index].scope_array_index = 0;
}
void assign_type(int t,int flag){
	if(DEBUG_INFO){
		printf("Current scope in assign_type is: %d in line_no: %d\n",global_scope,yylineno);
	}
	struct entry node;
	for(int i = 0;i < var_buffer_index;i++){
		if(var_buffer[i] >= 0){
			node = symbol_table[function_index][var_buffer[i]];
			if(node.var_name == temp_table[var_buffer[i]].var_name){
				if(check_for_same_scope(node,temp_table[var_buffer[i]])){
					yyerror("Variable having same name with same scope");
				}
				else{
					int element = var_buffer[i];
					symbol_table[function_index][element].entry_index = element;
					symbol_table[function_index][element].var_name = temp_table[element].var_name;
					symbol_table[function_index][element].scope[symbol_table[function_index][element].scope_array_index] = global_scope;
					symbol_table[function_index][element].type[global_scope] = t;
					symbol_table[function_index][element].line_no[global_scope] = yylineno;
					symbol_table[function_index][element].scope_array_index++;
					if(flag == 0 && symbol_table[function_index][element].global_flag != 1){
						symbol_table[function_index][element].global_flag = 0;
					}
					else{
						symbol_table[function_index][element].global_flag = 1;
					}
				}
			}
			else{
					int element = var_buffer[i];
					symbol_table[function_index][element].entry_index = element;
					symbol_table[function_index][element].var_name = temp_table[element].var_name;
					symbol_table[function_index][element].scope[symbol_table[function_index][element].scope_array_index] = global_scope;
					symbol_table[function_index][element].type[global_scope] = t;
					symbol_table[function_index][element].line_no[global_scope] = yylineno;
					symbol_table[function_index][element].scope_array_index++;
					if(flag == 0 && symbol_table[function_index][element].global_flag != 1){
						symbol_table[function_index][element].global_flag = 0;
					}
					else{
						symbol_table[function_index][element].global_flag = 1;
					}
			}
		}
		var_buffer[i] = -1;
	}
}
int check_for_same_scope(struct entry node1,struct entry node2){
	if(DEBUG_INFO){
		printf("Current scope in check_for_same_scope is:  %d in line_no: %d\n",global_scope,yylineno);
	}
	if (node1.entry_index == -1){
		return 0;
	}
	else{
		int target_scope = node2.scope[0];
		for(int i = 0;i < node1.scope_array_index;i++){
			if(node1.scope[i] == target_scope){
				return 1;
			}
		}
		return 0;
	}
}
void display_table(int table_index){
	char *decision = NULL;
	printf("\t\t\t%dth %s\n\n",table_index,"SYMBOL TABLE BUILT SO FAR");
	printf("----------------------------------------------------------------------------------------------------\n");
	for(int i=0;i <= 122;i++){
		if(symbol_table[table_index][i].entry_index != -1){
			for(int j=0;j < symbol_table[table_index][i].scope_array_index;j++){
				switch(symbol_table[table_index][i].type[symbol_table[table_index][i].scope[j]]){
					case 0:
						decision = (char*)malloc(sizeof(char) * 12);
						strncpy(decision,(char*)"Invalidated",11);
						break;
					case 1:
						decision = (char*)malloc(sizeof(char) * 4);
						strncpy(decision,(char*)"Int",3);
						break;
					case 2:
						decision = (char*)malloc(sizeof(char) * 5);
						strncpy(decision,(char*)"Float",4);
						break;
					case 3:
						decision = (char*)malloc(sizeof(char) * 6);
						strncpy(decision,(char*)"Double",5);
						break;
					case 4:
						decision = (char*)malloc(sizeof(char) * 5);
						strncpy(decision,(char*)"Char",4);
						break;

				}
				printf("| index: %d name: %c total_of_scope_used: %d type = %s in the scope %d line_no: %d global_flag: %d\t   |\n",symbol_table[table_index][i].entry_index,symbol_table[table_index][i].var_name,symbol_table[table_index][i].scope_array_index,decision,symbol_table[table_index][i].scope[j],symbol_table[table_index][i].line_no[symbol_table[table_index][i].scope[j]],symbol_table[table_index][i].global_flag);
				free(decision);
			}
			printf("----------------------------------------------------------------------------------------------------\n");
		}
	}
}
void check_scope_declaration(char *name,int Scope){
	if(DEBUG_INFO){
		printf("Current scope in check_scope_declaration for %s is:  %d in line no: %d\n",name,global_scope,yylineno);
	}
	if(found(name)){
		if (is_number(name) || symbol_table[function_index][name[0]].type[Scope] != 0){
			return;
		}
		else{
			for(int i = 0; i < Scope ; i++){
				if(symbol_table[function_index][name[0]].type[i] != 0){
					return;
				}
			}
			yyerror("Un-declared till now");
		}
		yyerror("Un-declared till now");
	}
	yyerror("Un-declared till now");
}
int found(char *name){
	return symbol_table[function_index][name[0]].entry_index != -1  || strlen(name) > 1 || is_number(name);
}
int  check_type(char *name1,char *name2){
	if(DEBUG_INFO){
		printf("Current scope in check_type for %s %s is: %d in line_no: %d\n",name1,name2,global_scope,yylineno);
	}
	if (strlen(name1) == 1 && strlen(name2) == 1 && !is_number(name2)){
		for(int i = 0; i < symbol_table[function_index][name1[0]].scope_array_index;i++){
			for(int j = 0; j < symbol_table[function_index][name2[0]].scope_array_index;j++){
				if (symbol_table[function_index][name1[0]].type[symbol_table[function_index][name1[0]].scope[i]] == symbol_table[function_index][name2[0]].type[symbol_table[function_index][name2[0]].scope[j]] && symbol_table[function_index][name1[0]].type[symbol_table[function_index][name1[0]].scope[i]] != 0 )
					return symbol_table[function_index][name1[0]].type[symbol_table[function_index][(int)name1[0]].scope[i]];
			}
		}
		printf("%s === %s\n",name1,name2);
		yyerror("Mismatched Type");
	}
	else if(strlen(name1) == 1){
		if (is_number(name2)){
			for(int i = 0;i < symbol_table[function_index][name1[0]].scope_array_index;i++){
				if(symbol_table[function_index][name1[0]].type[symbol_table[function_index][name1[0]].scope[i]] == 1){
					return 1;
				}
			}
			yyerror("Integer type not found");
		}
		yyerror("String is not allowed");
	}
	else if(strlen(name2) == 1){
		if(is_number(name1)){
			for(int i = 0;i < symbol_table[function_index][name2[0]].scope_array_index;i++){
				if(symbol_table[function_index][name2[0]].type[symbol_table[function_index][name2[0]].scope[i]] == 1){
					return 1;
				}
			}
			yyerror("Integer type not found");
		}
		yyerror("String is not allowed");
	}
	else{
		if(is_number(name1) && is_number(name2)){
			return 1;
		}
		yyerror("Un recognised type of two variables");
	}
}
void check_type_assign(char *name,int type,int scope){
	if(DEBUG_INFO){
		printf("Current scope in check_type_assign is: %d in lineno: %d\n",global_scope,yylineno);
	}
	for(int i = 0;i < symbol_table[function_index][name[0]].scope_array_index;i++){
		if(symbol_table[function_index][name[0]].type[symbol_table[function_index][name[0]].scope[i]] == type){
			return;
		}
	}
	yyerror("Mismatched type of LHS and RHS");
}
int is_number(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 0) return 0;
    }
    return 1;
}
void invalidate_scope_var(int target_scope){
	if(DEBUG_INFO){
		printf("invalidated target scope: %d\n",target_scope);
	}
	char *str;
	for(int i = 0;i < 122;i++){
		symbol_table[function_index][i].type[target_scope] = 0;
	}
	if(DEBUG_INFO){
		printf("After invalidating .... \n");
	}
	if(DEBUG_INFO){
		for(int i = 0;i <= function_index;i++){
			display_table(i);
		}
	}
}
#line 694 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 80 "symbY.y"
	{success();}
break;
case 3:
#line 85 "symbY.y"
	{
		function_index++;
		if(DEBUG_INFO){
			printf("%dth Main Function has been found in line no: %d\n",function_index,yylineno);
		}
	}
break;
case 6:
#line 95 "symbY.y"
	{
		function_index++;
		if(DEBUG_INFO){
			printf("%dth User Defined Function has been found in line no: %d\n",function_index,yylineno);
		}
	}
break;
case 12:
#line 111 "symbY.y"
	{yyval.t.i_type = 1;}
break;
case 13:
#line 112 "symbY.y"
	{yyval.t.i_type = 2; }
break;
case 14:
#line 113 "symbY.y"
	{yyval.t.i_type = 3; }
break;
case 15:
#line 114 "symbY.y"
	{yyval.t.i_type = 4; }
break;
case 16:
#line 118 "symbY.y"
	{
		global_scope += 1;
	}
break;
case 17:
#line 120 "symbY.y"
	{
		invalidate_scope_var(global_scope);
		global_scope -= 1;
	}
break;
case 28:
#line 142 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
	}
break;
case 31:
#line 149 "symbY.y"
	{
		global_scope += 1;
	}
break;
case 32:
#line 151 "symbY.y"
	{
		global_scope -= 1;
	}
break;
case 39:
#line 165 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-3].n.name,global_scope);
		check_type_assign(yystack.l_mark[-3].n.name,yystack.l_mark[-1].p.i_type,global_scope);

	}
break;
case 40:
#line 170 "symbY.y"
	{
		if(DEBUG_INFO){
			printf("Declaration statement is correctly parsed at line no %d\n",yylineno);
		}
	}
break;
case 41:
#line 175 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-3].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[-1].n.name,global_scope);
		check_type(yystack.l_mark[-3].n.name,yystack.l_mark[-1].n.name);
	}
break;
case 42:
#line 183 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.p.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 43:
#line 188 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.p.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 44:
#line 193 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.p.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 45:
#line 198 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.p.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 46:
#line 203 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.p.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 47:
#line 208 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.p.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 48:
#line 213 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.p.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 49:
#line 218 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.p.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 50:
#line 223 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.p.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 51:
#line 228 "symbY.y"
	{}
break;
case 52:
#line 232 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression having only operand has been found in line no: %d\n",yylineno);
		}
	}
break;
case 53:
#line 238 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}  	
	}
break;
case 54:
#line 244 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}			
	}
break;
case 55:
#line 250 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}		
	}
break;
case 56:
#line 256 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}				
	}
break;
case 57:
#line 262 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}			
	}
break;
case 58:
#line 268 "symbY.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}			
	}
break;
case 60:
#line 278 "symbY.y"
	{check_scope_declaration(yystack.l_mark[-1].n.name,global_scope);}
break;
case 61:
#line 279 "symbY.y"
	{check_scope_declaration(yystack.l_mark[-1].n.name,global_scope);}
break;
case 62:
#line 280 "symbY.y"
	{check_scope_declaration(yystack.l_mark[0].n.name,global_scope);}
break;
case 63:
#line 281 "symbY.y"
	{check_scope_declaration(yystack.l_mark[0].n.name,global_scope);}
break;
case 64:
#line 285 "symbY.y"
	{}
break;
case 65:
#line 286 "symbY.y"
	{}
break;
case 66:
#line 290 "symbY.y"
	{
		assign_type(yystack.l_mark[-1].t.i_type,1);
	}
break;
case 67:
#line 296 "symbY.y"
	{
		assign_type(yystack.l_mark[-1].t.i_type,0);
	}
break;
case 68:
#line 302 "symbY.y"
	{
		insert_by_name(yystack.l_mark[0].n.name);
		var_buffer[var_buffer_index++] = yystack.l_mark[0].n.name[0];
	}
break;
case 69:
#line 306 "symbY.y"
	{
		insert_by_name(yystack.l_mark[0].n.name);
		var_buffer[var_buffer_index++] = yystack.l_mark[0].n.name[0];
	}
break;
#line 1178 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
