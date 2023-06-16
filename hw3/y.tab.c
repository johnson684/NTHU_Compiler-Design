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
    4,    4,    4,    1,   23,   23,   23,   23,   23,   23,
   23,   51,   50,   22,   21,   20,   20,   19,   19,   19,
   18,   17,   16,   15,   15,   14,   13,   13,   12,   12,
   11,   11,   11,   11,
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
    3,    4,    6,    1,    1,    1,    1,    1,    1,    1,
    1,    7,    5,    2,    1,    5,    7,    1,    1,    1,
    5,    7,    9,    1,    1,    2,    2,    3,    2,    3,
    1,    2,    1,    2,
};
static const YYINT yydefred[] = {                         0,
   17,   18,   19,   20,   21,   22,   23,   24,   25,    0,
    0,    4,    0,    0,   10,   11,   12,    2,    5,    0,
   16,    0,    0,    0,    0,    0,    0,    0,    0,   42,
    0,    0,    0,   14,    3,    0,   43,    0,    0,    0,
    0,   30,   37,    0,    0,   49,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   28,
   29,   26,   27,    0,   68,    0,   94,    0,    0,    0,
    0,   75,   63,   34,    0,   35,   32,    0,    0,   39,
   41,    0,   51,    0,   53,    0,   44,    0,    0,   48,
    0,    0,    0,    0,   72,    0,   73,   74,    0,    0,
    0,   54,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   36,   60,    0,    0,   55,   45,
    0,    9,    0,   47,    0,    0,   64,   91,    0,   69,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   76,   77,   78,    0,   59,    0,   56,    0,    0,    0,
    0,    0,    0,    0,    0,  119,    0,    0,   99,  115,
  114,   98,  110,  109,  108,   97,  105,   96,   95,    0,
    0,    0,  100,  101,    7,    0,   92,    0,    0,   70,
    0,    0,   61,    0,    0,    0,    0,    0,    0,  117,
    0,  116,  104,  120,  122,  124,    0,   65,    0,   67,
   57,   58,    0,    0,    0,    0,    0,    0,  118,   93,
    0,    0,    0,    0,    0,    0,    0,  103,    0,  111,
    0,    0,    0,    0,    0,    0,  102,  107,  112,    0,
    0,  113,
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
  307,  338,  374,  356,  305,  279,  304,  330,  327,  304,
  330,  336,  332,  332,  333,  333,  333,  333,  334,  334,
  335,  335,  335,  301,  308,  301,  308,  286,  287,  289,
  294,  295,  296,  297,  298,  308,  327,  337,  338,  339,
  340,  341,  342,  343,  344,  345,  346,  347,  348,  349,
  350,  351,  376,  377,  338,  327,  330,  306,  301,  304,
  371,  372,  327,  303,  303,  303,  303,  349,  303,  300,
  327,  300,  300,  308,  337,  337,  319,  306,  279,  336,
  308,  308,  323,  327,  327,  327,  294,  327,  300,  330,
  301,  304,  304,  304,  303,  300,  288,  300,  338,  349,
  327,  327,  304,  290,  304,  300,  300,  338,  300,  327,
  304,  349,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         11,
  157,   65,   66,   67,   68,   69,   70,   71,   72,  132,
  158,  159,  160,  161,  162,  163,  164,  165,  166,  167,
  168,  169,  170,  171,   52,   14,   15,   16,   17,   53,
   54,   24,   25,   26,   27,   18,   19,   20,   28,   29,
   30,   31,   32,   33,   85,  118,   73,  123,   89,  173,
  174,
};
static const YYINT yysindex[] = {                       383,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  383,
    0,    0, -258,  383,    0,    0,    0,    0,    0,  383,
    0, -286, -282, -229, -243, -236, -231, -235, -197,    0,
 -213, -206, -262,    0,    0, -204,    0,  144,   71,   71,
 -241,    0,    0, -238,   71,    0, -217, -203,   71,  373,
    0, -241, -198, -156,   77,  101, -170,   71, -261,    0,
    0,    0,    0, -149,    0, -138,    0, -152, -146, -137,
 -145,    0,    0,    0, -165,    0,    0, -150, -204,    0,
    0, -134,    0, -244,    0, -139,    0, -130, -132,    0,
    0,  383,   77, -120,    0, -253,    0,    0, -104,   71,
   71,    0, -230,   77,   77,   77,   77,   77,   77,   77,
   77,   77,   77,   77,    0,    0, -272, -267,    0,    0,
 -106,    0, -132,    0,   71,   71,    0,    0,  -90,    0,
  -80,  -82, -146, -146, -137, -137, -137, -137, -145, -145,
    0,    0,    0, -244,    0,   71,    0,  -79,  -78,  -77,
  -75,   65,  -74, -168,  -70,    0,  -69,  -85,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
    8, -234,    0,    0,    0,  -73,    0,  -47,   71,    0,
  -66, -248,    0,  -89,   71,   71,   71,  -50,   71,    0,
  -48,    0,    0,    0,    0,    0, -249,    0,   71,    0,
    0,    0,  -51,  -53,  -31,  -26,  -46,  -21,    0,    0,
   -7,  -20, -132,   65,   71,   71,  -22,    0,  -37,    0,
  -19,  -17,  -14, -132,  -11,   71,    0,    0,    0,  -16,
   65,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -227,
    0,    0,    0, -222,    0,    0,    0,    0,    0,  287,
    0,    0, -183, -179,  -10,    0,    0,   -9, -167,    0,
    0,   -1, -164,    0,    0, -181,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -252,    0,    0,   -3,    0,    0,    0,    0,  143,    0,
    0,    0,    0,    0,    0,  217,    0, -140, -122,  302,
  230,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -191,    0,    0,  143,    0,  143,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,    0,  -65,   -8,  315,  337,  354,  372,  252,  280,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    4,    0,    0,    0,    0,    0,    0,  167,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -183,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -49,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
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
    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  -39,    0,    0,  -96,    0,   35,   87,   33,  -42,  129,
  -12,  -86,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -147,   20,    2,    0,    0,    0,    0,  -35,
    0,  258,    0,  272,  270,  296,    0,    0,    0,    0,
  -13,  283,    0,    0,  -76,  191,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 701
static const YYINT yytable[] = {                         64,
   74,   13,  122,  128,  188,   81,  131,  117,   37,   86,
   22,   21,   95,   97,   88,   34,   48,  100,   99,   12,
   38,   13,   39,   55,   56,  126,   44,   75,  144,  177,
   78,   57,   36,  146,   22,  145,  175,   55,   56,   12,
  147,   15,   49,  101,  116,   57,   13,   44,   44,   40,
   97,  125,  146,   50,    8,   39,  124,   41,   58,  202,
   23,  129,   84,   42,   37,   44,  220,  181,   43,  141,
  142,  143,   58,  130,   59,   60,   61,   76,   62,   63,
   79,   45,  131,  232,  197,  176,   46,   45,   59,   60,
   61,   15,   62,   63,   47,   35,   13,   36,   50,   55,
   56,   82,  210,   84,  116,   91,  183,   57,   45,   45,
  104,  105,  106,  107,  191,    6,   35,   35,   36,   36,
   33,   33,  172,  112,  113,  114,  219,  108,  109,  110,
  111,  190,   40,   40,   58,   52,   52,  228,  133,  134,
   87,   87,  139,  140,   92,  204,  205,  206,   98,  208,
   59,   60,   61,  115,   62,   63,  102,  195,  196,   90,
   90,   55,   56,   90,  103,   90,  119,   90,   79,   57,
   39,  172,  172,  120,  121,  221,  222,   87,   87,  148,
  149,   87,  150,   87,  125,   87,  230,  151,  152,  153,
  154,  155,  135,  136,  137,  138,   58,   88,   88,  127,
  121,  156,    1,    2,    3,    4,    5,    6,    7,    8,
    9,   10,   59,   60,   61,  178,   62,   63,  106,  106,
  179,  180,  194,  184,  185,  186,  106,  187,  189,  192,
  193,  199,  198,  203,   88,   88,  106,  106,   88,  106,
   88,  201,   88,  207,  106,  106,  106,  106,  106,  211,
  212,  209,  224,  106,   89,   89,  215,  106,  106,  106,
  106,  106,  106,  106,  106,  106,  106,  106,  106,  106,
  106,  106,  213,  106,  106,   55,   56,  214,  216,  218,
  217,  223,  226,   57,  225,  227,    1,  231,  229,   31,
   38,   89,   89,  148,  149,   89,  150,   89,   50,   89,
   46,  151,  152,  153,  154,  155,   66,  200,  121,   90,
   58,  123,   77,   80,  121,   35,    1,    2,    3,    4,
    5,    6,    7,    8,    9,   10,   59,   60,   61,   83,
   62,   63,   55,   56,  182,    0,    0,    0,   55,   56,
   57,    0,    0,    0,   55,   93,   57,    0,    0,    0,
  148,  149,   57,  150,    0,    0,    0,    0,  151,  152,
  153,  154,  155,    0,    0,    0,    0,   58,   55,   93,
    0,  121,    0,   58,    0,    0,   57,    0,    0,   58,
    0,    0,    0,   59,   60,   61,    0,   62,   63,   59,
   60,   61,    0,   62,   63,   94,   60,   61,    0,   62,
   63,   62,   62,   58,    0,   62,   62,    0,    0,   62,
   62,   62,   62,   62,    0,    0,   62,   62,    0,   96,
   60,   61,    0,   62,   63,   65,   65,    0,    0,   65,
   65,    0,    0,   65,   65,   65,   65,   65,    0,    0,
   65,   65,   62,   62,    0,   62,   62,   51,   62,    0,
   62,    0,    1,    2,    3,    4,    5,    6,    7,    8,
    9,   10,    0,    0,    0,    0,   65,   65,    0,   65,
   65,    0,   65,    0,   65,   71,   71,    0,    0,   71,
   71,    0,    0,   71,   71,   71,   71,   71,   79,   79,
   71,   71,   79,   79,    0,    0,   79,   79,    0,    0,
    0,    0,    0,   79,   79,    0,    0,    0,    0,    0,
   80,   80,    0,    0,   80,   80,   71,   71,   80,   80,
   71,    0,   71,    0,   71,   80,   80,    0,    0,   79,
   79,    0,    0,   79,    0,   79,    0,   79,   81,   81,
    0,    0,   81,   81,    0,    0,   81,   81,    0,    0,
    0,   80,   80,   81,   81,   80,    0,   80,    0,   80,
   82,   82,    0,    0,   82,   82,    0,    0,    0,    0,
    0,    0,    0,   84,   84,   82,   82,   84,   84,   81,
   81,    0,    0,   81,    0,   81,    0,   81,   84,   84,
    0,    0,    0,    0,    0,   86,   86,    0,    0,   86,
   86,   82,   82,    0,    0,   82,    0,   82,    0,   82,
   86,   86,   83,   83,   84,   84,   83,   83,   84,    0,
   84,    0,   84,    0,    0,    0,    0,   83,   83,    0,
   85,   85,    0,    0,   85,   85,   86,   86,    0,    0,
   86,    0,   86,    0,   86,   85,   85,    0,    0,    0,
    0,    0,    0,   83,   83,    0,    0,   83,    0,   83,
    0,   83,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   85,   85,    0,    0,   85,   87,   85,    0,   85,
    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,
   10,    1,    2,    3,    4,    5,    6,    7,    8,    9,
   10,
};
static const YYINT yycheck[] = {                         39,
   40,    0,   89,  100,  152,   45,  103,   84,   22,   49,
  269,   10,   55,   56,   50,   14,  279,  279,   58,    0,
  303,   20,  305,  268,  269,  279,  279,  269,  301,  126,
  269,  276,  319,  301,  269,  308,  123,  268,  269,   20,
  308,  269,  305,  305,   84,  276,  269,  300,  301,  279,
   93,  305,  301,  303,  307,  305,   92,  301,  303,  308,
  319,  101,  307,  300,   78,  301,  214,  144,  300,  112,
  113,  114,  303,  304,  319,  320,  321,  319,  323,  324,
  319,  279,  179,  231,  319,  125,  300,  279,  319,  320,
  321,  319,  323,  324,  301,  279,  319,  279,  303,  268,
  269,  319,  199,  307,  144,  304,  146,  276,  300,  301,
  263,  264,  259,  260,  154,  307,  300,  301,  300,  301,
  300,  301,  121,  269,  270,  271,  213,  274,  275,  267,
  268,  300,  300,  301,  303,  300,  301,  224,  104,  105,
  263,  264,  110,  111,  301,  185,  186,  187,  319,  189,
  319,  320,  321,  319,  323,  324,  306,  170,  171,  300,
  301,  268,  269,  304,  303,  306,  306,  308,  319,  276,
  305,  170,  171,  304,  307,  215,  216,  300,  301,  286,
  287,  304,  289,  306,  305,  308,  226,  294,  295,  296,
  297,  298,  106,  107,  108,  109,  303,  263,  264,  304,
  307,  308,  309,  310,  311,  312,  313,  314,  315,  316,
  317,  318,  319,  320,  321,  306,  323,  324,  268,  269,
  301,  304,  308,  303,  303,  303,  276,  303,  303,  300,
  300,  279,  306,  323,  300,  301,  286,  287,  304,  289,
  306,  308,  308,  294,  294,  295,  296,  297,  298,  301,
  304,  300,  290,  303,  263,  264,  303,  307,  308,  309,
  310,  311,  312,  313,  314,  315,  316,  317,  318,  319,
  320,  321,  304,  323,  324,  268,  269,  304,  300,  300,
  288,  304,  300,  276,  304,  300,    0,  304,  300,  300,
  300,  300,  301,  286,  287,  304,  289,  306,  300,  308,
  304,  294,  295,  296,  297,  298,  304,  179,  308,   52,
  303,  308,   41,   44,  307,   20,  309,  310,  311,  312,
  313,  314,  315,  316,  317,  318,  319,  320,  321,   47,
  323,  324,  268,  269,  144,   -1,   -1,   -1,  268,  269,
  276,   -1,   -1,   -1,  268,  269,  276,   -1,   -1,   -1,
  286,  287,  276,  289,   -1,   -1,   -1,   -1,  294,  295,
  296,  297,  298,   -1,   -1,   -1,   -1,  303,  268,  269,
   -1,  307,   -1,  303,   -1,   -1,  276,   -1,   -1,  303,
   -1,   -1,   -1,  319,  320,  321,   -1,  323,  324,  319,
  320,  321,   -1,  323,  324,  319,  320,  321,   -1,  323,
  324,  259,  260,  303,   -1,  263,  264,   -1,   -1,  267,
  268,  269,  270,  271,   -1,   -1,  274,  275,   -1,  319,
  320,  321,   -1,  323,  324,  259,  260,   -1,   -1,  263,
  264,   -1,   -1,  267,  268,  269,  270,  271,   -1,   -1,
  274,  275,  300,  301,   -1,  303,  304,  304,  306,   -1,
  308,   -1,  309,  310,  311,  312,  313,  314,  315,  316,
  317,  318,   -1,   -1,   -1,   -1,  300,  301,   -1,  303,
  304,   -1,  306,   -1,  308,  259,  260,   -1,   -1,  263,
  264,   -1,   -1,  267,  268,  269,  270,  271,  259,  260,
  274,  275,  263,  264,   -1,   -1,  267,  268,   -1,   -1,
   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,   -1,   -1,
  259,  260,   -1,   -1,  263,  264,  300,  301,  267,  268,
  304,   -1,  306,   -1,  308,  274,  275,   -1,   -1,  300,
  301,   -1,   -1,  304,   -1,  306,   -1,  308,  259,  260,
   -1,   -1,  263,  264,   -1,   -1,  267,  268,   -1,   -1,
   -1,  300,  301,  274,  275,  304,   -1,  306,   -1,  308,
  259,  260,   -1,   -1,  263,  264,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  259,  260,  274,  275,  263,  264,  300,
  301,   -1,   -1,  304,   -1,  306,   -1,  308,  274,  275,
   -1,   -1,   -1,   -1,   -1,  259,  260,   -1,   -1,  263,
  264,  300,  301,   -1,   -1,  304,   -1,  306,   -1,  308,
  274,  275,  259,  260,  300,  301,  263,  264,  304,   -1,
  306,   -1,  308,   -1,   -1,   -1,   -1,  274,  275,   -1,
  259,  260,   -1,   -1,  263,  264,  300,  301,   -1,   -1,
  304,   -1,  306,   -1,  308,  274,  275,   -1,   -1,   -1,
   -1,   -1,   -1,  300,  301,   -1,   -1,  304,   -1,  306,
   -1,  308,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  300,  301,   -1,   -1,  304,  304,  306,   -1,  308,
   -1,  309,  310,  311,  312,  313,  314,  315,  316,  317,
  318,  309,  310,  311,  312,  313,  314,  315,  316,  317,
  318,
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
"assignment_expression : IDENTIFIER L_SQ_BRACKET expression R_SQ_BRACKET ASSIGN assignment_expression",
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
#line 588 "parser.y"


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
#line 869 "y.tab.c"

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
#line 1542 "y.tab.c"
break;
case 2:
#line 66 "parser.y"
	{  }
#line 1547 "y.tab.c"
break;
case 3:
#line 67 "parser.y"
	{ }
#line 1552 "y.tab.c"
break;
case 5:
#line 72 "parser.y"
	{ }
#line 1557 "y.tab.c"
break;
case 6:
#line 76 "parser.y"
	{
        cur_scope++;
        set_scope_and_offset_of_param(yystack.l_mark[-1].stringval);
        code_gen_func_header(yystack.l_mark[-3].stringval);
    }
#line 1566 "y.tab.c"
break;
case 7:
#line 81 "parser.y"
	{ 
        pop_up_symbol(cur_scope);
        cur_scope--;
        code_gen_at_end_of_function_body(yystack.l_mark[-5].stringval);
    }
#line 1575 "y.tab.c"
break;
case 8:
#line 86 "parser.y"
	{
        cur_scope++;
        code_gen_func_header(yystack.l_mark[-2].stringval);
    }
#line 1583 "y.tab.c"
break;
case 9:
#line 90 "parser.y"
	{ 
        pop_up_symbol(cur_scope);
        cur_scope--;
        code_gen_at_end_of_function_body(yystack.l_mark[-4].stringval);
    }
#line 1592 "y.tab.c"
break;
case 10:
#line 96 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1597 "y.tab.c"
break;
case 11:
#line 97 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1602 "y.tab.c"
break;
case 12:
#line 98 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1607 "y.tab.c"
break;
case 13:
#line 101 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval ;}
#line 1612 "y.tab.c"
break;
case 14:
#line 103 "parser.y"
	{ 

    }
#line 1619 "y.tab.c"
break;
case 15:
#line 107 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval ;}
#line 1624 "y.tab.c"
break;
case 16:
#line 109 "parser.y"
	{ 

    }
#line 1631 "y.tab.c"
break;
case 26:
#line 127 "parser.y"
	{
        fprintf(f_asm, "    li t0, %d\n", yystack.l_mark[0].intval);
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
      }
#line 1640 "y.tab.c"
break;
case 27:
#line 132 "parser.y"
	{
        /* no need */
    }
#line 1647 "y.tab.c"
break;
case 28:
#line 135 "parser.y"
	{
        /* no need */
    }
#line 1654 "y.tab.c"
break;
case 29:
#line 138 "parser.y"
	{
        /* no need */
    }
#line 1661 "y.tab.c"
break;
case 30:
#line 143 "parser.y"
	{

}
#line 1668 "y.tab.c"
break;
case 31:
#line 149 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1673 "y.tab.c"
break;
case 32:
#line 150 "parser.y"
	{ 

    }
#line 1680 "y.tab.c"
break;
case 33:
#line 157 "parser.y"
	{ 
        yyval.stringval = install_symbol(yystack.l_mark[0].stringval);
        /*fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    sw zero, 0(sp)\n");*/
    }
#line 1689 "y.tab.c"
break;
case 34:
#line 162 "parser.y"
	{ 
        yyval.stringval = install_symbol(yystack.l_mark[-2].stringval);
    }
#line 1696 "y.tab.c"
break;
case 35:
#line 169 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1701 "y.tab.c"
break;
case 36:
#line 170 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1706 "y.tab.c"
break;
case 37:
#line 176 "parser.y"
	{

}
#line 1713 "y.tab.c"
break;
case 38:
#line 182 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1718 "y.tab.c"
break;
case 39:
#line 183 "parser.y"
	{ 

    }
#line 1725 "y.tab.c"
break;
case 40:
#line 190 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1730 "y.tab.c"
break;
case 41:
#line 191 "parser.y"
	{ 

    }
#line 1737 "y.tab.c"
break;
case 42:
#line 198 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1742 "y.tab.c"
break;
case 43:
#line 199 "parser.y"
	{ 

    }
#line 1749 "y.tab.c"
break;
case 44:
#line 206 "parser.y"
	{
        fprintf(f_asm, ".global %s\n", yystack.l_mark[-2].stringval);
    }
#line 1756 "y.tab.c"
break;
case 45:
#line 209 "parser.y"
	{
        fprintf(f_asm, ".global %s\n", yystack.l_mark[-3].stringval);
    }
#line 1763 "y.tab.c"
break;
case 46:
#line 215 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1768 "y.tab.c"
break;
case 47:
#line 216 "parser.y"
	{ 

    }
#line 1775 "y.tab.c"
break;
case 48:
#line 222 "parser.y"
	{ 

    }
#line 1782 "y.tab.c"
break;
case 49:
#line 229 "parser.y"
	{

}
#line 1789 "y.tab.c"
break;
case 50:
#line 235 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1794 "y.tab.c"
break;
case 51:
#line 236 "parser.y"
	{ 

    }
#line 1801 "y.tab.c"
break;
case 52:
#line 243 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval; }
#line 1806 "y.tab.c"
break;
case 53:
#line 244 "parser.y"
	{ 

    }
#line 1813 "y.tab.c"
break;
case 54:
#line 250 "parser.y"
	{

    }
#line 1820 "y.tab.c"
break;
case 55:
#line 253 "parser.y"
	{
        
    }
#line 1827 "y.tab.c"
break;
case 56:
#line 259 "parser.y"
	{ 

     }
#line 1834 "y.tab.c"
break;
case 57:
#line 262 "parser.y"
	{

    }
#line 1841 "y.tab.c"
break;
case 58:
#line 265 "parser.y"
	{

    }
#line 1848 "y.tab.c"
break;
case 59:
#line 268 "parser.y"
	{

    }
#line 1855 "y.tab.c"
break;
case 60:
#line 274 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 1860 "y.tab.c"
break;
case 61:
#line 275 "parser.y"
	{

    }
#line 1867 "y.tab.c"
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
#line 1883 "y.tab.c"
break;
case 63:
#line 296 "parser.y"
	{ 

    }
#line 1890 "y.tab.c"
break;
case 64:
#line 299 "parser.y"
	{ 

    }
#line 1897 "y.tab.c"
break;
case 65:
#line 302 "parser.y"
	{

    }
#line 1904 "y.tab.c"
break;
case 66:
#line 309 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1909 "y.tab.c"
break;
case 67:
#line 310 "parser.y"
	{ 

    }
#line 1916 "y.tab.c"
break;
case 68:
#line 316 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1921 "y.tab.c"
break;
case 69:
#line 317 "parser.y"
	{ 

    }
#line 1928 "y.tab.c"
break;
case 70:
#line 320 "parser.y"
	{ 
    }
#line 1934 "y.tab.c"
break;
case 71:
#line 325 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1939 "y.tab.c"
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
#line 1951 "y.tab.c"
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
#line 1965 "y.tab.c"
break;
case 74:
#line 344 "parser.y"
	{ 
        int index = look_up_symbol(yystack.l_mark[0].stringval);
        fprintf(f_asm, "    li t0, %d\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    sw t0, -4(sp)\n"); /* 0?*/
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
#line 1975 "y.tab.c"
break;
case 75:
#line 355 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 1980 "y.tab.c"
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
#line 1993 "y.tab.c"
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
#line 2006 "y.tab.c"
break;
case 78:
#line 374 "parser.y"
	{ 

    }
#line 2013 "y.tab.c"
break;
case 79:
#line 380 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2018 "y.tab.c"
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
#line 2031 "y.tab.c"
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
#line 2044 "y.tab.c"
break;
case 82:
#line 402 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2049 "y.tab.c"
break;
case 83:
#line 403 "parser.y"
	{ 

    }
#line 2056 "y.tab.c"
break;
case 84:
#line 406 "parser.y"
	{ 

    }
#line 2063 "y.tab.c"
break;
case 85:
#line 409 "parser.y"
	{ 

    }
#line 2070 "y.tab.c"
break;
case 86:
#line 412 "parser.y"
	{ 

    }
#line 2077 "y.tab.c"
break;
case 87:
#line 418 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2082 "y.tab.c"
break;
case 88:
#line 419 "parser.y"
	{ 

    }
#line 2089 "y.tab.c"
break;
case 89:
#line 422 "parser.y"
	{ 

    }
#line 2096 "y.tab.c"
break;
case 90:
#line 429 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2101 "y.tab.c"
break;
case 91:
#line 430 "parser.y"
	{
        int index = look_up_symbol(yystack.l_mark[-2].stringval);
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    sw t0, %d(s0)\n", table[index].offset * (-4) - 48);
    }
#line 2110 "y.tab.c"
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
#line 2121 "y.tab.c"
break;
case 93:
#line 442 "parser.y"
	{
        int index = look_up_symbol(yystack.l_mark[-5].stringval);
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    sw t0, %d(s0)\n", table[index].offset * (-4) - 48);
    }
#line 2130 "y.tab.c"
break;
case 94:
#line 452 "parser.y"
	{

    }
#line 2137 "y.tab.c"
break;
case 95:
#line 460 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2142 "y.tab.c"
break;
case 96:
#line 461 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2147 "y.tab.c"
break;
case 97:
#line 462 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2152 "y.tab.c"
break;
case 98:
#line 463 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2157 "y.tab.c"
break;
case 99:
#line 464 "parser.y"
	{yyval.stringval = yystack.l_mark[0].stringval;}
#line 2162 "y.tab.c"
break;
case 100:
#line 465 "parser.y"
	{yyval.stringval = yyval.stringval;}
#line 2167 "y.tab.c"
break;
case 101:
#line 466 "parser.y"
	{yyval.stringval = yyval.stringval;}
#line 2172 "y.tab.c"
break;
case 102:
#line 470 "parser.y"
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
#line 2193 "y.tab.c"
break;
case 103:
#line 490 "parser.y"
	{
        fprintf(f_asm, "    lw a0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sw ra, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    jal ra, delay\n");
        fprintf(f_asm, "    lw ra, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
    }
#line 2206 "y.tab.c"
break;
case 104:
#line 502 "parser.y"
	{ 

    }
#line 2213 "y.tab.c"
break;
case 105:
#line 508 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2218 "y.tab.c"
break;
case 106:
#line 512 "parser.y"
	{ 

    }
#line 2225 "y.tab.c"
break;
case 107:
#line 515 "parser.y"
	{
        
    }
#line 2232 "y.tab.c"
break;
case 108:
#line 522 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2237 "y.tab.c"
break;
case 109:
#line 523 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2242 "y.tab.c"
break;
case 110:
#line 524 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2247 "y.tab.c"
break;
case 111:
#line 528 "parser.y"
	{  

    }
#line 2254 "y.tab.c"
break;
case 112:
#line 534 "parser.y"
	{ 

    }
#line 2261 "y.tab.c"
break;
case 113:
#line 540 "parser.y"
	{
        
    }
#line 2268 "y.tab.c"
break;
case 114:
#line 546 "parser.y"
	{yyval.stringval =yystack.l_mark[0].stringval;}
#line 2273 "y.tab.c"
break;
case 115:
#line 547 "parser.y"
	{yyval.stringval =yystack.l_mark[0].stringval;}
#line 2278 "y.tab.c"
break;
case 116:
#line 551 "parser.y"
	{ 

    }
#line 2285 "y.tab.c"
break;
case 117:
#line 557 "parser.y"
	{ 

    }
#line 2292 "y.tab.c"
break;
case 118:
#line 560 "parser.y"
	{

    }
#line 2299 "y.tab.c"
break;
case 119:
#line 566 "parser.y"
	{ 

     }
#line 2306 "y.tab.c"
break;
case 120:
#line 569 "parser.y"
	{ 
       
     }
#line 2313 "y.tab.c"
break;
case 121:
#line 575 "parser.y"
	{ 

    }
#line 2320 "y.tab.c"
break;
case 122:
#line 578 "parser.y"
	{ 

    }
#line 2327 "y.tab.c"
break;
case 123:
#line 581 "parser.y"
	{ yyval.stringval = yystack.l_mark[0].stringval;}
#line 2332 "y.tab.c"
break;
case 124:
#line 582 "parser.y"
	{ 

    }
#line 2339 "y.tab.c"
break;
#line 2341 "y.tab.c"
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
