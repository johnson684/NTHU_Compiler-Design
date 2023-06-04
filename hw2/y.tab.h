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
#define UMINUS 280
#define UADD 281
#define UMULTI 282
#define UANDOP 283
#define INCPOST 284
#define DECPOST 285
#define IF 286
#define ELSE 287
#define SWITCH 288
#define CASE 289
#define DEFAULT 290
#define WHILE 291
#define DO 292
#define FOR 293
#define RETURN 294
#define BREAK 295
#define CONTINUE 296
#define SEMICOLON 297
#define COMMA 298
#define COLON 299
#define L_BRACKET 300
#define R_BRACKET 301
#define L_SQ_BRACKET 302
#define R_SQ_BRACKET 303
#define L_PARENTHESIS 304
#define R_PARENTHESIS 305
#define INT 306
#define CHAR 307
#define FLOAT 308
#define DOUBLE 309
#define VOID 310
#define SIGNED 311
#define UNSIGNED 312
#define LONG 313
#define SHORT 314
#define CONST 315
#define IDENTIFIER 316
#define CHAR_LITERAL 317
#define STRING_LITERAL 318
#define NL 319
#define INT_LITERAL 320
#define FLOAT_LITERAL 321
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
