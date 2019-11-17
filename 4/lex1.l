%{
#include<stdio.h>
#include "y.tab.h"

%}
%option noyywrap
digit     [0-9]

%%
[;]                                {return(SEMICOLON_TOK);}
[\{]                              {return(LCURLY_TOK);}
[\}]                               {return(RCURLY_TOK);}
[\(]                 {return(LPAREN_TOK);}
[\)]                 {return(RPAREN_TOK);}
int                              {return(INT_TOK);}
void                             {return(VOID_TOK);}
char                             {return(CHAR_TOK);}
float                            {return(FLOAT_TOK);}
main                             {return(MAIN_TOK);}
if                               {return(IF_TOK);};
while                            {return(WHILE_TOK);};
([a-z]|[A-Z])([a-z]|[A-Z]|[0-9])* {return (ID_TOK);}
[=]                               {return (EQUAL_TOK);}
[,]                               {return (COMMA_TOK);}
[+]                               {return (ADD_TOK);}
[-]                               {return (SUB_TOK);}
[*]                               {return (MUL_TOK);}
[/]                               {return (DIV_TOK);}
([0-9])([0-9])*                   {return (NUM_TOK);}
[>]                               {return (GREATER_TOK);};
[<]                               {return (LESS_TOK);};
[!]                               {return (NOT_TOK);};
"=="                              {return (EQUAL_TO_TOK);};
">="                              {return (GREATER_EQUAL_TO_TOK);};
"<="                              {return (LESS_EQUAL_TO_TOK);};
"!="                              {return (NOT_EQUAL_TO_TOK);};
[&&]                              {return (AND_TOK);};
[||]                              {return (OR_TOK);};
%%



