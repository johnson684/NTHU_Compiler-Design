%{
    #include <stdio.h>
    #include "code.h"
    int yylex();
    int dbg=1;
    int lineNo = 1;
    int in_if = 0;
    int in_while = 0;
    int in_for = 0;
    int is_array = 0;
    extern FILE* f_asm;
    int arg_cnt;
    int assignflag = 0;
%}

%union {
  int intval;
  double dval;
  char* stringval;
}
/* op */
%token<stringval> INC DEC LESS_OR_EQUAL_THAN GREATER_OR_EQUAL_THAN SHIFT_LEFT SHIFT_RIGHT EQUAL NOT_EQUAL AND OR ADD MINUS 
%token<stringval> MULTIPLY DIVIDE MOD LOGICAL_NOT BITWISE_NOT LESS_THAN GREATER_THAN AND_OP OR_OP XOR_OP ASSIGN 
%right ASSIGN
%left OR
%left AND
%left OR_OP
%left XOR_OP
%left AND_OP
%left EQUAL NOT_EQUAL
%left GREATER_THAN GREATER_OR_EQUAL_THAN LESS_THAN LESS_OR_EQUAL_THAN
%left SHIFT_LEFT SHIFT_RIGHT
%left ADD MINUS
%left MULTIPLY DIVIDE MOD
%nonassoc UMINUS UADD UMULTI UANDOP
%nonassoc INCPOST DECPOST
/* hw3 */
%token<stringval> DIGITALWRITE DELAY 
%token<intval> DVALUE
%type<stringval> assign_primary_expression
/* keyword */
%token IF ELSE SWITCH CASE DEFAULT WHILE DO FOR RETURN BREAK CONTINUE
/* punc */
%token<stringval> SEMICOLON COMMA COLON L_BRACKET R_BRACKET L_SQ_BRACKET R_SQ_BRACKET L_PARENTHESIS R_PARENTHESIS
/* expr */
%type<stringval> expression primary_expression suffix_expression assignment_expression 
%type<stringval>  equality_expression relational_expression  additive_expression multiplicative_expression 
%type<stringval> prefix_expression argument_expression_list
/* statement */
%type<stringval> statement_declaration_list compound_statement return_statement  break_statement jump_statement
%type<stringval> for_statement do_while_statement while_statement iteration_statement 
%type<stringval> if_statement selection_statement expression_statement statement
/* declaration */
%token<stringval> INT CHAR FLOAT DOUBLE VOID SIGNED UNSIGNED LONG SHORT CONST
%type<stringval> declaration declaration_specifiers  type_specifier 
%type<stringval> scalar_decl array_decl func_decl
%type<stringval> parameter_list parameter_declaration  scalar_declarator scalar_init_declarator scalar_init_declarator_list
%type<stringval> func_init_declarator_list 
/* universal */
%type<stringval> external_declaration function_definition trans_unit func_init_declarator func_declarator func_direct_declarator array_init_declarator_list array_init_declarator array_declarator array_content array_expression
%token<stringval> IDENTIFIER CHAR_LITERAL STRING_LITERAL NL
%token<intval> INT_LITERAL
%token<dval> FLOAT_LITERAL
%type<intval> LITERAL
%start program
%%
/* declaration */
program
    : trans_unit {  }

trans_unit
    : external_declaration                      {  }
    | trans_unit external_declaration     { }
    ;

external_declaration
    : declaration
    | function_definition { }
    ;

function_definition
    : declaration_specifiers IDENTIFIER L_BRACKET parameter_list R_BRACKET {
        cur_scope++;
        set_scope_and_offset_of_param($4);
        code_gen_func_header($2);
    }
    compound_statement { 
        pop_up_symbol(cur_scope);
        cur_scope--;
        code_gen_at_end_of_function_body($2);
    }
    | declaration_specifiers IDENTIFIER L_BRACKET R_BRACKET {
        cur_scope++;
        code_gen_func_header($2);
    }
    compound_statement { 
        pop_up_symbol(cur_scope);
        cur_scope--;
        code_gen_at_end_of_function_body($2);
    }
    ;
declaration : scalar_decl { $$ = $1;}
            | array_decl { $$ = $1;}
            | func_decl { $$ = $1;}
            ;
declaration_specifiers
    : type_specifier { $$ = $1 ;}/* e.g. int */
      /* e.g. signed int */
    | type_specifier declaration_specifiers     { 

    }
      /* i.e. const */
    | CONST { $$ = $1 ;}
      /* e.g. const int */
    | CONST declaration_specifiers     { 

    }
    ;

// terminals: fundamental types
type_specifier
    : INT 
    | CHAR
    | FLOAT
    | DOUBLE
    | VOID
    | SIGNED
    | UNSIGNED
    | LONG
    | SHORT
    ;
LITERAL:
      INT_LITERAL {
        $$=$1;
        fprintf(f_asm, "    li t0, %d\n", $1);
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
      }
    | FLOAT_LITERAL {
        /* no need */
    }
    | CHAR_LITERAL {
        /* no need */
    }
    | STRING_LITERAL {
        /* no need */
    }
    ;
/* scalar */
scalar_decl : declaration_specifiers scalar_init_declarator_list SEMICOLON{

}
;

scalar_init_declarator_list
    : scalar_init_declarator                           { $$ = $1; }
    | scalar_init_declarator COMMA scalar_init_declarator_list  { 

    }
    ;


scalar_init_declarator
    : scalar_declarator                    { 
        $$ = install_symbol($1);
        /*fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    sw zero, 0(sp)\n");*/
    }
    | scalar_declarator ASSIGN expression   { 
        $$ = install_symbol($1);
        int index = look_up_symbol($1);
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    sw t0, %d(s0)\n", table[index].offset * (-4) - 48);
    }
    ;


scalar_declarator
    : IDENTIFIER          { $$ = $1;}
    | MULTIPLY IDENTIFIER  { $$ = $2;}
    ;

/* scalar */

/* func */
func_decl : declaration_specifiers func_init_declarator_list SEMICOLON{

}
;

func_init_declarator_list
    : func_init_declarator                           { $$ = $1; }
    | func_init_declarator COMMA func_init_declarator_list  { 

    }
    ;


func_init_declarator
    : func_declarator                    { $$ = $1; }
    | func_declarator ASSIGN expression    { 

    }
    ;


func_declarator
    : func_direct_declarator         { $$ = $1; }
    | MULTIPLY func_direct_declarator { 

    }
    ;


func_direct_declarator
    : IDENTIFIER L_BRACKET R_BRACKET  {
        fprintf(f_asm, ".global %s\n", $1);
    }
    | IDENTIFIER L_BRACKET parameter_list R_BRACKET {
        fprintf(f_asm, ".global %s\n", $1);
    }
    ;

parameter_list
    : parameter_declaration { $$ = $1; }
    | parameter_declaration COMMA parameter_list { 

    }
    ;

parameter_declaration
    : declaration_specifiers scalar_declarator { 

    }
    ;
/* func */

/* array */
array_decl : declaration_specifiers array_init_declarator_list SEMICOLON {

}
;

array_init_declarator_list
    : array_init_declarator                           { $$ = $1; }
    | array_init_declarator COMMA array_init_declarator_list  { 

    }
    ;


array_init_declarator
    : array_declarator   { 
        
    }
    | array_declarator ASSIGN array_content   { 
        /*no need*/
        $$ = install_symbol($1);
    }
    ;

array_declarator
    : IDENTIFIER L_SQ_BRACKET LITERAL R_SQ_BRACKET {
        $$ = install_array_symbol($1,$3); 
        
    }
    | array_declarator L_SQ_BRACKET expression R_SQ_BRACKET {
        /* no need */
    }
    ;

array_content
    : L_PARENTHESIS array_expression R_PARENTHESIS  { 

     }
    | L_PARENTHESIS array_content COMMA array_content R_PARENTHESIS {

    }
    | L_PARENTHESIS array_content COMMA array_expression R_PARENTHESIS {

    }
    | L_PARENTHESIS array_content R_PARENTHESIS {

    }
    ;

array_expression
    : expression {$$ = $1;}
    | array_expression COMMA expression {

    }
    ;
/* array */

/* expression */
// highest precedence, should not be separated
primary_expression
    : IDENTIFIER  {
        $$=$1;
        int index = look_up_symbol($1);
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
    | LITERAL     { 

    }
    | L_BRACKET expression R_BRACKET    { 
        
    }
    | IDENTIFIER L_SQ_BRACKET expression R_SQ_BRACKET   {
        int index = look_up_symbol($1);
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

    ;

argument_expression_list
    : assignment_expression  { $$ = $1;}
    | assignment_expression COMMA argument_expression_list { 

    }
    ;

suffix_expression
    : primary_expression { $$ = $1;}
    | suffix_expression L_BRACKET R_BRACKET                  { 

    }
    | suffix_expression L_BRACKET argument_expression_list R_BRACKET       { 
    }
    ;

prefix_expression
    : suffix_expression  { $$ = $1;}
    | MINUS prefix_expression  %prec UMINUS    { 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sub t0, zero, t0\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        
    }
    | MULTIPLY prefix_expression  %prec UMULTI  { 
        /*section B*/
        //int index = look_up_symbol($2);
        //fprintf(f_asm, "    lw t0, %d(s0)\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        /*section B*/
        fprintf(f_asm, "    add t0, t0, s0\n");
        fprintf(f_asm, "    lw t1, 0(t0)\n");
        fprintf(f_asm, "    sw t1, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        
        
    }
    | AND_OP IDENTIFIER   %prec UANDOP { 
        int index = look_up_symbol($2);
        fprintf(f_asm, "    li t0, %d\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    sw t0, -4(sp)\n"); 
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
    ;

    /* Left precedence (Left to Right) */

multiplicative_expression
    : prefix_expression { $$ = $1;}
    | multiplicative_expression MULTIPLY prefix_expression { 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    mul t0, t0, t1\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
    | multiplicative_expression DIVIDE prefix_expression { 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    div t0, t1, t0\n");
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1;}
    | additive_expression ADD multiplicative_expression { 
        if(is_array){
            int index = look_up_symbol($1);
            if(dbg)printf("HELLO %s\n",table[index].name);
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    li t1, %d\n", table[index].offset * (-4) - 48);
            fprintf(f_asm, "    li t3, 4\n");
            fprintf(f_asm, "    mul t0, t0, t3\n");
            fprintf(f_asm, "    sub t0, t1, t0\n");
            fprintf(f_asm, "    sw t0, -4(sp)\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");
        }else {
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t1, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    add t0, t0, t1\n");
            fprintf(f_asm, "    sw t0, -4(sp)\n");
            fprintf(f_asm, "    addi sp, sp, -4\n");
        }
    }
    | additive_expression MINUS multiplicative_expression { 
        if(is_array) {

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
    ;

relational_expression
    : additive_expression { $$ = $1;}
    | relational_expression LESS_THAN additive_expression        { 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        if(in_for){
            if(dbg) printf("trick failQQ\n");
           // fprintf(f_asm, "    addi t1, t1, 1\n");
        }
        fprintf(f_asm, "    bge t1, t0, L%d\n", cur_label);
    }
    | relational_expression LESS_OR_EQUAL_THAN additive_expression     { 

    }
    | relational_expression GREATER_THAN additive_expression        { 

    }
    | relational_expression GREATER_OR_EQUAL_THAN additive_expression     { 

    }
    ;

equality_expression
    : relational_expression { $$ = $1;}
    | equality_expression EQUAL relational_expression   { 
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    lw t1, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    bne t1, t0, L%d\n", cur_label);
    }
    | equality_expression NOT_EQUAL relational_expression  { 
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
    ;


assignment_expression
    : equality_expression { $$ = $1;}
    | IDENTIFIER ASSIGN assignment_expression {
        $$=$1;
        int index = look_up_symbol($1);
        fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sw t0, %d(s0)\n", table[index].offset * (-4) - 48);

    }
    |  assign_primary_expression ASSIGN assignment_expression {
        if(assignflag==0){
            int index = look_up_symbol($1);
            fprintf(f_asm, "    lw t0, 0(sp)\n");
            fprintf(f_asm, "    addi sp, sp, 4\n");
            fprintf(f_asm, "    lw t1, %d(s0)\n", table[index].offset * (-4) - 48);
            fprintf(f_asm, "    add t1, s0, t1\n");
            fprintf(f_asm, "    sw t0, 0(t1)\n");
        }
    }
    | IDENTIFIER L_SQ_BRACKET expression R_SQ_BRACKET ASSIGN assignment_expression  {
        int index = look_up_symbol($1);
        fprintf(f_asm, "    lw t0, 0(sp)\n"); //
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
    ;
assign_primary_expression
    : MULTIPLY IDENTIFIER  {
        assignflag=0;
        $$ = $2;
    }
    | MULTIPLY L_BRACKET expression R_BRACKET    { 
        assignflag=2;
    }
     
    ;
// lowest precedence, includes everything
// comma not supported
expression
    : assignment_expression {
        is_array = 0;
        $$=$1;
    }
    ;
/* expression */

/* statement */
statement
    : expression_statement {$$ = $1;}
    | selection_statement {$$ = $1;}
    | iteration_statement {$$ = $1;}
    | jump_statement {$$ = $1;}
    | compound_statement {$$ = $1;}
    | delay_stmt{$$ = $$;}
    | digitalwrite_stmt {$$ = $$;}
    ;

digitalwrite_stmt
    : DIGITALWRITE L_BRACKET INT_LITERAL COMMA DVALUE R_BRACKET SEMICOLON {
        fprintf(f_asm, "    li t0, %d\n", $5);
        fprintf(f_asm, "    sw t0, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    li t0, %d\n", $3);
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
    ;

delay_stmt
    : DELAY L_BRACKET expression R_BRACKET SEMICOLON {
        fprintf(f_asm, "    lw a0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
        fprintf(f_asm, "    sw ra, -4(sp)\n");
        fprintf(f_asm, "    addi sp, sp, -4\n");
        fprintf(f_asm, "    jal ra, delay\n");
        fprintf(f_asm, "    lw ra, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");
    }
    ;

expression_statement
    : expression SEMICOLON { 

    }
    ;

selection_statement
    : if_statement { $$ = $1;}
    ;
if_start_stat:
    IF {
        cur_scope++;
        cur_label++;
        in_if = 1;
    }L_BRACKET expression {
        push_label(cur_label);
        /*fprintf(f_asm, "    lw t0, 0(sp)\n");
        fprintf(f_asm, "    addi sp, sp, 4\n");*/
        in_if = 0;
    }
if_statement
    : if_start_stat R_BRACKET compound_statement { 
        int tmp_label = pop_label();
        fprintf(f_asm, "L%d:\n", tmp_label);
        pop_up_symbol(cur_scope);
        cur_scope--;
    }
    | if_start_stat R_BRACKET compound_statement ELSE{
        int tmp_label = pop_label();
        fprintf(f_asm, "    beq zero, zero, EXIT%d\n", tmp_label);
        fprintf(f_asm, "L%d:\n", tmp_label);
        push_label(tmp_label);
    } compound_statement {
        int tmp_label = pop_label();
        fprintf(f_asm, "EXIT%d:\n", tmp_label);
        pop_up_symbol(cur_scope);
        cur_scope--;
    }
    ;


iteration_statement
    : while_statement { $$ = $1;}
    | do_while_statement { $$ = $1;}
    | for_statement { $$ = $1;}
    ;

while_statement
    : WHILE {
        cur_label++;
        cur_scope++;
        fprintf(f_asm, "WHILE%d:\n", cur_label);
        push_label(cur_label);
        in_while = 1;
    }L_BRACKET expression{
        in_while = 0;
    } R_BRACKET statement    {  
        int tmp_label = pop_label();
        fprintf(f_asm, "    beq zero, zero, WHILE%d\n", tmp_label);
        fprintf(f_asm, "L%d:\n", tmp_label);
        pop_up_symbol(cur_scope);
        cur_scope--;
    }
    ;

do_while_statement
    : DO {
        cur_scope++;
        cur_label++;
        fprintf(f_asm, "DOWHILE%d:\n", cur_label);
        push_label(cur_label);  
    }statement WHILE L_BRACKET expression R_BRACKET SEMICOLON { 
        int tmp_label = pop_label();
        fprintf(f_asm, "    beq zero, zero, DOWHILE%d\n", tmp_label);
        fprintf(f_asm, "L%d:\n", tmp_label);
        pop_up_symbol(cur_scope);
        cur_scope--;
    }
    ;

for_statement
    : FOR L_BRACKET expression SEMICOLON{
        cur_scope++;
        push_label(++cur_label);
        /*tricky*/
        in_for=1;
        fprintf(f_asm, "FOR%d:\n", cur_label);
    } expression SEMICOLON {
        in_for=0;
    } IDENTIFIER ASSIGN IDENTIFIER ADD INT_LITERAL R_BRACKET compound_statement {
        int tmp_label = pop_label();
        int index = look_up_symbol($3);
        
        //printf("%d",table[index].scope);
        fprintf(f_asm, "    lw t0, %d(s0)\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    addi t0, t0, 1\n");
        fprintf(f_asm, "    sw t0, %d(s0)\n", table[index].offset * (-4) - 48);
        fprintf(f_asm, "    beq zero, zero, FOR%d\n", tmp_label);
        fprintf(f_asm, "L%d:\n", tmp_label);
        pop_up_symbol(cur_scope);
        cur_scope--;
    }
    ;

jump_statement
    : break_statement {$$ =$1;}
    | return_statement {$$ =$1;}
    ;

break_statement
    : BREAK SEMICOLON     { 

    }
    ;

return_statement
    : RETURN SEMICOLON                { 

    }
    | RETURN expression SEMICOLON     {

    }
    ;

compound_statement
    : L_PARENTHESIS R_PARENTHESIS                               { 

     }
    | L_PARENTHESIS statement_declaration_list R_PARENTHESIS    { 
       
     }
    ;

statement_declaration_list
    : statement { 

    }
    | statement statement_declaration_list      { 

    }
    | declaration { $$ = $1;}
    | declaration statement_declaration_list    { 

    }
    ;
/* statement */

%%

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