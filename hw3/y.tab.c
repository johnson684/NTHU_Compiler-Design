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
    int dbg=0;
    int lineNo = 1;
    int in_if = 0;
    int in_while = 0;
    int in_for = 0;
    int is_array = 0;
    extern FILE* f_asm;
    int arg_cnt;
    int assignflag = 0;
    int do_flag=0;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 17 "parser.y"
typedef union YYSTYPE {
  int intval;
  double dval;
  char* stringval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 52 "y.tab.c"

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
    0,   39,   39,   37,   37,   49,   38,   50,   38,   25,
   25,   25,   26,   26,   26,   26,   27,   27,   27,   27,
   27,   27,   27,   27,   27,   48,   48,   48,   48,   28,
   35,   35,   34,   34,   33,   33,   30,   36,   36,   40,
   40,   41,   41,   42,   42,   31,   31,   32,   29,   43,
   43,   44,   44,   45,   45,   46,   46,   46,   46,   47,
   47,    3,    3,    3,    3,   11,   11,    4,    4,    4,
   10,   10,   10,   10,    9,    9,    9,    8,    8,    8,
    7,    7,    7,    7,    7,    6,    6,    6,    5,    5,
    5,    5,    1,    1,    2,   24,   24,   24,   24,   24,
   24,   24,   52,   51,   23,   22,   54,   53,   21,   55,
   21,   20,   20,   20,   56,   57,   19,   58,   18,   59,
   60,   17,   16,   16,   15,   14,   14,   13,   13,   12,
   12,   12,   12,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    1,    0,    7,    0,    6,    1,
    1,    1,    1,    2,    1,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    1,    3,    1,    3,    1,    2,    3,    1,    3,    1,
    3,    1,    2,    3,    4,    1,    3,    2,    3,    1,
    3,    1,    3,    4,    4,    3,    5,    5,    3,    1,
    3,    1,    1,    3,    4,    1,    3,    1,    3,    4,
    1,    2,    2,    2,    1,    3,    3,    1,    3,    3,
    1,    3,    3,    3,    3,    1,    3,    3,    1,    3,
    3,    6,    2,    4,    1,    1,    1,    1,    1,    1,
    1,    1,    7,    5,    2,    1,    0,    4,    3,    0,
    6,    1,    1,    1,    0,    0,    7,    0,    8,    0,
    0,   15,    1,    1,    2,    2,    3,    2,    3,    1,
    2,    1,    2,
};
static const YYINT yydefred[] = {                         0,
   17,   18,   19,   20,   21,   22,   23,   24,   25,    0,
    0,    4,    0,    0,   10,   11,   12,    2,    5,    0,
   16,    0,    0,    0,    0,    0,    0,    0,    0,   42,
    0,    0,    0,   14,    3,    0,   43,    0,    0,    0,
    0,   30,   37,    0,    0,   49,    0,    0,    0,    0,
    0,    0,    0,    0,   28,   29,   26,   27,    0,    0,
    0,    0,    0,    0,    0,   34,   68,    0,   95,    0,
    0,    0,    0,   75,   63,    0,   35,   32,    0,    0,
   39,   41,    0,   51,    0,   53,    0,   44,    0,    0,
   48,    0,    0,   54,    0,    0,   72,    0,    0,   73,
   74,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   36,   60,    0,    0,
   55,   45,    0,    9,    0,   47,    0,    0,   64,   90,
    0,   91,   69,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   76,   77,    0,   59,    0,   56,    0,
    0,  107,  115,  118,    0,    0,    0,  128,    0,    0,
  100,  124,  123,   99,  114,  113,  112,   98,  106,   97,
   96,    0,    0,    0,  101,  102,    0,    7,    0,    0,
    0,    0,   70,    0,    0,   61,    0,    0,    0,    0,
    0,    0,  126,    0,  125,  105,  129,  131,  133,    0,
    0,   65,    0,   67,   57,   58,    0,    0,    0,    0,
    0,    0,  127,    0,   92,    0,    0,  108,  116,    0,
  120,  110,    0,  104,    0,    0,    0,    0,    0,    0,
    0,    0,  111,  103,  117,    0,  121,  119,    0,    0,
    0,    0,    0,    0,    0,  122,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  309,  310,  311,  312,  313,  314,  315,  316,  317,  318,
  326,  351,  352,  353,  354,  355,  356,  363,  364,  365,
  352,  269,  319,  359,  360,  361,  362,  366,  367,  368,
  369,  370,  371,  352,  363,  319,  368,  303,  305,  279,
  301,  300,  300,  301,  279,  300,  301,  279,  305,  303,
  304,  352,  357,  358,  320,  321,  323,  324,  374,  268,
  269,  276,  303,  319,  327,  328,  329,  330,  331,  332,
  333,  334,  335,  336,  374,  269,  319,  361,  269,  319,
  362,  328,  319,  369,  307,  372,  328,  304,  357,  376,
  359,  304,  301,  306,  269,  319,  336,  303,  319,  336,
  319,  328,  279,  305,  279,  303,  263,  264,  259,  260,
  274,  275,  267,  268,  269,  270,  319,  328,  372,  373,
  306,  304,  307,  339,  375,  357,  305,  328,  304,  331,
  328,  331,  304,  331,  337,  333,  333,  334,  334,  334,
  334,  335,  335,  336,  336,  301,  308,  301,  308,  286,
  287,  289,  294,  295,  296,  297,  298,  308,  328,  338,
  339,  340,  341,  342,  343,  344,  345,  346,  347,  348,
  349,  350,  351,  352,  377,  378,  379,  339,  328,  304,
  306,  301,  304,  372,  373,  328,  303,  303,  380,  382,
  384,  303,  300,  328,  300,  300,  308,  338,  338,  319,
  304,  306,  279,  337,  308,  308,  323,  328,  303,  303,
  350,  328,  300,  339,  331,  301,  304,  328,  328,  294,
  300,  290,  288,  300,  383,  303,  385,  381,  304,  304,
  328,  328,  339,  300,  350,  304,  300,  300,  386,  319,
  279,  319,  267,  323,  304,  339,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         11,
   65,  159,   67,   68,   69,   70,   71,   72,   73,   74,
  135,  160,  161,  162,  163,  164,  165,  166,  167,  168,
  169,  170,  171,  172,  173,   52,   14,   15,   16,   17,
   53,   54,   24,   25,   26,   27,   18,   19,   20,   28,
   29,   30,   31,   32,   33,   86,  120,   75,  125,   90,
  175,  176,  177,  189,  228,  190,  225,  191,  227,  239,
};
static const YYINT yysindex[] = {                       424,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  424,
    0,    0, -257,  424,    0,    0,    0,    0,    0,  424,
    0, -303, -275, -241, -274, -215, -199, -191, -152,    0,
 -167, -165, -259,    0,    0, -147,    0,  208, -209,   46,
 -256,    0,    0, -252,   46,    0, -175, -154,   46,  414,
    0, -256, -145, -129,    0,    0,    0,    0, -126,   78,
   84, -158,   46, -253, -102,    0,    0, -120,    0, -220,
 -140, -137, -123,    0,    0, -134,    0,    0, -131, -147,
    0,    0, -104,    0, -198,    0,  -89,    0,  -80,  -82,
    0,    0,  424,    0,   78,  -79,    0,   46,  -79,    0,
    0,  -75,   46,   46,   46,   15,   78,   78,   78,   78,
   78,   78,   78,   78,   78,   78,    0,    0, -269, -169,
    0,    0, -105,    0,  -82,    0,   46,  -74,    0,    0,
  -73,    0,    0,  -70,  -72, -140, -140, -137, -137, -137,
 -137, -123, -123,    0,    0, -198,    0,   46,    0,  -76,
  -69,    0,    0,    0,  -68,   21,  -57,    0,  -55,  -56,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -221, -221, -247,    0,    0,  -53,    0,  -52,    0,
  -26,   46,    0,  -51, -159,    0,  -67,   46,  -45,  -29,
    9,   46,    0,  -21,    0,    0,    0,    0,    0, -249,
  -82,    0,   46,    0,    0,    0,  -20,  -24,   46,   46,
  -12,  -14,    0,   -3,    0,    4,   -7,    0,    0,  -15,
    0,    0,  -10,    0,   -5,   46,   46,  -82,    2,    9,
   -4,    8,    0,    0,    0,   10,    0,    0,  -18,   30,
   -8,   53,   -6,   19,  -82,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -238,
    0,    0,    0, -235,    0,    0,    0,    0,    0,  313,
    0,    0, -260, -150,   25,    0,    0,   26, -125,    0,
    0,   27, -122,    0,    0, -172,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -265,    0,    0,   39,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  178,    0,    0,    0,  241,    0, -163,
 -146,  343,  291,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -250,    0,    0,    0,  178,    0,    0,  115,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   44,    0,  -64,  150,  361,  378,  396,
  413,  304,  326,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   23,   29,    0,    0,    0,    0,    0,    0,  165,
  228,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -260,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  -40,    0,    0,  -99,    0,   87,   56,   83,  -36,
  168,   50,  -88,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -181,   33,    1,    0,    0,    0,    0,
  -32,    0,  299,    0,  314,  312,  337,    0,    0,    0,
    0,  -19,  311,    0,    0,  -77,  213,  322,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 742
static const YYINT yytable[] = {                         66,
   13,  124,   37,  130,   82,  132,  134,  119,   87,  211,
   21,   22,   76,   44,   34,   36,   79,   89,   35,   48,
   13,   22,  102,   97,  100,  103,   41,   38,   45,   39,
   15,  146,   12,   13,   44,   44,  178,   40,  147,   35,
   35,    8,  107,  108,  118,   49,   60,   61,  235,   45,
   45,  104,   12,   50,   62,   39,    6,  128,  100,   37,
  126,   23,   77,  131,  150,  151,   80,  152,  184,   60,
   61,  200,  153,  154,  155,  156,  157,   62,  144,  145,
   15,   63,  134,   13,   42,  123,  179,    1,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   64,   55,   56,
   43,   57,   58,  215,   63,  118,   36,  186,   85,   44,
   55,   56,  214,   57,   58,  194,   86,   86,  109,  110,
   64,   55,   56,  174,   57,   58,   45,   36,   36,  113,
  114,  148,   46,  111,  112,   47,   89,   89,  149,  233,
   89,  148,   89,   83,   89,  115,  116,  208,  206,   33,
   33,  212,   85,   86,   86,   50,  246,   86,   92,   86,
  101,   86,   60,   61,  138,  139,  140,  141,  218,  219,
   62,   93,  174,  174,   40,   40,  105,   52,   52,   94,
  150,  151,  106,  152,  117,  231,  232,   80,  153,  154,
  155,  156,  157,  136,  137,  142,  143,   63,   87,   87,
   39,  123,  158,    1,    2,    3,    4,    5,    6,    7,
    8,    9,   10,   64,   55,   56,  121,   57,   58,  109,
  109,  198,  199,  122,  123,  127,  187,  109,  129,  180,
  182,  183,  181,  188,  192,   87,   87,  109,  109,   87,
  109,   87,  195,   87,  196,  109,  109,  109,  109,  109,
  201,  197,  203,  202,  109,  207,  205,  209,  109,  109,
  109,  109,  109,  109,  109,  109,  109,  109,  109,  109,
  109,  109,  109,  210,  109,  109,   60,   61,  213,  217,
  216,  220,   60,   61,   62,  221,  222,  226,   60,   61,
   62,  223,  224,  229,  150,  151,   62,  152,  230,  236,
  240,  234,  153,  154,  155,  156,  157,  237,  241,  238,
  242,   63,    1,   60,   61,  123,  244,   63,  133,  243,
  193,   62,  245,   63,   31,   38,   50,   64,   55,   56,
  130,   57,   58,   64,   55,   56,  132,   57,   58,   64,
   55,   56,   46,   57,   58,   60,   95,   66,   63,  204,
   91,   60,   95,   62,   78,   81,   35,   84,  185,   62,
   59,    0,    0,    0,   64,   55,   56,    0,   57,   58,
    0,    0,    0,   62,   62,    0,    0,   62,   62,    0,
   63,   62,   62,   62,   62,    0,   98,    0,   62,   62,
    0,    0,    0,   93,    0,    0,   96,   55,   56,    0,
   57,   58,   99,   55,   56,    0,   57,   58,    0,    0,
    0,    0,   88,   88,   62,   62,    0,   62,   62,    0,
   62,    0,   62,   64,   64,    0,    0,   64,   64,    0,
    0,   64,   64,   64,   64,    0,   62,   62,   64,   64,
   62,   62,    0,   94,   62,   62,   62,   62,    0,   88,
   88,   62,   62,   88,    0,   88,    0,   88,    0,    0,
    0,    0,    0,    0,   64,   64,    0,   64,   64,    0,
   64,    0,   64,    0,    0,    0,    0,   62,   62,    0,
   62,   62,    0,   62,    0,   62,   65,   65,    0,    0,
   65,   65,    0,    0,   65,   65,   65,   65,    0,   71,
   71,   65,   65,   71,   71,    0,    0,   71,   71,   71,
   71,   51,    0,    0,   71,   71,    1,    2,    3,    4,
    5,    6,    7,    8,    9,   10,    0,   65,   65,    0,
   65,   65,    0,   65,    0,   65,    0,    0,    0,    0,
   71,   71,    0,    0,   71,    0,   71,    0,   71,   78,
   78,    0,    0,   78,   78,    0,    0,   78,   78,    0,
    0,    0,   79,   79,   78,   78,   79,   79,    0,    0,
   79,   79,    0,    0,    0,    0,    0,   79,   79,    0,
    0,    0,    0,    0,   80,   80,    0,    0,   80,   80,
   78,   78,   80,   80,   78,    0,   78,    0,   78,   80,
   80,   81,   81,   79,   79,   81,   81,   79,    0,   79,
    0,   79,    0,    0,    0,    0,   81,   81,    0,   83,
   83,    0,    0,   83,   83,   80,   80,    0,    0,   80,
    0,   80,    0,   80,   83,   83,   85,   85,    0,    0,
   85,   85,   81,   81,    0,    0,   81,    0,   81,    0,
   81,   85,   85,    0,   82,   82,    0,    0,   82,   82,
   83,   83,    0,    0,   83,    0,   83,    0,   83,   82,
   82,   84,   84,    0,    0,   84,   84,   85,   85,    0,
    0,   85,    0,   85,    0,   85,   84,   84,    0,    0,
    0,    0,    0,    0,    0,   82,   82,    0,    0,   82,
    0,   82,    0,   82,    0,    0,    0,    0,    0,    0,
    0,    0,   84,   84,    0,    0,   84,   88,   84,    0,
   84,    0,    1,    2,    3,    4,    5,    6,    7,    8,
    9,   10,    1,    2,    3,    4,    5,    6,    7,    8,
    9,   10,
};
static const YYINT yycheck[] = {                         40,
    0,   90,   22,  103,   45,  105,  106,   85,   49,  191,
   10,  269,  269,  279,   14,  319,  269,   50,  279,  279,
   20,  269,   63,   60,   61,  279,  301,  303,  279,  305,
  269,  301,    0,  269,  300,  301,  125,  279,  308,  300,
  301,  307,  263,  264,   85,  305,  268,  269,  230,  300,
  301,  305,   20,  303,  276,  305,  307,   98,   95,   79,
   93,  319,  319,  104,  286,  287,  319,  289,  146,  268,
  269,  319,  294,  295,  296,  297,  298,  276,  115,  116,
  319,  303,  182,  319,  300,  307,  127,  309,  310,  311,
  312,  313,  314,  315,  316,  317,  318,  319,  320,  321,
  300,  323,  324,  203,  303,  146,  279,  148,  307,  301,
  320,  321,  201,  323,  324,  156,  263,  264,  259,  260,
  319,  320,  321,  123,  323,  324,  279,  300,  301,  267,
  268,  301,  300,  274,  275,  301,  300,  301,  308,  228,
  304,  301,  306,  319,  308,  269,  270,  188,  308,  300,
  301,  192,  307,  300,  301,  303,  245,  304,  304,  306,
  319,  308,  268,  269,  109,  110,  111,  112,  209,  210,
  276,  301,  172,  173,  300,  301,  279,  300,  301,  306,
  286,  287,  303,  289,  319,  226,  227,  319,  294,  295,
  296,  297,  298,  107,  108,  113,  114,  303,  263,  264,
  305,  307,  308,  309,  310,  311,  312,  313,  314,  315,
  316,  317,  318,  319,  320,  321,  306,  323,  324,  268,
  269,  172,  173,  304,  307,  305,  303,  276,  304,  304,
  301,  304,  306,  303,  303,  300,  301,  286,  287,  304,
  289,  306,  300,  308,  300,  294,  295,  296,  297,  298,
  304,  308,  279,  306,  303,  323,  308,  303,  307,  308,
  309,  310,  311,  312,  313,  314,  315,  316,  317,  318,
  319,  320,  321,  303,  323,  324,  268,  269,  300,  304,
  301,  294,  268,  269,  276,  300,  290,  303,  268,  269,
  276,  288,  300,  304,  286,  287,  276,  289,  304,  304,
  319,  300,  294,  295,  296,  297,  298,  300,  279,  300,
  319,  303,    0,  268,  269,  307,  323,  303,  304,  267,
  300,  276,  304,  303,  300,  300,  300,  319,  320,  321,
  308,  323,  324,  319,  320,  321,  308,  323,  324,  319,
  320,  321,  304,  323,  324,  268,  269,  304,  303,  182,
   52,  268,  269,  276,   41,   44,   20,   47,  146,  276,
   39,   -1,   -1,   -1,  319,  320,  321,   -1,  323,  324,
   -1,   -1,   -1,  259,  260,   -1,   -1,  263,  264,   -1,
  303,  267,  268,  269,  270,   -1,  303,   -1,  274,  275,
   -1,   -1,   -1,  279,   -1,   -1,  319,  320,  321,   -1,
  323,  324,  319,  320,  321,   -1,  323,  324,   -1,   -1,
   -1,   -1,  263,  264,  300,  301,   -1,  303,  304,   -1,
  306,   -1,  308,  259,  260,   -1,   -1,  263,  264,   -1,
   -1,  267,  268,  269,  270,   -1,  259,  260,  274,  275,
  263,  264,   -1,  279,  267,  268,  269,  270,   -1,  300,
  301,  274,  275,  304,   -1,  306,   -1,  308,   -1,   -1,
   -1,   -1,   -1,   -1,  300,  301,   -1,  303,  304,   -1,
  306,   -1,  308,   -1,   -1,   -1,   -1,  300,  301,   -1,
  303,  304,   -1,  306,   -1,  308,  259,  260,   -1,   -1,
  263,  264,   -1,   -1,  267,  268,  269,  270,   -1,  259,
  260,  274,  275,  263,  264,   -1,   -1,  267,  268,  269,
  270,  304,   -1,   -1,  274,  275,  309,  310,  311,  312,
  313,  314,  315,  316,  317,  318,   -1,  300,  301,   -1,
  303,  304,   -1,  306,   -1,  308,   -1,   -1,   -1,   -1,
  300,  301,   -1,   -1,  304,   -1,  306,   -1,  308,  259,
  260,   -1,   -1,  263,  264,   -1,   -1,  267,  268,   -1,
   -1,   -1,  259,  260,  274,  275,  263,  264,   -1,   -1,
  267,  268,   -1,   -1,   -1,   -1,   -1,  274,  275,   -1,
   -1,   -1,   -1,   -1,  259,  260,   -1,   -1,  263,  264,
  300,  301,  267,  268,  304,   -1,  306,   -1,  308,  274,
  275,  259,  260,  300,  301,  263,  264,  304,   -1,  306,
   -1,  308,   -1,   -1,   -1,   -1,  274,  275,   -1,  259,
  260,   -1,   -1,  263,  264,  300,  301,   -1,   -1,  304,
   -1,  306,   -1,  308,  274,  275,  259,  260,   -1,   -1,
  263,  264,  300,  301,   -1,   -1,  304,   -1,  306,   -1,
  308,  274,  275,   -1,  259,  260,   -1,   -1,  263,  264,
  300,  301,   -1,   -1,  304,   -1,  306,   -1,  308,  274,
  275,  259,  260,   -1,   -1,  263,  264,  300,  301,   -1,
   -1,  304,   -1,  306,   -1,  308,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  300,  301,   -1,   -1,  304,
   -1,  306,   -1,  308,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  300,  301,   -1,   -1,  304,  304,  306,   -1,
  308,   -1,  309,  310,  311,  312,  313,  314,  315,  316,
  317,  318,  309,  310,  311,  312,  313,  314,  315,  316,
  317,  318,
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
   -1,
};
#endif
#define YYFINAL 11
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 324
#define YYUNDFTOKEN 387
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
"assign_primary_expression","expression","primary_expression",
"suffix_expression","assignment_expression","equality_expression",
"relational_expression","additive_expression","multiplicative_expression",
"prefix_expression","argument_expression_list","statement_declaration_list",
"compound_statement","return_statement","break_statement","jump_statement",
"for_statement","do_while_statement","while_statement","iteration_statement",
"if_statement","selection_statement","expression_statement","statement",
"declaration","declaration_specifiers","type_specifier","scalar_decl",
"array_decl","func_decl","parameter_list","parameter_declaration",
"scalar_declarator","scalar_init_declarator","scalar_init_declarator_list",
"func_init_declarator_list","external_declaration","function_definition",
"trans_unit","func_init_declarator","func_declarator","func_direct_declarator",
"array_init_declarator_list","array_init_declarator","array_declarator",
"array_content","array_expression","LITERAL","$$1","$$2","delay_stmt",
"digitalwrite_stmt","if_start_stat","$$3","$$4","$$5","$$6","$$7","$$8","$$9",
"illegal-symbol",
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
"array_declarator : IDENTIFIER L_SQ_BRACKET LITERAL R_SQ_BRACKET",
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
"assignment_expression : assign_primary_expression ASSIGN assignment_expression",
"assignment_expression : IDENTIFIER L_SQ_BRACKET expression R_SQ_BRACKET ASSIGN assignment_expression",
"assign_primary_expression : MULTIPLY IDENTIFIER",
"assign_primary_expression : MULTIPLY L_BRACKET expression R_BRACKET",
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
"$$3 :",
"if_start_stat : IF $$3 L_BRACKET expression",
"if_statement : if_start_stat R_BRACKET compound_statement",
"$$4 :",
"if_statement : if_start_stat R_BRACKET compound_statement ELSE $$4 compound_statement",
"iteration_statement : while_statement",
"iteration_statement : do_while_statement",
"iteration_statement : for_statement",
"$$5 :",
"$$6 :",
"while_statement : WHILE $$5 L_BRACKET expression $$6 R_BRACKET statement",
"$$7 :",
"do_while_statement : DO $$7 statement WHILE L_BRACKET expression R_BRACKET SEMICOLON",
"$$8 :",
"$$9 :",
"for_statement : FOR L_BRACKET expression SEMICOLON $$8 expression SEMICOLON $$9 IDENTIFIER ASSIGN IDENTIFIER ADD INT_LITERAL R_BRACKET compound_statement",
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
#line 789 "parser.y"


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
#line 905 "y.tab.c"

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
#line 70 "parser.y"
	{  }
#line 1578 "y.tab.c"
break;
case 2:
#line 73 "parser.y"
	{  }
#line 1583 "y.tab.c"
break;
case 3:
#line 74 "parser.y"
	{ }
#line 1588 "y.tab.c"
break;
case 5:
#line 79 "parser.y"
	{ }
#line 1593 "y.tab.c"
break;
case 6:
#line 83 "parser.y"
	{
        cur_scope++;
        set_scope_and_offset_of_param(yystack.l_mark[-1].stringval);
        code_gen_func_header(yystack.l_mark[-3].stringval);
    }
#line 1602 "y.tab.c"
break;
case 7:
#line 88 "parser.y"
	{ 
        pop_up_symbol(cur_scope);
        cur_scope--;
        code_gen_at_end_of_function_body(yystack.l_mark[-5].stringval);
    }
#line 1611 "y.tab.c"
break;
case 8:
#line 93 "parser.y"
	{
        cur_scope++;
        code_gen_func_header(yystack.l_mark[-2].stringval);
    }
#line 1619 "y.tab.c"
break;
case 9:
#line 97 "parser.y"
	{ 
        pop_up_symbol(cur_scope);
        cur_scope--;
        code_gen_at_end_of_function_body(yystack.l_mark[-4].stringval);
    }
#line 1628 "y.tab.c"
break;
case 10:
#line 103 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1633 "y.tab.c"
break;
case 11:
#line 104 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1638 "y.tab.c"
break;
case 12:
#line 105 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1643 "y.tab.c"
break;
case 13:
#line 108 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval ;}
#line 1648 "y.tab.c"
break;
case 14:
#line 110 "parser.y"
	{ 

    }
#line 1655 "y.tab.c"
break;
case 15:
#line 114 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval ;}
#line 1660 "y.tab.c"
break;
case 16:
#line 116 "parser.y"
	{ 

    }
#line 1667 "y.tab.c"
break;
case 26:
#line 134 "parser.y"
	{
        yyval.intval=yystack.l_mark[0].intval;
        fprintf(f_asm, "    li t0, %d\n", yystack.l_mark[0].intval);
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
      }
#line 1677 "y.tab.c"
break;
case 27:
#line 140 "parser.y"
	{
        /* no need */
    }
#line 1684 "y.tab.c"
break;
case 28:
#line 143 "parser.y"
	{
        /* no need */
    }
#line 1691 "y.tab.c"
break;
case 29:
#line 146 "parser.y"
	{
        /* no need */
    }
#line 1698 "y.tab.c"
break;
case 30:
#line 151 "parser.y"
	{

}
#line 1705 "y.tab.c"
break;
case 31:
#line 157 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1710 "y.tab.c"
break;
case 32:
#line 158 "parser.y"
	{ 

    }
#line 1717 "y.tab.c"
break;
case 33:
#line 165 "parser.y"
	{ 
        yyval.stringval = install_symbol(yystack.l_mark[0].stringval);
        int index = look_up_symbol(yystack.l_mark[0].stringval);
        fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    sw zero, %d(s0)\n", table[index].offset * (-4) - 48);
    }
#line 1727 "y.tab.c"
break;
case 34:
#line 171 "parser.y"
	{ 
        yyval.stringval = install_symbol(yystack.l_mark[-2].stringval);
        int index = look_up_symbol(yystack.l_mark[-2].stringval);
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sw t0, %d(s0)\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 1739 "y.tab.c"
break;
case 35:
#line 183 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1744 "y.tab.c"
break;
case 36:
#line 184 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1749 "y.tab.c"
break;
case 37:
#line 190 "parser.y"
	{

}
#line 1756 "y.tab.c"
break;
case 38:
#line 196 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1761 "y.tab.c"
break;
case 39:
#line 197 "parser.y"
	{ 

    }
#line 1768 "y.tab.c"
break;
case 40:
#line 204 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1773 "y.tab.c"
break;
case 41:
#line 205 "parser.y"
	{ 

    }
#line 1780 "y.tab.c"
break;
case 42:
#line 212 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1785 "y.tab.c"
break;
case 43:
#line 213 "parser.y"
	{ 

    }
#line 1792 "y.tab.c"
break;
case 44:
#line 220 "parser.y"
	{
        fprintf(f_asm, ".global %s\n", yystack.l_mark[-2].stringval);
    }
#line 1799 "y.tab.c"
break;
case 45:
#line 223 "parser.y"
	{
        fprintf(f_asm, ".global %s\n", yystack.l_mark[-3].stringval);
    }
#line 1806 "y.tab.c"
break;
case 46:
#line 229 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1811 "y.tab.c"
break;
case 47:
#line 230 "parser.y"
	{ 

    }
#line 1818 "y.tab.c"
break;
case 48:
#line 236 "parser.y"
	{ 

    }
#line 1825 "y.tab.c"
break;
case 49:
#line 243 "parser.y"
	{

}
#line 1832 "y.tab.c"
break;
case 50:
#line 249 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1837 "y.tab.c"
break;
case 51:
#line 250 "parser.y"
	{ 

    }
#line 1844 "y.tab.c"
break;
case 52:
#line 257 "parser.y"
	{ 
        
    }
#line 1851 "y.tab.c"
break;
case 53:
#line 260 "parser.y"
	{ 
        /*no need*/
        /*$$ = install_symbol($1);*/
    }
#line 1859 "y.tab.c"
break;
case 54:
#line 267 "parser.y"
	{
        yyval.stringval = install_array_symbol(yystack.l_mark[-3].stringval,yystack.l_mark[-1].intval); 
        
    }
#line 1867 "y.tab.c"
break;
case 55:
#line 271 "parser.y"
	{
        /* no need */
    }
#line 1874 "y.tab.c"
break;
case 56:
#line 277 "parser.y"
	{ 

     }
#line 1881 "y.tab.c"
break;
case 57:
#line 280 "parser.y"
	{

    }
#line 1888 "y.tab.c"
break;
case 58:
#line 283 "parser.y"
	{

    }
#line 1895 "y.tab.c"
break;
case 59:
#line 286 "parser.y"
	{

    }
#line 1902 "y.tab.c"
break;
case 60:
#line 292 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 1907 "y.tab.c"
break;
case 61:
#line 293 "parser.y"
	{

    }
#line 1914 "y.tab.c"
break;
case 62:
#line 302 "parser.y"
	{
        fprintf(f_asm, "\n/*    ID*/\n");
        yyval.stringval=yystack.l_mark[0].stringval;
        int index = look_up_symbol(yystack.l_mark[0].stringval);
        if(table[index].type == T_POINTER)is_array=1;
        if(in_while==0){
            if (table[index].mode == LOCAL_MODE) {
                fprintf(f_asm, "    lw t0, %d(s0)\n", table[index].offset * (-4) - 48);
                fprintf(f_asm, "    sw t0, -4(sp)\n");
                fprintf(f_asm, "    addi sp, sp, -4\n");
            } else {
                /*fprintf(f_asm, "    lw t0, %d(sp)\n", table[index].offset * (-4) - 16);
                fprintf(f_asm, "    sw t0, -4(sp)\n");
                fprintf(f_asm, "    addi sp, sp, -4\n");*/
            }
        }else {
            fprintf(f_asm, "    lw t0, %d(s0)\n", table[index].offset * (-4) - 48);
            fprintf(f_asm, "    li t1, 0\n");
            fprintf(f_asm, "    beq t1, t0, L%d\n", cur_label);
        }

    }
#line 1940 "y.tab.c"
break;
case 63:
#line 324 "parser.y"
	{ 

    }
#line 1947 "y.tab.c"
break;
case 64:
#line 327 "parser.y"
	{ 
        
    }
#line 1954 "y.tab.c"
break;
case 65:
#line 330 "parser.y"
	{
        int index = look_up_symbol(yystack.l_mark[-3].stringval);
        fprintf(f_asm, "    li t0, %d\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    li t2, 4\n");
        fprintf(f_asm, "    mul t1, t1, t2\n");
        fprintf(f_asm, "    sub t0, t0, t1\n");
        fprintf(f_asm, "    add t0, s0, t0\n");
        fprintf(f_asm, "    lw t1, 0(t0)\n");
        fprintf(f_asm, "    sw t1, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 1971 "y.tab.c"
break;
case 66:
#line 347 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1976 "y.tab.c"
break;
case 67:
#line 348 "parser.y"
	{ 

    }
#line 1983 "y.tab.c"
break;
case 68:
#line 354 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1988 "y.tab.c"
break;
case 69:
#line 355 "parser.y"
	{ 

    }
#line 1995 "y.tab.c"
break;
case 70:
#line 358 "parser.y"
	{ 
    }
#line 2001 "y.tab.c"
break;
case 71:
#line 363 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2006 "y.tab.c"
break;
case 72:
#line 364 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sub t0, zero, t0\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        
    }
#line 2018 "y.tab.c"
break;
case 73:
#line 372 "parser.y"
	{ 
        /*section B*/
        /*int index = look_up_symbol($2);*/
        /*fprintf(f_asm, "    lw t0, %d(s0)\n", table[index].offset * (-4) - 48);*/
        fprintf(f_asm, "\n/*unary multiply*/\n");
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        /*section B*/
        fprintf(f_asm, "    add t0, t0, s0\n");
        fprintf(f_asm, "    lw t1, 0(t0)\n");
        fprintf(f_asm, "    sw t1, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        
        
    }
#line 2037 "y.tab.c"
break;
case 74:
#line 387 "parser.y"
	{ 
        int index = look_up_symbol(yystack.l_mark[0].stringval);
        fprintf(f_asm, "    li t0, %d\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    sw t0, -4(sp)\n"); 
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 2047 "y.tab.c"
break;
case 75:
#line 398 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2052 "y.tab.c"
break;
case 76:
#line 399 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    mul t0, t0, t1\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 2065 "y.tab.c"
break;
case 77:
#line 408 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    div t0, t1, t0\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 2078 "y.tab.c"
break;
case 78:
#line 420 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2083 "y.tab.c"
break;
case 79:
#line 421 "parser.y"
	{ 
        if(is_array){
            int index = look_up_symbol(yystack.l_mark[-2].stringval);
            yyval.stringval=yystack.l_mark[-2].stringval;
            if(dbg)printf("HELLO %s\n",table[index].name);
            fprintf(f_asm, "\n/*array add*/\n");
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t2, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    li t1, %d\n", table[index].offset * (-4) - 48);
            fprintf(f_asm, "    li t3, 4\n");
            fprintf(f_asm, "    mul t0, t0, t3\n");
            fprintf(f_asm, "    sub t0, t1, t0\n");
            fprintf(f_asm, "    sw t0, -4(sp)\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");
        }else {
            fprintf(f_asm, "\n/*normal add*/\n");
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t1, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    add t0, t0, t1\n");
            fprintf(f_asm, "    sw t0, -4(sp)\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");
        }
    }
#line 2114 "y.tab.c"
break;
case 80:
#line 448 "parser.y"
	{ 
        if(is_array) {
            int index = look_up_symbol(yystack.l_mark[-2].stringval);
            yyval.stringval=yystack.l_mark[-2].stringval;
            if(dbg)printf("HELLO %s\n",table[index].name);
            fprintf(f_asm, "\n/*array sub*/\n");
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t2, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    li t3, 4\n");
            fprintf(f_asm, "    mul t0, t0, t3\n");
            fprintf(f_asm, "    add t0, t2, t0\n");
            fprintf(f_asm, "    sw t0, -4(sp)\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");
        } else {
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t1, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    sub t0, t1, t0\n");
            fprintf(f_asm, "    sw t0, -4(sp)\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");
        }
    }
#line 2143 "y.tab.c"
break;
case 81:
#line 476 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2148 "y.tab.c"
break;
case 82:
#line 477 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        if(do_flag)fprintf(f_asm, "    bge t1, t0, L%d\n", cur_label-2);
        else fprintf(f_asm, "    bge t1, t0, L%d\n", cur_label);
    }
#line 2160 "y.tab.c"
break;
case 83:
#line 485 "parser.y"
	{ 

    }
#line 2167 "y.tab.c"
break;
case 84:
#line 488 "parser.y"
	{ 

    }
#line 2174 "y.tab.c"
break;
case 85:
#line 491 "parser.y"
	{ 

    }
#line 2181 "y.tab.c"
break;
case 86:
#line 497 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2186 "y.tab.c"
break;
case 87:
#line 498 "parser.y"
	{ 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    bne t1, t0, L%d\n", cur_label);
    }
#line 2197 "y.tab.c"
break;
case 88:
#line 505 "parser.y"
	{ 
        if (in_if == 1) {
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t1, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    beq t1, t0, L%d\n", cur_label);
        } else {
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t1, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    bne t1, t0, LXA\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");
            fprintf(f_asm, "    li t0, 0\n");
            fprintf(f_asm, "    sw t0, 0(sp)\n");
            fprintf(f_asm, "    beq zero, zero, EXITXA\n");
            fprintf(f_asm, "LXA:\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");
            fprintf(f_asm, "    li t0, 1\n");
            fprintf(f_asm, "    sw t0, 0(sp)\n");
            fprintf(f_asm, "EXITXA:\n");
        }
    }
#line 2225 "y.tab.c"
break;
case 89:
#line 533 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2230 "y.tab.c"
break;
case 90:
#line 534 "parser.y"
	{
        fprintf(f_asm, "\n/*    normal assign*/\n");
        yyval.stringval=yystack.l_mark[-2].stringval;
        int index = look_up_symbol(yystack.l_mark[-2].stringval);
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sw t0, %d(s0)\n", table[index].offset * (-4) - 48);

    }
#line 2243 "y.tab.c"
break;
case 91:
#line 543 "parser.y"
	{
        if(assignflag==0){
            int index = look_up_symbol(yystack.l_mark[-2].stringval);
            fprintf(f_asm, "\n/*    pointer assign  */\n");
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t1, %d(s0)\n", table[index].offset * (-4) - 48);
            fprintf(f_asm, "    add t1, s0, t1\n");
            fprintf(f_asm, "    sw t0, 0(t1)\n");
        }else if(assignflag==2){
            fprintf(f_asm, "\n/*    array pointer assign*/\n");
            fprintf(f_asm, "    lw t0, 0(sp)\n") ;
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t1, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    add t1, s0, t1\n");
            fprintf(f_asm, "    sw t0, 0(t1)\n");
        }
    }
#line 2266 "y.tab.c"
break;
case 92:
#line 562 "parser.y"
	{
        int index = look_up_symbol(yystack.l_mark[-5].stringval);
        fprintf(f_asm, "\n/*    array assign*/\n");
        fprintf(f_asm, "    lw t0, 0(sp)\n"); /**/
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    li t2, %d\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    li t3, 4\n");
        fprintf(f_asm, "    mul t1, t1, t3\n");
        fprintf(f_asm, "    sub t2, t2, t1\n");
        fprintf(f_asm, "    add t2, s0, t2\n");
        fprintf(f_asm, "    sw t0, 0(t2)\n");
    }
#line 2284 "y.tab.c"
break;
case 93:
#line 578 "parser.y"
	{
        assignflag=0;
        yyval.stringval = yystack.l_mark[0].stringval;
    }
#line 2292 "y.tab.c"
break;
case 94:
#line 582 "parser.y"
	{ 
        assignflag=2;
        yyval.stringval=yystack.l_mark[-1].stringval;
    }
#line 2300 "y.tab.c"
break;
case 95:
#line 591 "parser.y"
	{
        is_array = 0;
        yyval.stringval=yystack.l_mark[0].stringval;
    }
#line 2308 "y.tab.c"
break;
case 96:
#line 600 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2313 "y.tab.c"
break;
case 97:
#line 601 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2318 "y.tab.c"
break;
case 98:
#line 602 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2323 "y.tab.c"
break;
case 99:
#line 603 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2328 "y.tab.c"
break;
case 100:
#line 604 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2333 "y.tab.c"
break;
case 101:
#line 605 "parser.y"
	{yyval.stringval = yyval.stringval;}
#line 2338 "y.tab.c"
break;
case 102:
#line 606 "parser.y"
	{yyval.stringval = yyval.stringval;}
#line 2343 "y.tab.c"
break;
case 103:
#line 610 "parser.y"
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
#line 2364 "y.tab.c"
break;
case 104:
#line 630 "parser.y"
	{
        fprintf(f_asm, "    lw a0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sw ra, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    jal ra, delay\n");
        fprintf(f_asm, "    lw ra, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
    }
#line 2377 "y.tab.c"
break;
case 105:
#line 642 "parser.y"
	{ 

    }
#line 2384 "y.tab.c"
break;
case 106:
#line 648 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2389 "y.tab.c"
break;
case 107:
#line 651 "parser.y"
	{
        cur_scope++;
        cur_label++;
        in_if = 1;
    }
#line 2398 "y.tab.c"
break;
case 108:
#line 655 "parser.y"
	{
        push_label(cur_label);
        /*fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");*/
        in_if = 0;
    }
#line 2408 "y.tab.c"
break;
case 109:
#line 662 "parser.y"
	{ 
        int tmp_label = pop_label();
        fprintf(f_asm, "L%d:\n", tmp_label);
        pop_up_symbol(cur_scope);
        cur_scope--;
    }
#line 2418 "y.tab.c"
break;
case 110:
#line 668 "parser.y"
	{
        int tmp_label = pop_label();
        fprintf(f_asm, "    beq zero, zero, EXIT%d\n", tmp_label);
        fprintf(f_asm, "L%d:\n", tmp_label);
        push_label(tmp_label);
    }
#line 2428 "y.tab.c"
break;
case 111:
#line 673 "parser.y"
	{
        int tmp_label = pop_label();
        fprintf(f_asm, "EXIT%d:\n", tmp_label);
        pop_up_symbol(cur_scope--);
    }
#line 2437 "y.tab.c"
break;
case 112:
#line 682 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2442 "y.tab.c"
break;
case 113:
#line 683 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2447 "y.tab.c"
break;
case 114:
#line 684 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2452 "y.tab.c"
break;
case 115:
#line 688 "parser.y"
	{
        cur_label++;
        cur_scope++;
        fprintf(f_asm, "WHILE%d:\n", cur_label);
        push_label(cur_label);
        in_while = 1;
    }
#line 2463 "y.tab.c"
break;
case 116:
#line 694 "parser.y"
	{
        in_while = 0;
    }
#line 2470 "y.tab.c"
break;
case 117:
#line 696 "parser.y"
	{  
        int tmp_label = pop_label();
        fprintf(f_asm, "    beq zero, zero, WHILE%d\n", tmp_label);
        fprintf(f_asm, "L%d:\n", tmp_label);
        pop_up_symbol(cur_scope);
        cur_scope--;
    }
#line 2481 "y.tab.c"
break;
case 118:
#line 706 "parser.y"
	{
        cur_scope++;
        cur_label++;
        do_flag = 1;
        fprintf(f_asm, "DOWHILE%d:\n", cur_label);
        push_label(cur_label);  
    }
#line 2492 "y.tab.c"
break;
case 119:
#line 712 "parser.y"
	{ 
        int tmp_label = pop_label();
        fprintf(f_asm, "    beq zero, zero, DOWHILE%d\n", tmp_label);
        fprintf(f_asm, "L%d:\n", tmp_label);
        pop_up_symbol(cur_scope);
        cur_scope--;
        /*do_flag = 0;*/
    }
#line 2504 "y.tab.c"
break;
case 120:
#line 723 "parser.y"
	{
        cur_scope++;
        push_label(++cur_label);
        /*tricky*/
        in_for=1;
        fprintf(f_asm, "FOR%d:\n", cur_label);
    }
#line 2515 "y.tab.c"
break;
case 121:
#line 729 "parser.y"
	{
        in_for=0;
    }
#line 2522 "y.tab.c"
break;
case 122:
#line 731 "parser.y"
	{
        int tmp_label = pop_label();
        int index = look_up_symbol(yystack.l_mark[-12].stringval);
        
        /*printf("%d",table[index].scope);*/
        fprintf(f_asm, "    lw t0, %d(s0)\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    addi t0, t0, 1\n");
        fprintf(f_asm, "    sw t0, %d(s0)\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    beq zero, zero, FOR%d\n", tmp_label);
        fprintf(f_asm, "L%d:\n", tmp_label);
        pop_up_symbol(cur_scope);
        cur_scope--;
    }
#line 2539 "y.tab.c"
break;
case 123:
#line 747 "parser.y"
	{yyval.stringval =yystack.l_mark[0].stringval;}
#line 2544 "y.tab.c"
break;
case 124:
#line 748 "parser.y"
	{yyval.stringval =yystack.l_mark[0].stringval;}
#line 2549 "y.tab.c"
break;
case 125:
#line 752 "parser.y"
	{ 

    }
#line 2556 "y.tab.c"
break;
case 126:
#line 758 "parser.y"
	{ 

    }
#line 2563 "y.tab.c"
break;
case 127:
#line 761 "parser.y"
	{

    }
#line 2570 "y.tab.c"
break;
case 128:
#line 767 "parser.y"
	{ 

     }
#line 2577 "y.tab.c"
break;
case 129:
#line 770 "parser.y"
	{ 
       
     }
#line 2584 "y.tab.c"
break;
case 130:
#line 776 "parser.y"
	{ 

    }
#line 2591 "y.tab.c"
break;
case 131:
#line 779 "parser.y"
	{ 

    }
#line 2598 "y.tab.c"
break;
case 132:
#line 782 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2603 "y.tab.c"
break;
case 133:
#line 783 "parser.y"
	{ 

    }
#line 2610 "y.tab.c"
break;
#line 2612 "y.tab.c"
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
