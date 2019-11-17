
%{ 
   /* Definition section */
   #include<stdio.h> 
   #include<stdlib.h> 
   #include "lex.yy.c"
%} 
  
%token MAIN_TOK LPAREN_TOK RPAREN_TOK LCURLY_TOK RCURLY_TOK INT_TOK VOID_TOK FLOAT_TOK CHAR_TOK ID_TOK SEMICOLON_TOK COMMA_TOK NUM_TOK EQUAL_TOK ADD_TOK SUB_TOK MUL_TOK
       DIV_TOK NOT_TOK LESS_EQUAL_TO_TOK NOT_EQUAL_TO_TOK EQUAL_TO_TOK GREATER_EQUAL_TO_TOK GREATER_TOK LESS_TOK AND_TOK OR_TOK IF_TOK WHILE_TOK
  
%start S
/* Rule Section */
%%
S:f2 type MAIN_TOK LPAREN_TOK RPAREN_TOK block  f1 {printf("Correct Syntax\n");};

f1:func f1|;

f2:f2 func|;

func:type ID_TOK LPAREN_TOK e1   {printf("Function defined");};

e1:RPAREN_TOK block|parameter RPAREN_TOK block;

parameter:type ID_TOK e2;

e2:COMMA_TOK parameter|;

block:LCURLY_TOK iblock RCURLY_TOK                {printf("block detected\n");};

iblock:stmt iblock|block iblock|;

stmt:declaration|declaration_with_initialization|assignment {printf("valid assignment\n");}|conditional|iterative|SEMICOLON_TOK;

declaration:type ID_TOK SEMICOLON_TOK                                   {printf("valid declaration\n");};
 
declaration_with_initialization:type assignment{printf("valid declaration with initialization\n");};

assignment:ID_TOK EQUAL_TOK expr b1;

b1:COMMA_TOK assignment|SEMICOLON_TOK;

type:INT_TOK | VOID_TOK |FLOAT_TOK |CHAR_TOK;

expr: term expr_ ;

expr_:a1 expr_|;

a1: ADD_TOK term|SUB_TOK term ;

term: factor term_;

term_:a2 term_|;

a2: MUL_TOK factor|DIV_TOK factor;

factor: ID_TOK|NUM_TOK|LPAREN_TOK expr RPAREN_TOK; 

conditional: IF_TOK LPAREN_TOK condition RPAREN_TOK c1                  {printf("Conditional statement\n");};

c1:stmt|block;

condition:expr c2 expr;

c2:EQUAL_TO_TOK|NOT_EQUAL_TO_TOK|GREATER_EQUAL_TO_TOK|LESS_EQUAL_TO_TOK|GREATER_TOK|LESS_TOK;

iterative:WHILE_TOK LPAREN_TOK condition RPAREN_TOK d1                   {printf("Iterative statement\n");};

d1:stmt|block;

%% 
  
int yyerror(char *msg) 
 { 
  printf("invalid string\n"); 
  exit(0); 
 } 
 
//Main code  
int main(int argc, char* argv[])
{
    int val;
   
    if(yyparse()==0)
    printf("SuccessFul\n");
    else
    printf("Error in line: %d",yylineno);
    return(0);
}
