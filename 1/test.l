%{
#include<stdio.h>
#include<stdlib.h>
#include "tokendef_LEX.h"
%}

%%
;                                {return(SEMICOLON_TOK);}
,                                {return COMMA_TOK;        }
\{                               {return(LCRLY_TOK);}
\}                               {return(RCRLY_TOK);}
\(				                 {return(LPAREN_TOK);}
\)				                 {return(RPAREN_TOK);}
\*                                {return(tk_Mul);}
\/                                {return(tk_Div);}
\%                                {return(tk_Mod);}
\+                                {return(tk_Add);}
\-                                {return(tk_Sub);}
\!                                {return(tk_Not);}
\<                                {return(tk_Lss);}
\<\=                               {return(tk_Leq);}
\>                                {return(tk_Gtr);}
\>\=                               {return(tk_Geq);}
\=\=                               {return(tk_Eq);}
\!\=                               {return(tk_Neq);}
\=                                {return(tk_Assign);} 
\&\&                               {return(tk_And);}
\|\|                               {return(tk_Or);}
\#                                {return(tk_Hash);} 
\.                                {return(tk_dot);}  
\[                                {return(tk_Lsqbr);} 
\]                                {return(tk_Rsqbr);}
\&                                {return(tk_BitwiseAnd);}
\|                                {return(tk_BitwiseOr);}
int                              {return(INT_TOK);}
main                             {return(MAIN_TOK);}
if                               {return(tk_If);}
else                             {return(tk_Else);} 
while                            {return(tk_While);}
printf                           {return(tk_Print);}
do                               {return(tk_do);}
putc                             {return(tk_Putc);} 
break                            {return(tk_break);}
continue                         {return(tk_Continue);}
float                            {return(tk_Float);}
double                           {return(tk_Double);} 
return                           {return(tk_return);}
char                             {return(tk_Char);}
case                             {return(tk_Case);} 
sizeof                           {return(tk_Sizeof);}
long                             {return(tk_Long);}
short                            {return(tk_Short);}
typedef                          {return(tk_Typedef);}
switch                           {return(tk_Switch);}
unsigned                         {return(tk_Unsigned);}
void                             {return(tk_Void);}
static                           {return(tk_static);}
struct                           {return(tk_struct);}
goto                             {return(tk_goto);}
([a-z]|[A-Z])([a-z]|[A-Z]|[0-9])* {return (ID_TOK);}
([0-9])([0-9])*                  {return(tk_Integer);}
([a-z]|[A-Z]|[0-9])([a-z]|[A-Z]|[0-9])* {return(tk_String);}

%%


int main(int argc, char *argv[])
{
    int val;
    if(argc < 3)
        exit(0);
    yyin = fopen(argv[1],"r");
    yyout = fopen(argv[2],"wb");
    while((val = yylex()) > 0)
    {
        fprintf(yyout,"Token === %s --> Token ID ====%d\n", yytext, val);
        
    }
    
    return(0);
}
 
