/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220114

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "parser.y"

    #include <stdio.h>
    #include "code.h"
    int yylex();
    int lineNo = 1;
    int in_if = 0;
    extern FILE* f_asm;
    int arg_cnt;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 11 "parser.y"
typedef union YYSTYPE {
  int intval;
  double dval;
  char* stringval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 46 "y.tab.c"

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

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INC 257
#define DEC 258
#define LESS_OR_EQUAL_THAN 259
#define GREATER_OR_EQUAL_THAN 260
#define SHIFT_LEFT 261
#define SHIFT_RIGHT 262
#define EQUAL 263
#define NOT_EQUAL 264
#define AND 265
#define OR 266
#define ADD 267
#define MINUS 268
#define MULTIPLY 269
#define DIVIDE 270
#define MOD 271
#define LOGICAL_NOT 272
#define BITWISE_NOT 273
#define LESS_THAN 274
#define GREATER_THAN 275
#define AND_OP 276
#define OR_OP 277
#define XOR_OP 278
#define ASSIGN 279
#define UMINUS 280
#define UADD 281
#define UMULTI 282
#define UANDOP 283
#define INCPOST 284
#define DECPOST 285
#define DIGITALWRITE 286
#define DELAY 287
#define DVALUE 288
#define IF 289
#define ELSE 290
#define SWITCH 291
#define CASE 292
#define DEFAULT 293
#define WHILE 294
#define DO 295
#define FOR 296
#define RETURN 297
#define BREAK 298
#define CONTINUE 299
#define SEMICOLON 300
#define COMMA 301
#define COLON 302
#define L_BRACKET 303
#define R_BRACKET 304
#define L_SQ_BRACKET 305
#define R_SQ_BRACKET 306
#define L_PARENTHESIS 307
#define R_PARENTHESIS 308
#define INT 309
#define CHAR 310
#define FLOAT 311
#define DOUBLE 312
#define VOID 313
#define SIGNED 314
#define UNSIGNED 315
#define LONG 316
#define SHORT 317
#define CONST 318
#define IDENTIFIER 319
#define CHAR_LITERAL 320
#define STRING_LITERAL 321
#define NL 322
#define INT_LITERAL 323
#define FLOAT_LITERAL 324
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   38,   38,   36,   36,   48,   37,   49,   37,   24,
   24,   24,   25,   25,   25,   25,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   47,   47,   47,   47,   27,
   34,   34,   33,   33,   32,   32,   29,   35,   35,   39,
   39,   40,   40,   41,   41,   30,   30,   31,   28,   42,
   42,   43,   43,   44,   44,   45,   45,   45,   45,   46,
   46,    2,    2,    2,    2,   10,   10,    3,    3,    3,
    9,    9,    9,    9,    8,    8,    8,    8,    7,    7,
    7,    6,    6,    6,    6,    6,    5,    5,    5,    4,
    4,    4,    1,   23,   23,   23,   23,   23,   23,   23,
   51,   50,   22,   21,   20,   20,   19,   19,   19,   18,
   17,   16,   15,   15,   14,   13,   13,   12,   12,   11,
   11,   11,   11,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    1,    0,    7,    0,    6,    1,
    1,    1,    1,    2,    1,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    1,    3,    1,    3,    1,    2,    3,    1,    3,    1,
    3,    1,    2,    3,    4,    1,    3,    2,    3,    1,
    3,    1,    3,    4,    4,    3,    5,    5,    3,    1,
    3,    1,    1,    3,    4,    1,    3,    1,    3,    4,
    1,    2,    2,    2,    1,    3,    3,    3,    1,    3,
    3,    1,    3,    3,    3,    3,    1,    3,    3,    1,
    3,    4,    1,    1,    1,    1,    1,    1,    1,    1,
    7,    5,    2,    1,    5,    7,    1,    1,    1,    5,
    7,    9,    1,    1,    2,    2,    3,    2,    3,    1,
    2,    1,    2,
};
static const YYINT yydefred[] = {                         0,
   17,   18,   19,   20,   21,   22,   23,   24,   25,    0,
    0,    4,    0,    0,   10,   11,   12,    2,    5,    0,
   16,    0,    0,    0,    0,    0,    0,    0,    0,   42,
    0,    0,    0,   14,    3,    0,   43,    0,    0,    0,
    0,   30,   37,    0,    0,   49,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   28,
   29,   26,   27,    0,   68,    0,   93,    0,    0,    0,
    0,   75,   63,   34,    0,   35,   32,    0,    0,   39,
   41,    0,   51,    0,   53,    0,   44,    0,    0,   48,
    0,    0,    0,    0,   72,    0,   73,   74,    0,    0,
    0,   54,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   36,   60,    0,    0,   55,   45,
    0,    9,    0,   47,    0,   64,   91,    0,   69,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   76,
   77,   78,    0,   59,    0,   56,    0,    0,    0,    0,
    0,    0,    0,    0,  118,    0,    0,   98,  114,  113,
   97,  109,  108,  107,   96,  104,   95,   94,    0,    0,
    0,   99,  100,    7,   92,   65,    0,   70,    0,    0,
   61,    0,    0,    0,    0,    0,    0,  116,    0,  115,
  103,  119,  121,  123,    0,   67,   57,   58,    0,    0,
    0,    0,    0,    0,  117,    0,    0,    0,    0,    0,
    0,    0,  102,    0,  110,    0,    0,    0,    0,    0,
    0,  101,  106,  111,    0,    0,  112,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  309,  310,  311,  312,  313,  314,  315,  316,  317,  318,
  326,  350,  351,  352,  353,  354,  355,  362,  363,  364,
  351,  269,  319,  358,  359,  360,  361,  365,  366,  367,
  368,  369,  370,  351,  362,  319,  367,  303,  305,  279,
  301,  300,  300,  301,  279,  300,  301,  279,  305,  303,
  304,  351,  356,  357,  268,  269,  276,  303,  319,  320,
  321,  323,  324,  327,  328,  329,  330,  331,  332,  333,
  334,  335,  373,  327,  269,  319,  360,  269,  319,  361,
  327,  319,  368,  307,  371,  327,  304,  356,  375,  358,
  304,  301,  269,  319,  335,  319,  335,  319,  327,  279,
  305,  306,  303,  263,  264,  259,  260,  274,  275,  267,
  268,  269,  270,  271,  319,  327,  371,  372,  306,  304,
  307,  338,  374,  356,  279,  304,  330,  327,  304,  330,
  336,  332,  332,  333,  333,  333,  333,  334,  334,  335,
  335,  335,  301,  308,  301,  308,  286,  287,  289,  294,
  295,  296,  297,  298,  308,  327,  337,  338,  339,  340,
  341,  342,  343,  344,  345,  346,  347,  348,  349,  350,
  351,  376,  377,  338,  330,  306,  301,  304,  371,  372,
  327,  303,  303,  303,  303,  349,  303,  300,  327,  300,
  300,  308,  337,  337,  319,  336,  308,  308,  323,  327,
  327,  327,  294,  327,  300,  301,  304,  304,  304,  303,
  300,  288,  300,  338,  349,  327,  327,  304,  290,  304,
  300,  300,  338,  300,  327,  304,  349,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         11,
  156,   65,   66,   67,   68,   69,   70,   71,   72,  131,
  157,  158,  159,  160,  161,  162,  163,  164,  165,  166,
  167,  168,  169,  170,   52,   14,   15,   16,   17,   53,
   54,   24,   25,   26,   27,   18,   19,   20,   28,   29,
   30,   31,   32,   33,   85,  118,   73,  123,   89,  172,
  173,
};
static const YYINT yysindex[] = {                       327,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  327,
    0,    0, -260,  327,    0,    0,    0,    0,    0,  327,
    0, -296, -188, -247, -264, -244, -220, -261, -226,    0,
 -200, -241, -254,    0,    0, -179,    0,   99,   -6,   -6,
 -256,    0,    0, -242,   -6,    0, -208, -164,   -6,  317,
    0, -256, -138, -123,   33,   52, -112,   -6, -253,    0,
    0,    0,    0, -126,    0, -109,    0, -145, -152, -139,
  -85,    0,    0,    0, -110,    0,    0,  -96, -179,    0,
    0,  -74,    0,  -36,    0,  -78,    0,  -69,  -71,    0,
    0,  327,   33,  -68,    0, -248,    0,    0,  -63,   -6,
   -6,    0,  -30,   33,   33,   33,   33,   33,   33,   33,
   33,   33,   33,   33,    0,    0, -280, -198,    0,    0,
 -222,    0,  -71,    0,   -6,    0,    0,  -64,    0,  -58,
  -56, -152, -152, -139, -139, -139, -139,  -85,  -85,    0,
    0,    0,  -36,    0,   -6,    0,  -54,  -53,  -52,  -46,
  -42,  -45,   27,  -41,    0,  -40,  -33,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -99,  -99,
 -240,    0,    0,    0,    0,    0,   -6,    0,  -32, -192,
    0,  -59,   -6,   -6,   -6,  -28,   -6,    0,  -31,    0,
    0,    0,    0,    0, -114,    0,    0,    0,  -29,  -24,
  -18,  -12,  -35,   -2,    0,   11,    5,  -71,  -42,   -6,
   -6,   -4,    0,   14,    0,    2,    7,    8,  -71,   10,
   -6,    0,    0,    0,   12,  -42,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -236,
    0,    0,    0, -235,    0,    0,    0,    0,    0,  311,
    0,    0, -262, -151,   19,    0,    0,   24, -108,    0,
    0,   25, -100,    0,    0, -174,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -259,    0,    0,   22,    0,    0,    0,    0,  118,    0,
    0,    0,    0,    0,    0,  131,    0, -125,   59,  233,
  181,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -257,    0,    0,  118,    0,  118,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   29,
    0,  166,  316,  251,  268,  286,  303,  194,  216,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   21,   23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -262,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -156,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  -39,    0,    0,  -95,    0,   98,   28,   95,  -44,  135,
   60,  -87,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -148,   35,    4,    0,    0,    0,    0,  -34,
    0,  280,    0,  293,  291,  318,    0,    0,    0,    0,
   -7,  290,    0,    0,  -77,  196,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 645
static const YYINT yytable[] = {                         64,
   74,  122,  186,   13,  127,   81,  117,  130,   22,   86,
   95,   97,   75,   21,   37,   88,   35,   34,   99,   44,
  143,   45,   36,   13,   48,  100,   78,  144,   22,  175,
  125,   40,   15,   13,   12,  174,   41,   35,   35,   44,
   44,   44,   45,   45,  116,   55,   56,    8,   97,    6,
   49,  101,   45,   57,   12,   42,  101,  124,   23,   47,
  215,  128,   76,  147,  148,  179,  149,  140,  141,  142,
   37,  150,  151,  152,  153,  154,   79,  227,  195,   43,
   58,  130,   15,   13,  121,  155,    1,    2,    3,    4,
    5,    6,    7,    8,    9,   10,   59,   60,   61,   46,
   62,   63,  145,  116,   36,  181,  106,  107,  145,  146,
   82,  105,  105,  189,   38,  198,   39,  104,  105,  105,
  214,  108,  109,   50,  171,   36,   36,  110,  111,  105,
  105,  223,  105,  134,  135,  136,  137,  105,  105,  105,
  105,  105,   84,  200,  201,  202,  105,  204,   33,   33,
  105,  105,  105,  105,  105,  105,  105,  105,  105,  105,
  105,  105,  105,  105,  105,   91,  105,  105,   55,   56,
  216,  217,  171,  171,   90,   90,   57,   92,   90,  102,
   90,  225,   90,  112,  113,  114,  147,  148,   50,  149,
   39,   40,   40,  103,  150,  151,  152,  153,  154,   52,
   52,  132,  133,   58,  138,  139,   98,  121,  115,    1,
    2,    3,    4,    5,    6,    7,    8,    9,   10,   59,
   60,   61,   79,   62,   63,   55,   56,  119,  193,  194,
   39,   55,   56,   57,  120,  121,  101,   55,   56,   57,
  126,  176,  177,  147,  148,   57,  149,  178,  182,  183,
  184,  150,  151,  152,  153,  154,  185,  187,  190,  191,
   58,   55,   56,  199,  121,  203,   58,  210,  205,   57,
   84,  206,   58,  129,  192,  197,   59,   60,   61,  207,
   62,   63,   59,   60,   61,  208,   62,   63,   59,   60,
   61,  209,   62,   63,   55,   56,   58,  211,  212,  218,
   55,   93,   57,  219,  213,  220,  221,  222,   57,  224,
    1,  196,   59,   60,   61,  226,   62,   63,   31,   55,
   93,   87,   87,   38,   50,   46,  188,   57,  120,   58,
  122,   90,   66,   77,   80,   58,   83,   35,  180,    0,
    0,    0,    0,    0,    0,   59,   60,   61,    0,   62,
   63,   94,   60,   61,   58,   62,   63,    0,   87,   87,
    0,    0,   87,    0,   87,    0,   87,    0,    0,    0,
   96,   60,   61,    0,   62,   63,   62,   62,    0,    0,
   62,   62,    0,    0,   62,   62,   62,   62,   62,   71,
   71,   62,   62,   71,   71,    0,    0,   71,   71,   71,
   71,   71,   51,    0,   71,   71,    0,    1,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   62,   62,    0,
   62,   62,    0,   62,    0,   62,    0,    0,   88,   88,
   71,   71,    0,    0,   71,    0,   71,    0,   71,   79,
   79,    0,    0,   79,   79,    0,    0,   79,   79,    0,
    0,    0,   80,   80,   79,   79,   80,   80,    0,    0,
   80,   80,    0,    0,    0,   88,   88,   80,   80,   88,
    0,   88,    0,   88,   81,   81,    0,    0,   81,   81,
   79,   79,   81,   81,   79,    0,   79,    0,   79,   81,
   81,   82,   82,   80,   80,   82,   82,   80,    0,   80,
    0,   80,    0,    0,    0,    0,   82,   82,    0,   84,
   84,    0,    0,   84,   84,   81,   81,    0,    0,   81,
    0,   81,    0,   81,   84,   84,   86,   86,    0,    0,
   86,   86,   82,   82,    0,    0,   82,    0,   82,    0,
   82,   86,   86,    0,   83,   83,    0,    0,   83,   83,
   84,   84,    0,    0,   84,    0,   84,    0,   84,   83,
   83,   85,   85,    0,    0,   85,   85,   86,   86,    0,
    0,   86,    0,   86,    0,   86,   85,   85,   89,   89,
    0,    0,    0,    0,    0,   83,   83,    0,    0,   83,
    0,   83,    0,   83,    0,    0,    0,    0,    0,    0,
    0,    0,   85,   85,    0,    0,   85,    0,   85,    0,
   85,    0,    0,    0,    0,   89,   89,    0,    0,   89,
   87,   89,    0,   89,    0,    1,    2,    3,    4,    5,
    6,    7,    8,    9,   10,    1,    2,    3,    4,    5,
    6,    7,    8,    9,   10,
};
static const YYINT yycheck[] = {                         39,
   40,   89,  151,    0,  100,   45,   84,  103,  269,   49,
   55,   56,  269,   10,   22,   50,  279,   14,   58,  279,
  301,  279,  319,   20,  279,  279,  269,  308,  269,  125,
  279,  279,  269,  269,    0,  123,  301,  300,  301,  301,
  300,  301,  300,  301,   84,  268,  269,  307,   93,  307,
  305,  305,  279,  276,   20,  300,  305,   92,  319,  301,
  209,  101,  319,  286,  287,  143,  289,  112,  113,  114,
   78,  294,  295,  296,  297,  298,  319,  226,  319,  300,
  303,  177,  319,  319,  307,  308,  309,  310,  311,  312,
  313,  314,  315,  316,  317,  318,  319,  320,  321,  300,
  323,  324,  301,  143,  279,  145,  259,  260,  301,  308,
  319,  268,  269,  153,  303,  308,  305,  263,  264,  276,
  208,  274,  275,  303,  121,  300,  301,  267,  268,  286,
  287,  219,  289,  106,  107,  108,  109,  294,  295,  296,
  297,  298,  307,  183,  184,  185,  303,  187,  300,  301,
  307,  308,  309,  310,  311,  312,  313,  314,  315,  316,
  317,  318,  319,  320,  321,  304,  323,  324,  268,  269,
  210,  211,  169,  170,  300,  301,  276,  301,  304,  306,
  306,  221,  308,  269,  270,  271,  286,  287,  303,  289,
  305,  300,  301,  303,  294,  295,  296,  297,  298,  300,
  301,  104,  105,  303,  110,  111,  319,  307,  319,  309,
  310,  311,  312,  313,  314,  315,  316,  317,  318,  319,
  320,  321,  319,  323,  324,  268,  269,  306,  169,  170,
  305,  268,  269,  276,  304,  307,  305,  268,  269,  276,
  304,  306,  301,  286,  287,  276,  289,  304,  303,  303,
  303,  294,  295,  296,  297,  298,  303,  303,  300,  300,
  303,  268,  269,  323,  307,  294,  303,  303,  300,  276,
  307,  301,  303,  304,  308,  308,  319,  320,  321,  304,
  323,  324,  319,  320,  321,  304,  323,  324,  319,  320,
  321,  304,  323,  324,  268,  269,  303,  300,  288,  304,
  268,  269,  276,  290,  300,  304,  300,  300,  276,  300,
    0,  177,  319,  320,  321,  304,  323,  324,  300,  268,
  269,  263,  264,  300,  300,  304,  300,  276,  308,  303,
  308,   52,  304,   41,   44,  303,   47,   20,  143,   -1,
   -1,   -1,   -1,   -1,   -1,  319,  320,  321,   -1,  323,
  324,  319,  320,  321,  303,  323,  324,   -1,  300,  301,
   -1,   -1,  304,   -1,  306,   -1,  308,   -1,   -1,   -1,
  319,  320,  321,   -1,  323,  324,  259,  260,   -1,   -1,
  263,  264,   -1,   -1,  267,  268,  269,  270,  271,  259,
  260,  274,  275,  263,  264,   -1,   -1,  267,  268,  269,
  270,  271,  304,   -1,  274,  275,   -1,  309,  310,  311,
  312,  313,  314,  315,  316,  317,  318,  300,  301,   -1,
  303,  304,   -1,  306,   -1,  308,   -1,   -1,  263,  264,
  300,  301,   -1,   -1,  304,   -1,  306,   -1,  308,  259,
  260,   -1,   -1,  263,  264,   -1,   -1,  267,  268,   -1,
   -1,   -1,  259,  260,  274,  275,  263,  264,   -1,   -1,
  267,  268,   -1,   -1,   -1,  300,  301,  274,  275,  304,
   -1,  306,   -1,  308,  259,  260,   -1,   -1,  263,  264,
  300,  301,  267,  268,  304,   -1,  306,   -1,  308,  274,
  275,  259,  260,  300,  301,  263,  264,  304,   -1,  306,
   -1,  308,   -1,   -1,   -1,   -1,  274,  275,   -1,  259,
  260,   -1,   -1,  263,  264,  300,  301,   -1,   -1,  304,
   -1,  306,   -1,  308,  274,  275,  259,  260,   -1,   -1,
  263,  264,  300,  301,   -1,   -1,  304,   -1,  306,   -1,
  308,  274,  275,   -1,  259,  260,   -1,   -1,  263,  264,
  300,  301,   -1,   -1,  304,   -1,  306,   -1,  308,  274,
  275,  259,  260,   -1,   -1,  263,  264,  300,  301,   -1,
   -1,  304,   -1,  306,   -1,  308,  274,  275,  263,  264,
   -1,   -1,   -1,   -1,   -1,  300,  301,   -1,   -1,  304,
   -1,  306,   -1,  308,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  300,  301,   -1,   -1,  304,   -1,  306,   -1,
  308,   -1,   -1,   -1,   -1,  300,  301,   -1,   -1,  304,
  304,  306,   -1,  308,   -1,  309,  310,  311,  312,  313,
  314,  315,  316,  317,  318,  309,  310,  311,  312,  313,
  314,  315,  316,  317,  318,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 11
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 324
#define YYUNDFTOKEN 378
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","INC","DEC","LESS_OR_EQUAL_THAN",
"GREATER_OR_EQUAL_THAN","SHIFT_LEFT","SHIFT_RIGHT","EQUAL","NOT_EQUAL","AND",
"OR","ADD","MINUS","MULTIPLY","DIVIDE","MOD","LOGICAL_NOT","BITWISE_NOT",
"LESS_THAN","GREATER_THAN","AND_OP","OR_OP","XOR_OP","ASSIGN","UMINUS","UADD",
"UMULTI","UANDOP","INCPOST","DECPOST","DIGITALWRITE","DELAY","DVALUE","IF",
"ELSE","SWITCH","CASE","DEFAULT","WHILE","DO","FOR","RETURN","BREAK","CONTINUE",
"SEMICOLON","COMMA","COLON","L_BRACKET","R_BRACKET","L_SQ_BRACKET",
"R_SQ_BRACKET","L_PARENTHESIS","R_PARENTHESIS","INT","CHAR","FLOAT","DOUBLE",
"VOID","SIGNED","UNSIGNED","LONG","SHORT","CONST","IDENTIFIER","CHAR_LITERAL",
"STRING_LITERAL","NL","INT_LITERAL","FLOAT_LITERAL","$accept","program",
"expression","primary_expression","suffix_expression","assignment_expression",
"equality_expression","relational_expression","additive_expression",
"multiplicative_expression","prefix_expression","argument_expression_list",
"statement_declaration_list","compound_statement","return_statement",
"break_statement","jump_statement","for_statement","do_while_statement",
"while_statement","iteration_statement","if_statement","selection_statement",
"expression_statement","statement","declaration","declaration_specifiers",
"type_specifier","scalar_decl","array_decl","func_decl","parameter_list",
"parameter_declaration","scalar_declarator","scalar_init_declarator",
"scalar_init_declarator_list","func_init_declarator_list",
"external_declaration","function_definition","trans_unit",
"func_init_declarator","func_declarator","func_direct_declarator",
"array_init_declarator_list","array_init_declarator","array_declarator",
"array_content","array_expression","LITERAL","$$1","$$2","delay_stmt",
"digitalwrite_stmt","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : trans_unit",
"trans_unit : external_declaration",
"trans_unit : trans_unit external_declaration",
"external_declaration : declaration",
"external_declaration : function_definition",
"$$1 :",
"function_definition : declaration_specifiers IDENTIFIER L_BRACKET parameter_list R_BRACKET $$1 compound_statement",
"$$2 :",
"function_definition : declaration_specifiers IDENTIFIER L_BRACKET R_BRACKET $$2 compound_statement",
"declaration : scalar_decl",
"declaration : array_decl",
"declaration : func_decl",
"declaration_specifiers : type_specifier",
"declaration_specifiers : type_specifier declaration_specifiers",
"declaration_specifiers : CONST",
"declaration_specifiers : CONST declaration_specifiers",
"type_specifier : INT",
"type_specifier : CHAR",
"type_specifier : FLOAT",
"type_specifier : DOUBLE",
"type_specifier : VOID",
"type_specifier : SIGNED",
"type_specifier : UNSIGNED",
"type_specifier : LONG",
"type_specifier : SHORT",
"LITERAL : INT_LITERAL",
"LITERAL : FLOAT_LITERAL",
"LITERAL : CHAR_LITERAL",
"LITERAL : STRING_LITERAL",
"scalar_decl : declaration_specifiers scalar_init_declarator_list SEMICOLON",
"scalar_init_declarator_list : scalar_init_declarator",
"scalar_init_declarator_list : scalar_init_declarator COMMA scalar_init_declarator_list",
"scalar_init_declarator : scalar_declarator",
"scalar_init_declarator : scalar_declarator ASSIGN expression",
"scalar_declarator : IDENTIFIER",
"scalar_declarator : MULTIPLY IDENTIFIER",
"func_decl : declaration_specifiers func_init_declarator_list SEMICOLON",
"func_init_declarator_list : func_init_declarator",
"func_init_declarator_list : func_init_declarator COMMA func_init_declarator_list",
"func_init_declarator : func_declarator",
"func_init_declarator : func_declarator ASSIGN expression",
"func_declarator : func_direct_declarator",
"func_declarator : MULTIPLY func_direct_declarator",
"func_direct_declarator : IDENTIFIER L_BRACKET R_BRACKET",
"func_direct_declarator : IDENTIFIER L_BRACKET parameter_list R_BRACKET",
"parameter_list : parameter_declaration",
"parameter_list : parameter_declaration COMMA parameter_list",
"parameter_declaration : declaration_specifiers scalar_declarator",
"array_decl : declaration_specifiers array_init_declarator_list SEMICOLON",
"array_init_declarator_list : array_init_declarator",
"array_init_declarator_list : array_init_declarator COMMA array_init_declarator_list",
"array_init_declarator : array_declarator",
"array_init_declarator : array_declarator ASSIGN array_content",
"array_declarator : IDENTIFIER L_SQ_BRACKET expression R_SQ_BRACKET",
"array_declarator : array_declarator L_SQ_BRACKET expression R_SQ_BRACKET",
"array_content : L_PARENTHESIS array_expression R_PARENTHESIS",
"array_content : L_PARENTHESIS array_content COMMA array_content R_PARENTHESIS",
"array_content : L_PARENTHESIS array_content COMMA array_expression R_PARENTHESIS",
"array_content : L_PARENTHESIS array_content R_PARENTHESIS",
"array_expression : expression",
"array_expression : array_expression COMMA expression",
"primary_expression : IDENTIFIER",
"primary_expression : LITERAL",
"primary_expression : L_BRACKET expression R_BRACKET",
"primary_expression : IDENTIFIER L_SQ_BRACKET expression R_SQ_BRACKET",
"argument_expression_list : assignment_expression",
"argument_expression_list : assignment_expression COMMA argument_expression_list",
"suffix_expression : primary_expression",
"suffix_expression : suffix_expression L_BRACKET R_BRACKET",
"suffix_expression : suffix_expression L_BRACKET argument_expression_list R_BRACKET",
"prefix_expression : suffix_expression",
"prefix_expression : MINUS prefix_expression",
"prefix_expression : MULTIPLY prefix_expression",
"prefix_expression : AND_OP IDENTIFIER",
"multiplicative_expression : prefix_expression",
"multiplicative_expression : multiplicative_expression MULTIPLY prefix_expression",
"multiplicative_expression : multiplicative_expression DIVIDE prefix_expression",
"multiplicative_expression : multiplicative_expression MOD prefix_expression",
"additive_expression : multiplicative_expression",
"additive_expression : additive_expression ADD multiplicative_expression",
"additive_expression : additive_expression MINUS multiplicative_expression",
"relational_expression : additive_expression",
"relational_expression : relational_expression LESS_THAN additive_expression",
"relational_expression : relational_expression LESS_OR_EQUAL_THAN additive_expression",
"relational_expression : relational_expression GREATER_THAN additive_expression",
"relational_expression : relational_expression GREATER_OR_EQUAL_THAN additive_expression",
"equality_expression : relational_expression",
"equality_expression : equality_expression EQUAL relational_expression",
"equality_expression : equality_expression NOT_EQUAL relational_expression",
"assignment_expression : equality_expression",
"assignment_expression : IDENTIFIER ASSIGN assignment_expression",
"assignment_expression : MULTIPLY IDENTIFIER ASSIGN assignment_expression",
"expression : assignment_expression",
"statement : expression_statement",
"statement : selection_statement",
"statement : iteration_statement",
"statement : jump_statement",
"statement : compound_statement",
"statement : delay_stmt",
"statement : digitalwrite_stmt",
"digitalwrite_stmt : DIGITALWRITE L_BRACKET INT_LITERAL COMMA DVALUE R_BRACKET SEMICOLON",
"delay_stmt : DELAY L_BRACKET expression R_BRACKET SEMICOLON",
"expression_statement : expression SEMICOLON",
"selection_statement : if_statement",
"if_statement : IF L_BRACKET expression R_BRACKET compound_statement",
"if_statement : IF L_BRACKET expression R_BRACKET compound_statement ELSE compound_statement",
"iteration_statement : while_statement",
"iteration_statement : do_while_statement",
"iteration_statement : for_statement",
"while_statement : WHILE L_BRACKET expression R_BRACKET statement",
"do_while_statement : DO statement WHILE L_BRACKET expression R_BRACKET SEMICOLON",
"for_statement : FOR L_BRACKET expression SEMICOLON expression SEMICOLON expression R_BRACKET statement",
"jump_statement : break_statement",
"jump_statement : return_statement",
"break_statement : BREAK SEMICOLON",
"return_statement : RETURN SEMICOLON",
"return_statement : RETURN expression SEMICOLON",
"compound_statement : L_PARENTHESIS R_PARENTHESIS",
"compound_statement : L_PARENTHESIS statement_declaration_list R_PARENTHESIS",
"statement_declaration_list : statement",
"statement_declaration_list : statement statement_declaration_list",
"statement_declaration_list : declaration",
"statement_declaration_list : declaration statement_declaration_list",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

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

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 583 "parser.y"


int main(void) {
    if ((f_asm = fopen(FILENAME, "w")) == NULL) {
        perror("Error at opening file");
    }
    init();
    yyparse();
    fclose(f_asm);
    return 0;
}
int yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return 0;
}
#line 846 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

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

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
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
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 63 "parser.y"
	{  }
#line 1519 "y.tab.c"
break;
case 2:
#line 66 "parser.y"
	{  }
#line 1524 "y.tab.c"
break;
case 3:
#line 67 "parser.y"
	{ }
#line 1529 "y.tab.c"
break;
case 5:
#line 72 "parser.y"
	{ }
#line 1534 "y.tab.c"
break;
case 6:
#line 76 "parser.y"
	{
        cur_scope++;
        set_scope_and_offset_of_param(yystack.l_mark[-1].stringval);
        code_gen_func_header(yystack.l_mark[-3].stringval);
    }
#line 1543 "y.tab.c"
break;
case 7:
#line 81 "parser.y"
	{ 
        pop_up_symbol(cur_scope);
        cur_scope--;
        code_gen_at_end_of_function_body(yystack.l_mark[-5].stringval);
    }
#line 1552 "y.tab.c"
break;
case 8:
#line 86 "parser.y"
	{
        cur_scope++;
        code_gen_func_header(yystack.l_mark[-2].stringval);
    }
#line 1560 "y.tab.c"
break;
case 9:
#line 90 "parser.y"
	{ 
        pop_up_symbol(cur_scope);
        cur_scope--;
        code_gen_at_end_of_function_body(yystack.l_mark[-4].stringval);
    }
#line 1569 "y.tab.c"
break;
case 10:
#line 96 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1574 "y.tab.c"
break;
case 11:
#line 97 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1579 "y.tab.c"
break;
case 12:
#line 98 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1584 "y.tab.c"
break;
case 13:
#line 101 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval ;}
#line 1589 "y.tab.c"
break;
case 14:
#line 103 "parser.y"
	{ 

    }
#line 1596 "y.tab.c"
break;
case 15:
#line 107 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval ;}
#line 1601 "y.tab.c"
break;
case 16:
#line 109 "parser.y"
	{ 

    }
#line 1608 "y.tab.c"
break;
case 26:
#line 127 "parser.y"
	{
        fprintf(f_asm, "    li t0, %d\n", yystack.l_mark[0].intval);
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
      }
#line 1617 "y.tab.c"
break;
case 27:
#line 132 "parser.y"
	{
        /* no need */
    }
#line 1624 "y.tab.c"
break;
case 28:
#line 135 "parser.y"
	{
        /* no need */
    }
#line 1631 "y.tab.c"
break;
case 29:
#line 138 "parser.y"
	{
        /* no need */
    }
#line 1638 "y.tab.c"
break;
case 30:
#line 143 "parser.y"
	{

}
#line 1645 "y.tab.c"
break;
case 31:
#line 149 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1650 "y.tab.c"
break;
case 32:
#line 150 "parser.y"
	{ 

    }
#line 1657 "y.tab.c"
break;
case 33:
#line 157 "parser.y"
	{ 
        yyval.stringval = install_symbol(yystack.l_mark[0].stringval);
        /*fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    sw zero, 0(sp)\n");*/
    }
#line 1666 "y.tab.c"
break;
case 34:
#line 162 "parser.y"
	{ 
        yyval.stringval = install_symbol(yystack.l_mark[-2].stringval);
    }
#line 1673 "y.tab.c"
break;
case 35:
#line 169 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1678 "y.tab.c"
break;
case 36:
#line 170 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1683 "y.tab.c"
break;
case 37:
#line 176 "parser.y"
	{

}
#line 1690 "y.tab.c"
break;
case 38:
#line 182 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1695 "y.tab.c"
break;
case 39:
#line 183 "parser.y"
	{ 

    }
#line 1702 "y.tab.c"
break;
case 40:
#line 190 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1707 "y.tab.c"
break;
case 41:
#line 191 "parser.y"
	{ 

    }
#line 1714 "y.tab.c"
break;
case 42:
#line 198 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1719 "y.tab.c"
break;
case 43:
#line 199 "parser.y"
	{ 

    }
#line 1726 "y.tab.c"
break;
case 44:
#line 206 "parser.y"
	{
        fprintf(f_asm, ".global %s\n", yystack.l_mark[-2].stringval);
    }
#line 1733 "y.tab.c"
break;
case 45:
#line 209 "parser.y"
	{
        fprintf(f_asm, ".global %s\n", yystack.l_mark[-3].stringval);
    }
#line 1740 "y.tab.c"
break;
case 46:
#line 215 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1745 "y.tab.c"
break;
case 47:
#line 216 "parser.y"
	{ 

    }
#line 1752 "y.tab.c"
break;
case 48:
#line 222 "parser.y"
	{ 

    }
#line 1759 "y.tab.c"
break;
case 49:
#line 229 "parser.y"
	{

}
#line 1766 "y.tab.c"
break;
case 50:
#line 235 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1771 "y.tab.c"
break;
case 51:
#line 236 "parser.y"
	{ 

    }
#line 1778 "y.tab.c"
break;
case 52:
#line 243 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1783 "y.tab.c"
break;
case 53:
#line 244 "parser.y"
	{ 

    }
#line 1790 "y.tab.c"
break;
case 54:
#line 250 "parser.y"
	{

    }
#line 1797 "y.tab.c"
break;
case 55:
#line 253 "parser.y"
	{

    }
#line 1804 "y.tab.c"
break;
case 56:
#line 259 "parser.y"
	{ 

     }
#line 1811 "y.tab.c"
break;
case 57:
#line 262 "parser.y"
	{

    }
#line 1818 "y.tab.c"
break;
case 58:
#line 265 "parser.y"
	{

    }
#line 1825 "y.tab.c"
break;
case 59:
#line 268 "parser.y"
	{

    }
#line 1832 "y.tab.c"
break;
case 60:
#line 274 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 1837 "y.tab.c"
break;
case 61:
#line 275 "parser.y"
	{

    }
#line 1844 "y.tab.c"
break;
case 62:
#line 284 "parser.y"
	{
        int index = look_up_symbol(yystack.l_mark[0].stringval);
        if (table[index].mode == LOCAL_MODE) {
            fprintf(f_asm, "    lw t0, %d(s0)\n", table[index].offset * (-4) - 48);
            fprintf(f_asm, "    sw t0, -4(sp)\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");
        } else {
            /*fprintf(f_asm, "    lw t0, %d(sp)\n", table[index].offset * (-4) - 16);
            fprintf(f_asm, "    sw t0, -4(sp)\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");*/
        }
    }
#line 1860 "y.tab.c"
break;
case 63:
#line 296 "parser.y"
	{ 

    }
#line 1867 "y.tab.c"
break;
case 64:
#line 299 "parser.y"
	{ 

    }
#line 1874 "y.tab.c"
break;
case 65:
#line 302 "parser.y"
	{

    }
#line 1881 "y.tab.c"
break;
case 66:
#line 309 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1886 "y.tab.c"
break;
case 67:
#line 310 "parser.y"
	{ 

    }
#line 1893 "y.tab.c"
break;
case 68:
#line 316 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1898 "y.tab.c"
break;
case 69:
#line 317 "parser.y"
	{ 

    }
#line 1905 "y.tab.c"
break;
case 70:
#line 320 "parser.y"
	{ 
    }
#line 1911 "y.tab.c"
break;
case 71:
#line 325 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1916 "y.tab.c"
break;
case 72:
#line 326 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sub t0, zero, t0\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        
    }
#line 1928 "y.tab.c"
break;
case 73:
#line 334 "parser.y"
	{ 
        int index = look_up_symbol(yystack.l_mark[0].stringval);
        fprintf(f_asm, "    lw t0, %d(s0)\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    add t0, t0, s0\n");
        fprintf(f_asm, "    lw t1, 0(t0)\n");
        fprintf(f_asm, "    sw t1, -4(sp)/*here*/\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        
        
    }
#line 1942 "y.tab.c"
break;
case 74:
#line 344 "parser.y"
	{ 
        int index = look_up_symbol(yystack.l_mark[0].stringval);
        fprintf(f_asm, "    li t0, %d\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    sw t0, -4(sp)\n"); /* 0?*/
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 1952 "y.tab.c"
break;
case 75:
#line 355 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1957 "y.tab.c"
break;
case 76:
#line 356 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    mul t0, t0, t1\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 1970 "y.tab.c"
break;
case 77:
#line 365 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    div t0, t1, t0\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 1983 "y.tab.c"
break;
case 78:
#line 374 "parser.y"
	{ 

    }
#line 1990 "y.tab.c"
break;
case 79:
#line 380 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1995 "y.tab.c"
break;
case 80:
#line 381 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    add t0, t0, t1\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 2008 "y.tab.c"
break;
case 81:
#line 390 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sub t0, t1, t0\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 2021 "y.tab.c"
break;
case 82:
#line 402 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2026 "y.tab.c"
break;
case 83:
#line 403 "parser.y"
	{ 

    }
#line 2033 "y.tab.c"
break;
case 84:
#line 406 "parser.y"
	{ 

    }
#line 2040 "y.tab.c"
break;
case 85:
#line 409 "parser.y"
	{ 

    }
#line 2047 "y.tab.c"
break;
case 86:
#line 412 "parser.y"
	{ 

    }
#line 2054 "y.tab.c"
break;
case 87:
#line 418 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2059 "y.tab.c"
break;
case 88:
#line 419 "parser.y"
	{ 

    }
#line 2066 "y.tab.c"
break;
case 89:
#line 422 "parser.y"
	{ 

    }
#line 2073 "y.tab.c"
break;
case 90:
#line 429 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2078 "y.tab.c"
break;
case 91:
#line 430 "parser.y"
	{
        int index = look_up_symbol(yystack.l_mark[-2].stringval);
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    sw t0, %d(s0)\n", table[index].offset * (-4) - 48);
    }
#line 2087 "y.tab.c"
break;
case 92:
#line 435 "parser.y"
	{
        int index = look_up_symbol(yystack.l_mark[-2].stringval);
        fprintf(f_asm, "    lw t0, 0(sp)/*check*/\n");
        fprintf(f_asm, "    lw t1, %d(s0)\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    add t1, s0, t1\n");
        fprintf(f_asm, "    sw t0, 0(t1)\n");
    }
#line 2098 "y.tab.c"
break;
case 93:
#line 447 "parser.y"
	{

    }
#line 2105 "y.tab.c"
break;
case 94:
#line 455 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2110 "y.tab.c"
break;
case 95:
#line 456 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2115 "y.tab.c"
break;
case 96:
#line 457 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2120 "y.tab.c"
break;
case 97:
#line 458 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2125 "y.tab.c"
break;
case 98:
#line 459 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2130 "y.tab.c"
break;
case 101:
#line 465 "parser.y"
	{
        fprintf(f_asm, "    li t0, %d\n", yystack.l_mark[-2].intval);
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    li t0, %d\n", yystack.l_mark[-4].intval);
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    lw a0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw a1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sw ra, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    jal ra, digitalWrite\n");
        fprintf(f_asm, "    lw ra, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
    }
#line 2151 "y.tab.c"
break;
case 102:
#line 485 "parser.y"
	{
        fprintf(f_asm, "    lw a0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sw ra, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    jal ra, delay\n");
        fprintf(f_asm, "    lw ra, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
    }
#line 2164 "y.tab.c"
break;
case 103:
#line 497 "parser.y"
	{ 

    }
#line 2171 "y.tab.c"
break;
case 104:
#line 503 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2176 "y.tab.c"
break;
case 105:
#line 507 "parser.y"
	{ 

    }
#line 2183 "y.tab.c"
break;
case 106:
#line 510 "parser.y"
	{

    }
#line 2190 "y.tab.c"
break;
case 107:
#line 517 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2195 "y.tab.c"
break;
case 108:
#line 518 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2200 "y.tab.c"
break;
case 109:
#line 519 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2205 "y.tab.c"
break;
case 110:
#line 523 "parser.y"
	{  

    }
#line 2212 "y.tab.c"
break;
case 111:
#line 529 "parser.y"
	{ 

    }
#line 2219 "y.tab.c"
break;
case 112:
#line 535 "parser.y"
	{

    }
#line 2226 "y.tab.c"
break;
case 113:
#line 541 "parser.y"
	{yyval.stringval =yystack.l_mark[0].stringval;}
#line 2231 "y.tab.c"
break;
case 114:
#line 542 "parser.y"
	{yyval.stringval =yystack.l_mark[0].stringval;}
#line 2236 "y.tab.c"
break;
case 115:
#line 546 "parser.y"
	{ 

    }
#line 2243 "y.tab.c"
break;
case 116:
#line 552 "parser.y"
	{ 

    }
#line 2250 "y.tab.c"
break;
case 117:
#line 555 "parser.y"
	{

    }
#line 2257 "y.tab.c"
break;
case 118:
#line 561 "parser.y"
	{ 

     }
#line 2264 "y.tab.c"
break;
case 119:
#line 564 "parser.y"
	{ 

     }
#line 2271 "y.tab.c"
break;
case 120:
#line 570 "parser.y"
	{ 

    }
#line 2278 "y.tab.c"
break;
case 121:
#line 573 "parser.y"
	{ 

    }
#line 2285 "y.tab.c"
break;
case 122:
#line 576 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2290 "y.tab.c"
break;
case 123:
#line 577 "parser.y"
	{ 

    }
#line 2297 "y.tab.c"
break;
#line 2299 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
