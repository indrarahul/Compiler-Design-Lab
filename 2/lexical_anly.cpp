#include <bits/stdc++.h>
#include <string.h>
#include <stdlib.h>
#include<map>


/**single character lexemes**/
#define LPAREN_TOK '('
#define RPAREN_TOK ')'
#define LCURL_TOK '{'
#define RCURL_TOK '}'
#define LBRAC '['
#define RBRAC ']'
#define COLON ':'
#define PLUS_TOK '+'
#define MINUS_TOK '-'
#define MULT_TOK '*'
#define DIVIDE_TOK '/'
#define SLASH '\\'
#define MOD_TOK '%'
#define ASSIGNMENT_TOK '='
#define SEMICOLON_TOK ';'
#define NOT_TOK '!' 
#define COMMA_TOK ','
#define LESS_THAN_TOK '<' 
#define MORE_THAN_TOK '>' 

/**after ascii**/
#define EQUALITY_TOK 256           /** == **/
#define NOT_EQUAL_TOK 257         /** != **/
#define LESS_THAN_EQUAL_TO_TOK 258 /** <= **/
#define MORE_THAN_EQUAL_TO_TOK 258 /** >= **/
#define INCR_TOK 259               /** ++ **/
#define DECR_TOK 260               /** -- **/
#define LOG_AND_TOK 261            /** && **/
#define LOG_OR_TOK 263             /** || **/

/**Reserved Key words**/
#define FOR_TOK 264    /** for **/
#define SWITCH_TOK 265 /** switch **/
#define CASE_TOK 266   /** case **/
#define IF_TOK 267     /** if **/
#define ELSE_TOK 268   /** else **/
#define WHILE_TOK 269  /** while **/
#define TYPE_TOK 270
/** Others **/
#define ID_TOK 271        /** identifier names **/
#define INT_CONST_TOK 272 /** integer constant **/
#define STRING_TOK 273

using namespace std;
FILE *yyin;
char *yytext; /** The last token scanned **/
int yylen;    /**length of yytext **/

map<string, int> keywords;

bool is_alphan(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

void store_keywords()
{
    keywords["for"] = FOR_TOK;
    keywords["while"] = WHILE_TOK;
    keywords["if"] = IF_TOK;
    keywords["else"] = ELSE_TOK;
    keywords["switch"] = SWITCH_TOK;
    keywords["case"] = CASE_TOK;
    keywords["int"] = TYPE_TOK;
    keywords["double"] = TYPE_TOK;
    keywords["float"] = TYPE_TOK;
    keywords["char"] = TYPE_TOK;
}

int yylex()
{
    char c;
    while (true)
    {
        //skipping spaces and newlines
        c = fgetc(yyin);
        if (c == EOF)
        {
            yylen = 0;
            yytext[0] = '\0';
            return -1;
        }
        if (c != ' ' && c != '\n')
            break;
    }

    string tmp = "";
    //now identification of the token starts
    switch (c)
    {
    case '{':
        return LCURL_TOK;
    case '}':
        return RCURL_TOK;
    case '(':
        return LPAREN_TOK;
    case ')':
        return RPAREN_TOK;
    case ';':
        return SEMICOLON_TOK;
    case '[':
        return LBRAC;
    case ']':
        return RBRAC;
    case ':':
        return COLON;
    case '\'':
        return SLASH;
    case '!':
        yylen = 1;
        yytext[0] = c;
        yytext[1] = '\0';
        return c;

    case '|':
        c = fgetc(yyin);
        if (c == '|')
        {
            yylen = 2;
            strcpy(yytext, "||");
            return LOG_OR_TOK;
        }
        else
        {
            yylen = 1;
            strcpy(yytext, "|");
            fseek(yyin, -1, SEEK_CUR);
            return c;
        }

    case '&':
        c = fgetc(yyin);
        if (c == '&')
        {
            yylen = 2;
            strcpy(yytext, "&&");
            return LOG_AND_TOK;
        }
        else
        {
            yylen = 1;
            strcpy(yytext, "&");
            fseek(yyin, -1, SEEK_CUR);
            return c;
        }
    case '<':
        c = fgetc(yyin);
        if (c == '=')
        {
            strcpy(yytext, "<=");
            yylen = 2;
            return LESS_THAN_EQUAL_TO_TOK;
        }
        else
        {
            fseek(yyin, -1, SEEK_CUR);
            yylen = 1;
            strcpy(yytext, "<");
            return LESS_THAN_TOK;
        }
    case '>':
        c = fgetc(yyin);
        if (c == '=')
        {
            strcpy(yytext, ">=");
            yylen = 2;
            return MORE_THAN_EQUAL_TO_TOK;
        }
        else
        {
            fseek(yyin, -1, SEEK_CUR);
            yylen = 1;
            strcpy(yytext, ">");
            return MORE_THAN_TOK;
        }
    case '=':
        c = fgetc(yyin);
        if (c == '=')
        {
            strcpy(yytext, "==");
            yylen = 2;
            return EQUALITY_TOK;
        }
        else
        {
            fseek(yyin, -1, SEEK_CUR);
            yylen = 1;
            strcpy(yytext, "=");
            return ASSIGNMENT_TOK;
        }
    case '+':
        c = fgetc(yyin);
        if (c == '=')
        {
            strcpy(yytext, "+=");
            yylen = 2;
            return ASSIGNMENT_TOK;
        }
        if (c == '+')
        {
            strcpy(yytext, "++");
            yylen = 2;
            return INCR_TOK;
        }
        else
        {
            fseek(yyin, -1, SEEK_CUR);
            yylen = 1;
            strcpy(yytext, "+");
            return PLUS_TOK;
        }
    case '-':
        c = fgetc(yyin);
        if (c == '=')
        {
            strcpy(yytext, "-=");
            yylen = 2;
            return ASSIGNMENT_TOK;
        }
        if (c == '-')
        {
            strcpy(yytext, "--");
            yylen = 2;
            return DECR_TOK;
        }
        if (c >= '0' && c <= '9')
        {
            tmp = "-";
            while (c >= '0' && c <= '9')
            {
                tmp += c;
                c = fgetc(yyin);
            }
            fseek(yyin, -1, SEEK_CUR);

            strcpy(yytext, tmp.c_str());
            yylen = tmp.size();

            return INT_CONST_TOK;            
        }
        else
        {
            fseek(yyin, -1, SEEK_CUR);
            yylen = 1;
            strcpy(yytext, "-");
            return MINUS_TOK;
        }

    case '*':
        c = fgetc(yyin);
        if (c == '=')
        {
            strcpy(yytext, "*=");
            yylen = 2;
            return ASSIGNMENT_TOK;
        }
        else
        {
            fseek(yyin, -1, SEEK_CUR);
            yylen = 1;
            strcpy(yytext, "*");
            return MULT_TOK;
        }

    case '/':
        c = fgetc(yyin);
        if (c == '=')
        {
            strcpy(yytext, "/=");
            yylen = 2;
            return ASSIGNMENT_TOK;
        }
        else
        {
            fseek(yyin, -1, SEEK_CUR);
            yylen = 1;
            strcpy(yytext, "/");
            return DIVIDE_TOK;
        }
    case '\"':
        c = fgetc(yyin);
        tmp="\"";
        while(c != '\"'){
            tmp += c;
            c = fgetc(yyin);
        }
        tmp +=c;
        strcpy(yytext, tmp.c_str());
        yylen = tmp.size();

        return STRING_TOK;
    default:
        if (c >= '0' && c <= '9')
        {
            

            while (c >= '0' && c <= '9')
            {
                tmp += c;
                c = fgetc(yyin);
            }
            fseek(yyin, -1, SEEK_CUR);

            strcpy(yytext, tmp.c_str());
            yylen = tmp.size();

            return INT_CONST_TOK;
        }
        else if (is_alphan(c) || (c == '_'))
        {
            
            tmp = "";
            while (is_alphan(c) || (c == '_'))
            {
                tmp += c;
                c = fgetc(yyin);
            }
            fseek(yyin, -1, SEEK_CUR);
            strcpy(yytext, tmp.c_str());
            yylen = tmp.size();

            
            map<string, int>::iterator it = keywords.find(tmp);
            if (it != keywords.end())
            {
               
                return keywords[tmp];
            }
            else
            {
                return ID_TOK;
            }
        }
        else
        {
            yylen = 1;
            yytext[0] = c;
            yytext[1] = '\0';
            yylen = 1;
            return -100;
        }
    }
   
}

int main(int argc, char **argv)
{
    store_keywords();
    if (argc != 2)
    {
        printf("Provide %s <file-name>\n", argv[0]);
        exit(1);
    }

    int token;
    yyin = fopen(argv[1], "r");
    yytext = new char[100];
    while (!feof(yyin))
    {
        token = yylex();
        if (token == -1)
        {
            printf("Reached end of file while parsing.\n");
            break;
        }
        printf("%s : %d\n",yytext, token);
    }
   
    fclose(yyin);
}


