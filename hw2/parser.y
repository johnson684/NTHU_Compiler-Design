%{
    #include <stdio.h>
%}

%union {
  int intval;
  double dval;
  char* stringval;
}
/* op */
%token<stringval> INC DEC LESS_OR_EQUAL_THAN GREATER_OR_EQUAL_THAN SHIFT_LEFT SHIFT_RIGHT EQUAL NOT_EQUAL AND OR ADD MINUS MULTIPLY DIVIDE MOD LOGICAL_NOT BITWISE_NOT LESS_THAN GREATER_THAN AND_OP OR_OP XOR_OP ASSIGN 
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
/* keyword */
%token IF ELSE SWITCH CASE DEFAULT WHILE DO FOR RETURN BREAK CONTINUE
/* punc */
%token<stringval> SEMICOLON COMMA COLON L_BRACKET R_BRACKET L_SQ_BRACKET R_SQ_BRACKET L_PARENTHESIS R_PARENTHESIS
/* expr */
%type<stringval> expression primary_expression suffix_expression multidim_arr_list assignment_expression logical_or_expression logical_and_expression bitwise_or_expression
%type<stringval> bitwise_xor_expression bitwise_and_expression equality_expression relational_expression shift_expression additive_expression multiplicative_expression specifier_qualifier_list
%type<stringval> type_name prefix_expression argument_expression_list
/* statement */
%type<stringval> statement_declaration_list compound_statement return_statement continue_statement break_statement jump_statement emptiable_expression
%type<stringval> for_statement do_while_statement while_statement iteration_statement statement_list switch_clause switch_clause_list
%type<stringval> switch_statement if_statement emptiable_statement_declaration_list selection_statement expression_statement statement
/* declaration */
%token<stringval> INT CHAR FLOAT DOUBLE VOID SIGNED UNSIGNED LONG SHORT CONST
%type<stringval> declaration declaration_specifiers  type_specifier 
%type<stringval> scalar_decl array_decl func_decl
%type<stringval> parameter_list parameter_declaration  scalar_declarator scalar_init_declarator scalar_init_declarator_list
%type<stringval> func_init_declarator_list 
/* universal */
%type<stringval> function_definition trans_unit extern_decl func_init_declarator func_declarator func_direct_declarator array_init_declarator_list array_init_declarator array_declarator array_content array_expression
%token<stringval> IDENTIFIER CHAR_LITERAL STRING_LITERAL
%token<intval> INT_LITERAL
%token<dval> FLOAT_LITERAL
%type<stringval> LITERAL
%start program
%%
/* declaration */
program:
	trans_unit {printf("%s",$1);}
	;


trans_unit:
	extern_decl { $$ = $1;}
    | trans_unit extern_decl {
        int len1 = strlen($1);
		int len2 = strlen($2);
		$$ = (char*)malloc((len1+len2)*sizeof(char) + 1);
		strcat($$, $1);
		strcat($$, $2);
    }
	;

extern_decl
    : declaration { $$ = $1;}
    | function_definition   { $$ = $1; } 
    ;   

function_definition
    : declaration_specifiers func_declarator L_PARENTHESIS R_PARENTHESIS                             { 
        $$ = (char*)malloc(sizeof(char)*(strlen($1)+strlen($2)+30));
        strcpy($$, "<func_def>");
        strcat($$, $1);
        strcat($$, $2);
        strcat($$, "{}");
        strcat($$, "</func_def>");
    }
    | declaration_specifiers func_declarator L_PARENTHESIS statement_declaration_list R_PARENTHESIS  {  
        $$ = (char*)malloc(sizeof(char)*(strlen($1)+strlen($2)+strlen($4)+30));
        strcpy($$, "<func_def>");
        strcat($$, $1);
        strcat($$, $2);
        strcat($$, "{");
        strcat($$, $4);
        strcat($$,  "}");
        strcat($$, "</func_def>");
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
        int len1 = strlen($1);
		int len2 = strlen($2);
		$$ = (char*)malloc((len1+len2)*sizeof(char) + 1);
		strcat($$, $1);
		strcat($$, $2);
    }
      /* i.e. const */
    | CONST { $$ = $1 ;}
      /* e.g. const int */
    | CONST declaration_specifiers     { 
        int len1 = strlen($1);
		int len2 = strlen($2);
		$$ = (char*)malloc((len1+len2)*sizeof(char) + 1);
		strcat($$, $1);
		strcat($$, $2);
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
        $$ = (char*) malloc (sizeof(char) * (100));
        sprintf($$,"%d",$1);
      }
    | FLOAT_LITERAL {
        $$ = (char*) malloc (sizeof(char) * (100));
        sprintf($$,"%f",$1);
    }
    | CHAR_LITERAL {
        $$ = $1;
    }
    | STRING_LITERAL {
        $$ = $1;
    }
    ;
/* scalar */
scalar_decl : declaration_specifiers scalar_init_declarator_list SEMICOLON{
    int len1 = strlen($1);
    int len2 = strlen($2);
    $$= (char*)malloc((len1+len2+30)*sizeof(char)+1);
    strcat($$, "<scal_decl>");
    strcat($$, $1);
    strcat($$, $2);
    strcat($$, ";");
    strcat($$,"</scal_decl>");
}
;

scalar_init_declarator_list
    : scalar_init_declarator                           { $$ = $1; }
    | scalar_init_declarator COMMA scalar_init_declarator_list  { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, ",");
        strcat($$, $3);
    }
    ;


scalar_init_declarator
    : scalar_declarator                    { $$ = $1; }
    | scalar_declarator ASSIGN expression   { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "=");
        strcat($$, $3);
    }
    ;


scalar_declarator
    : IDENTIFIER          { $$ = $1;}
    | MULTIPLY IDENTIFIER  { 
        int len2 = strlen($2);
        $$= (char*)malloc((len2+2)*sizeof(char)+1);
        strcat($$, "*");
        strcat($$, $2);
    }
    ;

/* scalar */

/* func */
func_decl : declaration_specifiers func_init_declarator_list SEMICOLON{
    int len1 = strlen($1);
    int len2 = strlen($2);
    $$= (char*)malloc((len1+len2+30)*sizeof(char)+1);
    strcat($$, "<func_decl>");
    strcat($$, $1);
    strcat($$, $2);
    strcat($$, ";");
    strcat($$,"</func_decl>");
}
;

func_init_declarator_list
    : func_init_declarator                           { $$ = $1; }
    | func_init_declarator COMMA func_init_declarator_list  { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, ",");
        strcat($$, $3);
    }
    ;


func_init_declarator
    : func_declarator                    { $$ = $1; }
    | func_declarator ASSIGN expression    { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "=");
        strcat($$, $3);
    }
    ;


func_declarator
    : func_direct_declarator         { $$ = $1; }
    | MULTIPLY func_direct_declarator { 
        int len2 = strlen($2);
        $$= (char*)malloc((len2+2)*sizeof(char)+1);
        strcat($$, "*");
        strcat($$, $2);
    }
    ;


func_direct_declarator
    : IDENTIFIER L_BRACKET R_BRACKET  {
        int len1 = strlen($1);
        $$= (char*)malloc((len1+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "()");
    }
    | IDENTIFIER L_BRACKET parameter_list R_BRACKET {
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "(");
        strcat($$,$3);
        strcat($$,")");
    }
    ;

parameter_list
    : parameter_declaration { $$ = $1; }
    | parameter_declaration COMMA parameter_list { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, ",");
        strcat($$, $3);
    }
    ;

parameter_declaration
    : declaration_specifiers scalar_declarator { 
        int len1 = strlen($1);
        int len2 = strlen($2);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, $2);
    }
    ;
/* func */

/* array */
array_decl : declaration_specifiers array_init_declarator_list SEMICOLON {
    int len1 = strlen($1);
    int len2 = strlen($2);
    $$= (char*)malloc((len1+len2+30)*sizeof(char)+1);
    strcat($$, "<array_decl>");
    strcat($$, $1);
    strcat($$, $2);
    strcat($$, ";");
    strcat($$,"</array_decl>");
}
;

array_init_declarator_list
    : array_init_declarator                           { $$ = $1; }
    | array_init_declarator COMMA array_init_declarator_list  { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, ",");
        strcat($$, $3);
    }
    ;


array_init_declarator
    : array_declarator   { $$ = $1; }
    | array_declarator ASSIGN array_content   { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "=");
        strcat($$, $3);
    }
    ;

array_declarator
    : IDENTIFIER L_SQ_BRACKET expression R_SQ_BRACKET {
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "[");
        strcat($$,$3);
        strcat($$,"]");
    }
    | array_declarator L_SQ_BRACKET expression R_SQ_BRACKET {
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "[");
        strcat($$,$3);
        strcat($$,"]");
    }
    ;

array_content
    : L_PARENTHESIS array_expression R_PARENTHESIS  { 
        int len1 = strlen($2);
        $$= (char*)malloc((len1+3)*sizeof(char)+1);
        strcat($$, "{");
        strcat($$,$2);
        strcat($$,"}");
     }
    | L_PARENTHESIS array_content COMMA array_content R_PARENTHESIS {
        int len1 = strlen($2);
        int len2 = strlen($4);
        $$= (char*)malloc((len1+len2+4)*sizeof(char)+1);
        strcat($$, "{");
        strcat($$,$2);
        strcat($$,",");
        strcat($$,$4);
        strcat($$,"}");
    }
    | L_PARENTHESIS array_content R_PARENTHESIS {
        int len1 = strlen($2);
        $$= (char*)malloc((len1+3)*sizeof(char)+1);
        strcat($$, "{");
        strcat($$,$2);
        strcat($$,"}");
    }
    ;

array_expression
    : expression {$$ = $1;}
    | array_expression COMMA expression {
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, ",");
        strcat($$, $3);
    }
    ;
/* array */

/* expression */
// highest precedence, should not be separated
primary_expression
    : IDENTIFIER  { $$ = $1;}
    | LITERAL     { $$ = $1;}
    | L_BRACKET expression R_BRACKET    { 
        int len1 = strlen($2);
        $$= (char*)malloc((len1+4)*sizeof(char)+1);
        strcat($$,"(");
        strcat($$, $2);
        strcat($$, ")");
    }
    ;

    /* Right precedence (Right to Left) */



multidim_arr_list
    : L_SQ_BRACKET expression R_SQ_BRACKET                        {  
        int len1 = strlen($2);
        $$= (char*)malloc((len1+4)*sizeof(char)+1);
        strcat($$,"(");
        strcat($$, $2);
        strcat($$, ")");
    }
    | L_SQ_BRACKET expression R_SQ_BRACKET multidim_arr_list      { 
        int len1 = strlen($2);
        int len2 = strlen($4);
        $$= (char*)malloc((len1+len2+4)*sizeof(char)+1);
        strcat($$,"(");
        strcat($$, $2);
        strcat($$, ")");
        strcat($$, $4);
    }
    ;

argument_expression_list
    : assignment_expression  { $$ = $1;}
    | assignment_expression COMMA argument_expression_list { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+4)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, ",");
        strcat($$, $3);
    }
    ;

type_name
    : specifier_qualifier_list { $$ = $1;}
    | specifier_qualifier_list MULTIPLY      { 
        int len1 = strlen($1);
        int len2 = strlen($2);
        $$= (char*)malloc((len1+len2+4)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, $2);
    }
    ;

    // TODO: wait until declaration
specifier_qualifier_list
    : CONST { $$ = $1;}
    | CONST specifier_qualifier_list   { 
        int len1 = strlen($1);
        int len2 = strlen($2);
        $$= (char*)malloc((len1+len2+4)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, $2);
    }
    | type_specifier { $$ = $1;}
    | type_specifier specifier_qualifier_list   { 
        int len1 = strlen($1);
        int len2 = strlen($2);
        $$= (char*)malloc((len1+len2+4)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, $2);
    }
    ;

suffix_expression
    : primary_expression { $$ = $1;}
    | suffix_expression INC                                 {  
        int len1 = strlen($1);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,$1);
        strcat($$,"++");
    }
    | suffix_expression DEC                                  { 
        int len1 = strlen($1);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,$1);
        strcat($$,"--");
    }
    | suffix_expression L_BRACKET R_BRACKET                  { 
        int len1 = strlen($1);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,$1);
        strcat($$,"()");
    }
    | suffix_expression L_BRACKET argument_expression_list R_BRACKET       { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+4)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$,"(");
        strcat($$, $3);
        strcat($$, ")");
    }
      /* array: hw spec differs from c / c++ spec */
    | IDENTIFIER  multidim_arr_list       { 
        int len1 = strlen($1);
        int len2 = strlen($2);
        $$= (char*)malloc((len1+len2+4)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, $2);
    }
    ;

prefix_expression
    : suffix_expression  { $$ = $1;}
    | INC prefix_expression              { 
        int len1 = strlen($2);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,"++");
        strcat($$,$2);
    }
    | DEC prefix_expression              { 
        int len1 = strlen($2);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,"--");
        strcat($$,$2);
    }
    | ADD prefix_expression              { 
        int len1 = strlen($2);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,"+");
        strcat($$,$2);
    }
    | MINUS prefix_expression              { 
        int len1 = strlen($2);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,"-");
        strcat($$,$2);
    }
    | LOGICAL_NOT prefix_expression              { 
        int len1 = strlen($2);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,"!");
        strcat($$,$2);
    }
    | BITWISE_NOT prefix_expression              { 
        int len1 = strlen($2);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,"~");
        strcat($$,$2);
    }
    | MULTIPLY prefix_expression              { 
        int len1 = strlen($2);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,"*");
        strcat($$,$2);
    }
    | AND_OP prefix_expression              { 
        int len1 = strlen($2);
        $$ = (char*) malloc(sizeof(char)*(len1+3));
        strcat($$,"&");
        strcat($$,$2);
    }
    | L_BRACKET type_name R_BRACKET prefix_expression   { 
        int len1 = strlen($2);
        int len2 = strlen($4);
        $$= (char*)malloc((len1+len2+4)*sizeof(char)+1);
        strcat($$,"(");
        strcat($$, $2);
        strcat($$, ")");
        strcat($$, $4);
    }
    ;

    /* Left precedence (Left to Right) */

multiplicative_expression
    : prefix_expression { $$ = $1;}
    | multiplicative_expression MULTIPLY prefix_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "*");
        strcat($$, $3);
    }
    | multiplicative_expression DIVIDE prefix_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "/");
        strcat($$, $3);
    }
    | multiplicative_expression MOD prefix_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "%");
        strcat($$, $3);
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1;}
    | additive_expression ADD multiplicative_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "+");
        strcat($$, $3);
    }
    | additive_expression MINUS multiplicative_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "-");
        strcat($$, $3);
    }
    ;

shift_expression
    : additive_expression { $$ = $1;}
    | shift_expression SHIFT_LEFT additive_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "<<");
        strcat($$, $3);
    }
    | shift_expression SHIFT_RIGHT additive_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, ">>");
        strcat($$, $3);
    }
    ;

relational_expression
    : shift_expression { $$ = $1;}
    | relational_expression LESS_THAN shift_expression        { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "<");
        strcat($$, $3);
    }
    | relational_expression LESS_OR_EQUAL_THAN shift_expression     { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "<=");
        strcat($$, $3);
    }
    | relational_expression GREATER_THAN shift_expression        { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, ">");
        strcat($$, $3);
    }
    | relational_expression GREATER_OR_EQUAL_THAN shift_expression     { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, ">=");
        strcat($$, $3);
    }
    ;

equality_expression
    : relational_expression { $$ = $1;}
    | equality_expression EQUAL relational_expression   { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "==");
        strcat($$, $3);
    }
    | equality_expression NOT_EQUAL relational_expression  { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "!=");
        strcat($$, $3);
    }
    ;

bitwise_and_expression
    : equality_expression { $$ = $1;}
    | bitwise_and_expression AND_OP equality_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "&");
        strcat($$, $3);
    }
    ;

bitwise_xor_expression
    : bitwise_and_expression { $$ = $1;}
    | bitwise_xor_expression XOR_OP bitwise_and_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "^");
        strcat($$, $3);
    }
    ;

bitwise_or_expression
    : bitwise_xor_expression { $$ = $1;}
    | bitwise_or_expression OR_OP bitwise_xor_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "|");
        strcat($$, $3);
    }
    ;

logical_and_expression
    : bitwise_or_expression { $$ = $1;}
    | logical_and_expression AND bitwise_or_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "&&");
        strcat($$, $3);
    }
    ;

logical_or_expression
    : logical_and_expression { $$ = $1;}
    | logical_or_expression OR logical_and_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+3)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "||");
        strcat($$, $3);
     }
    ;


    /* Right precedence (Right to Left) */

assignment_expression
    : logical_or_expression { $$ = $1;}
    | logical_or_expression ASSIGN assignment_expression { 
        int len1 = strlen($1);
        int len2 = strlen($3);
        $$= (char*)malloc((len1+len2+2)*sizeof(char)+1);
        strcat($$, $1);
        strcat($$, "=");
        strcat($$, $3);
    }
    ;

// lowest precedence, includes everything
// comma not supported
expression
    : assignment_expression {
        int len1 = strlen($1); 
        $$ = (char*) malloc(sizeof(char)*(len1+30));
        strcat($$, "<expr>");
        strcat($$,$1);
        strcat($$,"</expr>");
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
    ;

expression_statement
    : expression SEMICOLON { 
        $$ = (char*) malloc (sizeof(char) * (5+strlen($1)));
        strcat($$,$1);
        strcat($$,";");
    }
    ;

selection_statement
    : if_statement { $$ = $1;}
    | switch_statement { $$ = $1;}
    ;

if_statement
    : IF L_BRACKET expression R_BRACKET L_PARENTHESIS emptiable_statement_declaration_list R_PARENTHESIS { 
        $$ = (char*) malloc (sizeof(char) * (50+strlen($3)+strlen($6)));
        strcat($$,"if(");
        strcat($$,$3);
        strcat($$,"){");
        strcat($$,$6);
        strcat($$,"}");
    }
    | IF L_BRACKET expression R_BRACKET L_PARENTHESIS emptiable_statement_declaration_list R_PARENTHESIS ELSE L_PARENTHESIS emptiable_statement_declaration_list R_PARENTHESIS {
        $$ = (char*) malloc (sizeof(char) * (50+strlen($3)+strlen($10)+strlen($6)));
        strcat($$,"if(");
        strcat($$,$3);
        strcat($$,"){");
        strcat($$,$6);
        strcat($$,"}else{");
        strcat($$,$10);
        strcat($$,"}");
    }
    ;

emptiable_statement_declaration_list
    : /* empty */                   {  }
    | statement_declaration_list { $$ = $1;}
    ;

switch_statement
    : SWITCH L_BRACKET expression R_BRACKET L_PARENTHESIS R_PARENTHESIS {
        $$ = (char*) malloc (sizeof(char) * (50+strlen($3)));
        strcat($$,"switch(");
        strcat($$,$3);
        strcat($$,"){}");
    }
    | SWITCH L_BRACKET expression R_BRACKET L_PARENTHESIS switch_clause_list R_PARENTHESIS {
        $$ = (char*) malloc (sizeof(char) * (50+strlen($3)+strlen($6)));
        strcat($$,"switch(");
        strcat($$,$3);
        strcat($$,"){");
        strcat($$,$6);
        strcat($$,"}");
    }
    ;

switch_clause_list
    : switch_clause { $$ = $1;}
    | switch_clause switch_clause_list      {  
        $$ = (char*) malloc (sizeof(char) * (5+strlen($2)+strlen($1)));
        strcat($$,$1);
        strcat($$,$2);
    }
    ;

switch_clause
    : CASE expression COLON                   {  
        $$ = (char*) malloc (sizeof(char) * (15+strlen($2)));
        strcat($$,"case");
        strcat($$,$2);
        strcat($$,":");
    }
    | CASE expression COLON statement_list    {  
        $$ = (char*) malloc (sizeof(char) * (15+strlen($2)+strlen($4)));
        strcat($$,"case");
        strcat($$,$2);
        strcat($$,":");
        strcat($$,$4);
    }
    | DEFAULT COLON                            {  
        $$ = (char*) malloc (sizeof(char) * (15));
        strcat($$,"default:");
    }
    | DEFAULT COLON statement_list            { 
        $$ = (char*) malloc (sizeof(char) * (15+strlen($3)));
        strcat($$,"default:");
        strcat($$,$3);
    }
    ;

statement_list
    : statement { $$ = $1;}
    | statement statement_list  { 
        $$ = (char*) malloc (sizeof(char) * (5+strlen($2)+strlen($1)));
        strcat($$,$1);
        strcat($$,$2);
    }
    ;

iteration_statement
    : while_statement { $$ = $1;}
    | do_while_statement { $$ = $1;}
    | for_statement { $$ = $1;}
    ;

while_statement
    : WHILE L_BRACKET expression R_BRACKET statement    {  
        $$ = (char*) malloc (sizeof(char) * (50+strlen($3)+strlen($5)));
        strcat($$,"while(");
        strcat($$,$3);
        strcat($$,")");
        strcat($$,$5);
    }
    ;

do_while_statement
    : DO statement WHILE L_BRACKET expression R_BRACKET SEMICOLON { 
        $$ = (char*) malloc (sizeof(char) * (50+strlen($2)+strlen($5)));
        strcat($$,"do");
        strcat($$,$2);
        strcat($$,"while(");
        strcat($$,$5);
        strcat($$,")");
        strcat($$,";");
    }
    ;

for_statement
    : FOR L_BRACKET emptiable_expression SEMICOLON emptiable_expression SEMICOLON emptiable_expression R_BRACKET statement {
        $$ = (char*) malloc (sizeof(char) * (50+strlen($3)+strlen($5)+strlen($7)+strlen($9)));
        strcat($$,"for");
        strcat($$,"(");
        strcat($$,$3);
        strcat($$,";");
        strcat($$,$5);
        strcat($$,";");
        strcat($$,$7);
        strcat($$,")");
        strcat($$,$9);
    }
    ;

emptiable_expression
    : /* empty */   { }
    | expression {$$ =$1;}
    ;

jump_statement
    : break_statement {$$ =$1;}
    | continue_statement {$$ =$1;}
    | return_statement {$$ =$1;}
    ;

break_statement
    : BREAK SEMICOLON     { 
        $$ = (char*) malloc (sizeof(char) * 10);
        strcat($$,"break;");
    }
    ;

continue_statement
    : CONTINUE SEMICOLON  { 
        $$ = (char*) malloc (sizeof(char) * 10);
        strcat($$,"continue;");
    }
    ;

return_statement
    : RETURN SEMICOLON                { 
        $$ = (char*) malloc (sizeof(char) * 10);
        strcat($$,"return;");
    }
    | RETURN expression SEMICOLON     {
        $$ = (char*) malloc (sizeof(char) * (10+strlen($2)));
        strcat($$,"return");
        strcat($$,$2);
        strcat($$,";");
    }
    ;

compound_statement
    : L_PARENTHESIS R_PARENTHESIS                               { 
        $$ = (char*) malloc (sizeof(char) * 4);
        strcat($$,"{}");
     }
    | L_PARENTHESIS statement_declaration_list R_PARENTHESIS    { 
        $$ = (char*) malloc (sizeof(char) * (4+strlen($2)));
        strcat($$,"{");
        strcat($$,$2);
        strcat($$,"}");
     }
    ;

statement_declaration_list
    : statement { 
        $$ = (char*) malloc(sizeof(char) * (strlen($1)+30));
        strcat($$,"<stmt>");
        strcat($$, $1);
        strcat($$,"</stmt>");
    }
    | statement statement_declaration_list      { 
        $$ = (char*) malloc(sizeof(char) * (strlen($1)+strlen($2)+30));
        strcat($$,"<stmt>");
        strcat($$, $1);
        strcat($$,"</stmt>");
        strcat($$, $2);
    }
    | declaration { $$ = $1;}
    | declaration statement_declaration_list    { 
        $$ = (char*) malloc(sizeof(char) * (strlen($1)+strlen($2)+3));
        strcat($$, $1);
        strcat($$, $2);
    }
    ;
/* statement */

%%

int main(void) {
    yyparse();
    return 0;
}
int yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return 0;
}
