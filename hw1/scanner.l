%{
    #include <stdio.h>
    int lineCount=1;
    int pragma = 1;
    int pragma_token = 1;
    char* src = "";
    char* res;
    void print_src() {
        if (pragma) {
            printf("%d:%s\n", lineCount, src);
        }
        src = "";
        lineCount += 1;
    }
    void concat(const char* s) {
        res = malloc(strlen(src) + strlen(s) + 1);
        strcpy(res, src);
        strcat(res, s);
        src = res;
    }
%}
Keyword "for"|"do"|"while"|"break"|"continue"|"if"|"else"|"return"|"struct"|"switch"|"case"|"default"|"void"|"int"|"double"|"float"|"char"|"const"|"signed"|"unsigned"|"short"|"long"
Operators [+*\/%<>!=&|-]|[+-]{1,2}|"&&"|"||"|"=="|">="|"<="|"!="
Space [ \t]
Macros "NULL"|"__COUNTER__"|"__LINE__"|"INT_MAX"|"INT_MIN"|"CHAR_MAX"|"CHAR_MIN"|"MAX"|"MIN"
%x  COMMENT

%%
{Keyword}   {if (pragma_token) {printf("#key:%s\n", yytext);} concat(yytext);}
{Operators} {if (pragma_token) {printf("#op:%s\n", yytext);} concat(yytext);}
{Macros} {if(pragma_token) {printf("#macro:%s\n", yytext);} concat(yytext);}
{Space} {concat(yytext);}

[:;,.()\[\]\{\}]  {if (pragma_token) printf("#punc:%s\n", yytext); concat(yytext);}
[a-zA-Z_][a-zA-Z0-9_]*  {if (pragma_token) printf("#id:%s\n", yytext); concat(yytext);}
[-+]?[0-9]+ {if (pragma_token) printf("#integer:%s\n", yytext); concat(yytext);}
[-+]?("."[0-9]+|[0-9]+"."|[0-9]+"."[0-9]+)  {if (pragma_token) {printf("#float:%s\n", yytext);} concat(yytext);}

\n  {print_src();}

\'(\\.|[^'])\'  {if (pragma_token) {printf("#char:%s\n", yytext);} concat(yytext);}
\"(\\.|[^"])*\" {if (pragma_token) {printf("#string:%s\n", yytext);} concat(yytext);}

"//".* {concat(yytext);}
"/*"    {concat(yytext); BEGIN COMMENT;}
<COMMENT>"*/"   {concat(yytext); BEGIN 0;}
<COMMENT>.  {concat(yytext);}
<COMMENT>\n {print_src();}

#pragma{Space}+source{Space}+on {pragma = 1; concat(yytext);}
#pragma{Space}+source{Space}+off    {pragma = 0; concat(yytext);}
#pragma{Space}+token{Space}+on  {pragma_token = 1; concat(yytext);}
#pragma{Space}+token{Space}+off {pragma_token = 0; concat(yytext);}

%%
int main(int argc, char* argv[]){
    ++argv;
    --argc; /* skip over program name */
    if( 0 < argc ){
        yyin = fopen(argv[0], "r");
    }else yyin = stdin;
    
    yylex();
    return 0;
}