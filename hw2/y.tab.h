#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#define IF 280
#define ELSE 281
#define SWITCH 282
#define CASE 283
#define DEFAULT 284
#define WHILE 285
#define DO 286
#define FOR 287
#define RETURN 288
#define BREAK 289
#define CONTINUE 290
#define SEMICOLON 291
#define COMMA 292
#define COLON 293
#define L_BRACKET 294
#define R_BRACKET 295
#define L_SQ_BRACKET 296
#define R_SQ_BRACKET 297
#define L_PARENTHESIS 298
#define R_PARENTHESIS 299
#define INT 300
#define CHAR 301
#define FLOAT 302
#define DOUBLE 303
#define VOID 304
#define SIGNED 305
#define UNSIGNED 306
#define LONG 307
#define SHORT 308
#define CONST 309
#define IDENTIFIER 310
#define CHAR_LITERAL 311
#define STRING_LITERAL 312
#define INT_LITERAL 313
#define FLOAT_LITERAL 314
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
  int intval;
  double dval;
  char* stringval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
