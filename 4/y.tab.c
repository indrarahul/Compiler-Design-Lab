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

#line 2 "syn1.y"
 
   /* Definition section */
   #include<stdio.h> 
   #include<stdlib.h> 
   #include "lex.yy.c"
#line 27 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

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

#define MAIN_TOK 257
#define LPAREN_TOK 258
#define RPAREN_TOK 259
#define LCURLY_TOK 260
#define RCURLY_TOK 261
#define INT_TOK 262
#define VOID_TOK 263
#define FLOAT_TOK 264
#define CHAR_TOK 265
#define ID_TOK 266
#define SEMICOLON_TOK 267
#define COMMA_TOK 268
#define NUM_TOK 269
#define EQUAL_TOK 270
#define ADD_TOK 271
#define SUB_TOK 272
#define MUL_TOK 273
#define DIV_TOK 274
#define NOT_TOK 275
#define LESS_EQUAL_TO_TOK 276
#define NOT_EQUAL_TO_TOK 277
#define EQUAL_TO_TOK 278
#define GREATER_EQUAL_TO_TOK 279
#define GREATER_TOK 280
#define LESS_TOK 281
#define AND_TOK 282
#define OR_TOK 283
#define IF_TOK 284
#define WHILE_TOK 285
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    4,    4,    1,    1,    5,    6,    6,    7,    8,
    8,    3,    9,    9,    9,   10,   10,   10,   10,   10,
   10,   11,   12,   13,   17,   17,    2,    2,    2,    2,
   16,   19,   19,   20,   20,   18,   22,   22,   23,   23,
   21,   21,   21,   14,   25,   25,   24,   26,   26,   26,
   26,   26,   26,   15,   27,   27,
};
static const YYINT yylen[] = {                            2,
    7,    2,    0,    2,    0,    4,    2,    3,    3,    2,
    0,    3,    2,    2,    0,    1,    1,    1,    1,    1,
    1,    3,    2,    4,    2,    1,    1,    1,    1,    1,
    2,    2,    0,    2,    2,    2,    2,    0,    2,    2,
    1,    1,    3,    5,    1,    1,    3,    1,    1,    1,
    1,    1,    1,    5,    1,    1,
};
static const YYINT yydefred[] = {                         5,
    0,    0,   27,   28,   29,   30,    0,    4,    0,    0,
    0,    0,    0,    0,    0,    6,    0,    0,    0,    7,
    0,    0,    0,   21,    0,    0,    0,    0,    0,    0,
   16,   17,   18,   19,   20,    0,    1,    0,    0,    9,
    8,    0,    0,    0,    0,   23,   14,   12,   13,    2,
   10,    0,   41,   42,    0,    0,    0,    0,    0,    0,
   22,    0,   26,    0,   24,    0,    0,   31,    0,    0,
    0,   36,    0,   51,   49,   48,   50,   52,   53,    0,
    0,    0,   43,   25,   34,   35,   32,   39,   40,   37,
   47,   46,   45,   44,   56,   55,   54,
};
static const YYINT yydgoto[] = {                          1,
    2,   27,   28,   37,   38,   16,   17,   40,   29,   30,
   31,   32,   33,   34,   35,   58,   65,   56,   68,   69,
   57,   72,   73,   59,   94,   80,   97,
};
static const YYINT yysindex[] = {                         0,
    0, -190,    0,    0,    0,    0, -253,    0, -255, -250,
 -248, -199, -227, -227, -231,    0, -222, -246, -190,    0,
 -218, -227, -211,    0, -191, -182, -205, -246, -170, -246,
    0,    0,    0,    0,    0, -174,    0, -190, -190,    0,
    0, -235, -235, -235, -260,    0,    0,    0,    0,    0,
    0, -235,    0,    0, -221, -220, -196, -252, -166, -165,
    0, -164,    0, -169,    0, -235, -235,    0, -220, -235,
 -235,    0, -196,    0,    0,    0,    0,    0,    0, -235,
 -246, -246,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -163,   96,    0,
 -160,    0,    0,    0,    0,    0,    0, -163,    0, -163,
    0,    0,    0,    0,    0,    0,    0,   96,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -197, -223,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -197,    0,
    0,    0, -223,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    3,  -13,   62,   99,    0,   63,    0,    2,    4,
    0,    0,  -21,    0,    0,  -40,    0,   21,   34,    0,
   19,   31,    0,   61,    0,    0,    0,
};
#define YYTABLESIZE 105
static const YYINT yytable[] = {                         19,
   20,   55,   11,    9,    7,   46,   61,   12,   41,   42,
   13,   62,   10,   18,   15,    3,    4,    5,    6,   23,
   24,   36,   52,   74,   75,   76,   77,   78,   79,   47,
   53,   49,   18,   54,   21,   38,   22,   25,   26,   91,
   36,   15,   84,   38,   38,   63,   64,   38,   38,   39,
   66,   67,   38,   38,   38,   38,   38,   38,   42,   14,
   45,   33,    3,    4,    5,    6,   43,   92,   95,   33,
   33,    3,    4,    5,    6,   44,   70,   71,   33,   33,
   33,   33,   33,   33,   93,   96,   85,   86,   88,   89,
   48,   10,   81,   82,   83,    3,   23,   15,   11,   50,
    8,   51,   87,   90,   60,
};
static const YYINT yycheck[] = {                         13,
   14,   42,  258,  257,    2,   27,  267,  258,   22,  270,
  259,   52,  266,  260,   12,  262,  263,  264,  265,  266,
  267,   19,  258,  276,  277,  278,  279,  280,  281,   28,
  266,   30,  260,  269,  266,  259,  259,  284,  285,   80,
   38,   39,   64,  267,  268,  267,  268,  271,  272,  268,
  271,  272,  276,  277,  278,  279,  280,  281,  270,  259,
  266,  259,  262,  263,  264,  265,  258,   81,   82,  267,
  268,  262,  263,  264,  265,  258,  273,  274,  276,  277,
  278,  279,  280,  281,   81,   82,   66,   67,   70,   71,
  261,  266,  259,  259,  259,    0,  266,  261,  259,   38,
    2,   39,   69,   73,   44,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 285
#define YYUNDFTOKEN 315
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"MAIN_TOK","LPAREN_TOK",
"RPAREN_TOK","LCURLY_TOK","RCURLY_TOK","INT_TOK","VOID_TOK","FLOAT_TOK",
"CHAR_TOK","ID_TOK","SEMICOLON_TOK","COMMA_TOK","NUM_TOK","EQUAL_TOK","ADD_TOK",
"SUB_TOK","MUL_TOK","DIV_TOK","NOT_TOK","LESS_EQUAL_TO_TOK","NOT_EQUAL_TO_TOK",
"EQUAL_TO_TOK","GREATER_EQUAL_TO_TOK","GREATER_TOK","LESS_TOK","AND_TOK",
"OR_TOK","IF_TOK","WHILE_TOK",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : S",
"S : f2 type MAIN_TOK LPAREN_TOK RPAREN_TOK block f1",
"f1 : func f1",
"f1 :",
"f2 : f2 func",
"f2 :",
"func : type ID_TOK LPAREN_TOK e1",
"e1 : RPAREN_TOK block",
"e1 : parameter RPAREN_TOK block",
"parameter : type ID_TOK e2",
"e2 : COMMA_TOK parameter",
"e2 :",
"block : LCURLY_TOK iblock RCURLY_TOK",
"iblock : stmt iblock",
"iblock : block iblock",
"iblock :",
"stmt : declaration",
"stmt : declaration_with_initialization",
"stmt : assignment",
"stmt : conditional",
"stmt : iterative",
"stmt : SEMICOLON_TOK",
"declaration : type ID_TOK SEMICOLON_TOK",
"declaration_with_initialization : type assignment",
"assignment : ID_TOK EQUAL_TOK expr b1",
"b1 : COMMA_TOK assignment",
"b1 : SEMICOLON_TOK",
"type : INT_TOK",
"type : VOID_TOK",
"type : FLOAT_TOK",
"type : CHAR_TOK",
"expr : term expr_",
"expr_ : a1 expr_",
"expr_ :",
"a1 : ADD_TOK term",
"a1 : SUB_TOK term",
"term : factor term_",
"term_ : a2 term_",
"term_ :",
"a2 : MUL_TOK factor",
"a2 : DIV_TOK factor",
"factor : ID_TOK",
"factor : NUM_TOK",
"factor : LPAREN_TOK expr RPAREN_TOK",
"conditional : IF_TOK LPAREN_TOK condition RPAREN_TOK c1",
"c1 : stmt",
"c1 : block",
"condition : expr c2 expr",
"c2 : EQUAL_TO_TOK",
"c2 : NOT_EQUAL_TO_TOK",
"c2 : GREATER_EQUAL_TO_TOK",
"c2 : LESS_EQUAL_TO_TOK",
"c2 : GREATER_TOK",
"c2 : LESS_TOK",
"iterative : WHILE_TOK LPAREN_TOK condition RPAREN_TOK d1",
"d1 : stmt",
"d1 : block",

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
#line 71 "syn1.y"
 
  
int yyerror(char *msg) 
 { 
  printf("invalid string\n"); 
  exit(0); 
 } 

extern FILE* yyin;  
//driver code  
int main(int argc, char* argv[])
{
    int val;
   
    if(yyparse()==0)
    printf("SuccessFul\n");
    else
    printf("Error in line: %d",yylineno);
    return(0);
}
#line 326 "y.tab.c"

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
#line 15 "syn1.y"
	{printf("Correct Syntax\n");}
break;
case 6:
#line 21 "syn1.y"
	{printf("Function defined");}
break;
case 12:
#line 29 "syn1.y"
	{printf("block detected\n");}
break;
case 18:
#line 33 "syn1.y"
	{printf("valid assignment\n");}
break;
case 22:
#line 35 "syn1.y"
	{printf("valid declaration\n");}
break;
case 23:
#line 37 "syn1.y"
	{printf("valid declaration with initialization\n");}
break;
case 44:
#line 59 "syn1.y"
	{printf("Conditional statement\n");}
break;
case 54:
#line 67 "syn1.y"
	{printf("Iterative statement\n");}
break;
#line 560 "y.tab.c"
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
