%{
    #include <stdio.h>
    #include "y.tab.h"
%}
Space [ \t]
Macros "NULL"|"__COUNTER__"|"__LINE__"|"INT_MAX"|"INT_MIN"|"CHAR_MAX"|"CHAR_MIN"|"MAX"|"MIN"
%x  COMMENT

%%
"digitalWrite" {
    return DIGITALWRITE;
}

"HIGH" {
    yylval.intval = 1;
    return DVALUE;
}

"LOW" {
    yylval.intval = 0;
    return DVALUE;
}

"delay" {
    return DELAY;
}
"++" { return INC; }
"--" { return DEC; }
"<=" { return LESS_OR_EQUAL_THAN; }
">=" { return GREATER_OR_EQUAL_THAN; }
"<<" { return SHIFT_LEFT; }
">>" { return SHIFT_RIGHT; }
"==" { return EQUAL; }
"!=" { return NOT_EQUAL; }
"&&" { return AND; }
"||" { return OR; }
"+" {return ADD; }
"-" { return MINUS; }
"*" { return MULTIPLY; }
"/" { return DIVIDE; }
"%" { return MOD; }
"!" { return LOGICAL_NOT; }
"~" { return BITWISE_NOT; }
"<" { return LESS_THAN; }
">" { return GREATER_THAN; }
"&" { return AND_OP; }
"|" { return OR_OP; }
"^" { return XOR_OP; }
"=" { return ASSIGN; }

";" { return SEMICOLON; }
"," { return COMMA; }
":" { return COLON; }
"(" { return L_BRACKET; }
")" { return R_BRACKET; }
"[" { return L_SQ_BRACKET; }
"]" { return R_SQ_BRACKET; }
"{" { return L_PARENTHESIS; }
"}" { return R_PARENTHESIS; }

"if" { return IF; }
"else" { return ELSE; }
"switch" { return SWITCH; }
"case" { return CASE; }
"default" { return DEFAULT; }
"do" { return DO; }
"while" { return WHILE; }
"for" { return FOR; }
"return" { return RETURN; }
"break" { return BREAK;}
"continue" { return CONTINUE; } // no struct


"const" {yylval.stringval = strdup(yytext); return CONST;}
"int" {yylval.stringval = strdup(yytext); return INT;}
"char" {yylval.stringval = strdup(yytext); return CHAR;}
"float" {yylval.stringval = strdup(yytext); return FLOAT;}
"double" {yylval.stringval = strdup(yytext); return DOUBLE;}
"void" {yylval.stringval = strdup(yytext); return VOID;}
"signed" {yylval.stringval = strdup(yytext); return SIGNED;}
"unsigned" {yylval.stringval = strdup(yytext); return UNSIGNED;}
"long" {yylval.stringval = strdup(yytext); return LONG;}
"short" {yylval.stringval = strdup(yytext); return SHORT;}
"NULL" {yylval.stringval = strdup("0"); return NL;}

[a-zA-Z_][a-zA-Z0-9_]*  {yylval.stringval = strdup(yytext); return IDENTIFIER;}
[0-9]+ {yylval.intval = atoi(yytext); return INT_LITERAL;} // int
("."[0-9]+|[0-9]+"."|[0-9]+"."[0-9]+)  {yylval.dval = atof(yytext); return FLOAT_LITERAL;} // float
\'(\\.|[^'])\'  {yylval.stringval = strdup(yytext); return CHAR_LITERAL; } // char 
\"(\\.|[^"])*\" {yylval.stringval = strdup(yytext); return STRING_LITERAL; } // str

{Space} {}
\n  {}



"//".* {}
"/*"    {BEGIN COMMENT;}
<COMMENT>"*/"   {BEGIN 0;}
<COMMENT>.  {}
<COMMENT>\n {}


%%
