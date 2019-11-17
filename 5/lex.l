%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	extern int yylineno;
%}
letter [a-zA-Z_]
digit [0-9]
quote ["'"]
start ["/*"]
end ["*/"]
%%
"for" {return FOR_TOK;}
"while" {return WHILE_TOK;}
"switch" {return SWITCH_TOK;}
"case" {return CASE_TOK;}
"if" {return IF_TOK;}
"else" {return ELSE_TOK;}
"int" {return INTEGER_TOK;}
"float" {return FLOATING_TOK;}
"double" {return DOUBLE_TOK;}
"char" {return CHAR_TOK;}
"break" {return BREAK_TOK;}
"default" {return DEFAULT_TOK;}
"return" {return RETURN_TOK;}
"#include" {return INCLUDE_TOK;}
"#define" {return DEFINE_TOK;}
"main" {return MAIN_TOK;}
"//". {}
^"/*"[^*]*|[*]*"*/" {}
";" {return SEMICOLON_TOK;}
"," {return COMMA_TOK;}
"." {return DOT_TOK;}
"{" {return LCURLY_TOK;}
"}" {return RCURLY_TOK;}
"(" {return LPAREN_TOK;}
")" {return RPAREN_TOK;}
"[" {return ARRAY_BRACKET_LTOK;}
"]" {return ARRAY_BRACKET_RTOK;}
"++" {return  INCREMENT_TOK;}
"+=" {return ADDITION_EQUAL_TOK;}
"+" {return ADDITION_TOK;}
"--" {return DECREMENT_TOK;}
"-=" {return  MINUS_EQUAL_TOK;}
"-" {return MINUS_TOK;}
"*=" {return MULTIPLICATION_EQUAL_TOK;}
"*" { return MULTIPLICATION_TOK;}
"/=" {return DIVISION_EQUAL_TOK;}
"/" {return DIVISION_TOK;}
"%=" {return MODULO_EQUAL_TOK;}
"%" {return MODULO_TOK;}
">>" {return RIGHT_SHIFT_TOK;}
">=" {return GREATER_THAN_EQUAL_TOK;}
">" {return GREATER_TOK;}
"<<" {return LEFT_SHIFT_TOK;}
"<=" {return LESS_THAN_EQUAL_TOK;}
"<" {return LESS_TOK;}
"==" {return EQUAL_COMPARE_TOK;}
"=" {return EQUAL_TOK;}
"!=" {return NOT_EQUAL_TOK;}
"!" {return NOT_TOK;}
"||" {return OR_TOK;}
"|=" {return BIT_OR_EQUAL_TOK;}
"|" {return BIT_OR_TOK;}
"&&" {return AND_TOK;}
"&=" {return BIT_AND_EQUAL_TOK;}
"&" {return BIT_AND_TOK;}
"^" {return XOR_TOK;}
"^=" {return XOR_EQUAL_TOK;}
":" {return COLON_TOK;}
[\t" "]
[\n] {yylineno++;}
{letter}({letter}|{digit})* { 
	char *temp = strdup(yytext);
	yylval.n.name = (char*)malloc(sizeof(char)*yyleng);
	strncpy(yylval.n.name,temp,yyleng);
	temp = NULL;
	return ID_TOK;}
{digit}+ {
	char *temp = strdup(yytext);
	yylval.n.name = (char*)malloc(sizeof(char)*yyleng);
	yylval.n.i_val = (char*)malloc(sizeof(char)*yyleng);
	strncpy(yylval.n.name,temp,yyleng);
	strncpy(yylval.n.i_val,temp,yyleng);
	temp = NULL;
	return INT_CONST_TOK;}
{digit}+({letter}|{digit})* {;}
%%
int yywrap(){return 1;}
