#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../error.h"
#include "../node/node_type.h"


#ifndef SYMBOL_H
#define SYMBOL_H

#define NEST_DEPTH 512

union symbol_data{
    int sd_int;
    double sd_double;
    unsigned char sd_char;
    char *sd_string;
};



struct symbol_my{
    int smbl_id;
    char *smbl_name;
    int smbl_name_len;

    //enum node_type_enum smbl_type;
    int smbl_type;
    char *smbl_file;
    int  smbl_file_len;
    int smbl_line_num;	

    int smbl_in_which_node;
	
    union symbol_data smbl_data;

};

struct symbol_a_dms{
    int category;
    int seq;
    int index1;
    int index2;
    struct symbol_a_dms * next;
};

struct temp_var_infor{
    int index;
    int declaration_specifiers_index;
};


struct symbol_a_infor{
    int index;
    int node_index;
    int declaration_specifiers_index;
    int IDENTIFIER_index;
    char* smbl_name;
    int line_num;
    int s_type;  // variable:0 struct:1 function:2 tmp_var:4
    int pointer_index;
    int array_dimension;
    int *every_dimension;
    struct symbol_a_dms * next;
    int mod_num;
    int taint_m;
    int action_scope;
};

#endif

struct symbol_my* add_symbol(char *input_yytext_ptr, int line_num, int symbol_type);

int print_symbol(struct symbol_my *ptr);
int print_symbol_all_infor(struct symbol_my *smbl_ptr);
int print_symbol_table();

//-----------------------symbol_a
int symbol_a_add(int action_scope, int node_index);

int symbol_a_find_part1(char *name, int action_scope);
int symbol_a_find_part2(int node_index);
int symbol_a_find(char *name, int action_scope, int node_index);

int symbol_a_table_num_add();
int alter_symbol_a_action_scope(int index, int action_scope);
int alter_symbol_a_s_type(int index, int s_type);
int alter_symbol_a_taint_m(int index, int taint_m);

int print_symbol_a_table();
int print_symbol_a_infor(int index);

int is_in_taint_file(char *name, int line_num);


