#include <stdio.h>
#include <stdlib.h>
#define MAX_TABLE_SIZE 5000
#define MAX_LABEL_STACK_SIZE 10
#define FILENAME "codegen.S"
#define FILETMP "tmp.S"

typedef struct symbol_entry *PTR_SYMB;

struct symbol_entry {
    char *name;
    int scope;
    int offset;
    int id;
    int variant;
    int type;
    int total_args;
    int total_locals;
    int mode;
};

void init();
char *install_symbol(char*);
char *install_array_symbol(char*, int);
int look_up_symbol(char*);
void pop_up_symbol(int);
void set_scope_and_offset_of_param(char*);
void code_gen_func_header(char*);
void code_gen_at_end_of_function_body(char*);
void push_label(int);
int pop_label();

char *copys(char *s);

#define ARGUMENT_MODE 0
#define LOCAL_MODE 1
#define GLOBAL_MODE 2

#define T_OTHER 0
#define T_FUNCTION 1
#define T_POINTER 2

extern FILE* f_asm;
extern int cur_scope;
extern int cur_counter;
extern int cur_label;
extern int cur_local_var;
extern int label_stack[MAX_LABEL_STACK_SIZE];
extern int cur_label_stack_size;
extern struct symbol_entry table[MAX_TABLE_SIZE];