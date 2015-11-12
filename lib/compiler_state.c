#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "compiler_state.h"

#include "scope.h"

extern struct compiler_state my_state;

int print_compiler_state()
{
    printf("================compiler_state start===================\n");
    printf("c_file_str:%s\n", my_state.c_file_str);
    printf("symbol_max_number:%d\nsymbol_number:%d\n", my_state.symbol_max_number, my_state.symbol_number);
    printf("node_max_number:%d\nnode_number:%d\n", my_state.node_max_number, my_state.node_number);
    printf("need_dot_file:%d %s\n", my_state.need_dot_file, my_state.dot_file_str);
    printf("need_taint_file:%d %s\n", my_state.need_taint_file, my_state.taint_file_str);
    print_taint_source();
    printf("taint_num:%d\n", my_state.taint_num);
    printf("need_infor:%d\n", my_state.need_infor);


    printf("symbol_table:%p\n", my_state.declaration_specifiers_table);
    printf("node_table:%p\n", my_state.node_table);
    printf("declaration_secifiers_table:%p\n", my_state.declaration_specifiers_table);

    printf("================compiler_state end ====================\n");
    return 0;
}



int initialize_compiler_state(int node_max_num, int symbol_max_num)
{
    int i=0;
    //char error_str[ERROR_STR_NUMBER];
    //initialize state->symbol_max_number
    if(0==node_max_num)
    {
        my_state.node_max_number  =NODE_MAX_NUMBER;
    }
    else
    {
        my_state.node_max_number  =node_max_num;
    }

    //initialize state->node_max_numaber
    if(0==symbol_max_num)
    {
        my_state.symbol_max_number  =SYMBOL_MAX_NUMBER;
    }
    else
    {
        my_state.symbol_max_number  =symbol_max_num;
    }

    //initialize state->node_number and state->symbol_number 
    my_state.node_number  =0;
    my_state.symbol_number=0;

    //initialize state->node_table
    my_state.node_table=(struct node_my **)malloc(my_state.node_max_number*sizeof(struct node_my *));
    if(0x00==my_state.node_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc node_table error!");
        my_state.error_int=10101;
        error_quit();
    }
    memset(my_state.node_table, 0x00, my_state.node_max_number*sizeof(struct node_my *));
    printf("81818181: node_table:%p\n", my_state.node_table);

    //initialize state->symbol_table
    my_state.symbol_table=(struct symbol_my **)malloc(my_state.symbol_max_number*sizeof(struct symbol_my *));
    if(0x00==my_state.symbol_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc symbol_table error!");
        my_state.error_int=10102;
        error_quit();
    }
    memset(my_state.symbol_table, 0x00, my_state.symbol_max_number*sizeof(struct symbol_my *));
    printf("81818181: symbol_table:%p\n", my_state.symbol_table);

    //initialize state->c_file_str and state->c_file_fd
/*
    int count_i=0;
    while(0x00!=c_file_str[count_i])
    {
        ++count_i;
    }
    if(count_i>FILE_NAME_LENGTH)
    {
        snprintf(state->error_str, sizeof(state->error_str), "c file name is too long(%d is more than FILE_NAME_LEGNTH:%d)", count_i, FILE_NAME_LENGTH);
        state->error_int=13;
    }
    char *tmp_str=strcpy(state->c_file_str, c_file_str); 
    if(state->c_file_str!=tmp_str)
    {
        snprintf(state->error_str, sizeof(state->error_str), "strcpy c file name error!");
        state->error_int=14;
        error_quit(state);
    }
*/
    my_state.c_file_fd=fopen(my_state.c_file_str, "r");
    if(0x00==my_state.c_file_fd)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: fopen c file:%s error!", my_state.c_file_str);
        my_state.error_int=10103;
        error_quit();
    }    

    //initialize state->need_dot_file and state->dot_file_fd
/*
    if(0==need_dot_file)
    {
        state->need_dot_file=0;
    }
    else
    {
        state->need_dot_file=1;
    }
*/
    if(1==my_state.need_dot_file)   
    {
        //my_state.dot_file_fd=open(my_state.dot_file_str, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
        my_state.dot_file_fd=open(my_state.dot_file_str, O_RDWR|O_CREAT);
        if(-1==my_state.dot_file_fd)
        {
            snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: open dot file:%s error!", my_state.dot_file_str);
            my_state.error_int=10104;
            error_quit();
        }
        char *dot_start="digraph G{\n";
        int write_num=write(my_state.dot_file_fd, dot_start, strlen(dot_start));
    }


    if(1==my_state.need_taint_file)
    {
      deal_taint_file();
    }
 
    //initialize state->need_infor
    /*
    if(0==need_infor)
    {
        state->need_infor=need_infor;
    }
    else
    {
        state->need_infor=1;
    }
    */

//===================table start
//-------------------initialize declaration_specifiers_table
    //my_state.declaration_specifiers_table=()malloc(DECLARATION_SPECIFIERS_TABLE_NUM*sizeof(struct declaration_specifiers_infor *));
    my_state.declaration_specifiers_table=(struct declaration_specifiers_infor **)malloc(DECLARATION_SPECIFIERS_TABLE_NUM*sizeof(struct declaration_specifiers_infor *));
    if(0x00==my_state.declaration_specifiers_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc declaration_specifiers_table error!");
        my_state.error_int=10101;
        error_quit();
    }
    printf("lib/compiler_state.c:151 %p\n", my_state.declaration_specifiers_table);
    memset(my_state.declaration_specifiers_table, 0x00, DECLARATION_SPECIFIERS_TABLE_NUM*sizeof(struct declaration_specifiers_infor *));
    my_state.declaration_specifiers_table_num=0; 

//-------------------initialize direct_declarator_table
    //my_state.declaration_specifiers_table=()malloc(DECLARATION_SPECIFIERS_TABLE_NUM*sizeof(struct declaration_specifiers_infor *));
    my_state.direct_declarator_table=(struct direct_declarator_infor **)malloc(DIRECT_DECLARATOR_TABLE_NUM*sizeof(struct direct_declarator_infor *));
    if(0x00==my_state.direct_declarator_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc direct_declarator_table error!");
        my_state.error_int=10102;
        error_quit();
    }
    //printf("lib/compiler_state.c:151 %x\n", my_state.direct_declarator_table);
    memset(my_state.direct_declarator_table, 0x00, DIRECT_DECLARATOR_TABLE_NUM*sizeof(struct direct_declarator_infor *));
    my_state.direct_declarator_table_num=0; 

//--------------------initialize compound_statement_table
    my_state.compound_statement_table=(struct compound_statement_infor **)malloc(COMPOUND_STATEMENT_TABLE_NUM*sizeof(struct compound_statement_infor *));
    if(0x00==my_state.compound_statement_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc compound_statement_table  error!");
        my_state.error_int=10103;
        error_quit();
    }
    memset(my_state.compound_statement_table, 0x00, COMPOUND_STATEMENT_TABLE_NUM*sizeof(struct compound_statement_infor  *));
    my_state.compound_statement_table_num=0;

//--------------------------------------------------------------------------------------------------------------------------
//--------------------initialize declaration_table
    my_state.declaration_table=(struct declaration_infor **)malloc(DECLARATION_TABLE_NUM*sizeof(struct declaration_infor *));
    if(0x00==my_state.declaration_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc declaration_table  error!");
        my_state.error_int=10104;
        error_quit();
    }
    memset(my_state.declaration_table, 0x00, DECLARATION_TABLE_NUM*sizeof(struct declaration_infor  *));
    my_state.declaration_table_num=0;


//--------------------initialize init_declarator_table
    my_state.init_declarator_table=(struct init_declarator_infor **)malloc(INIT_DECLARATOR_TABLE_NUM*sizeof(struct init_declarator_infor *));
    if(0x00==my_state.init_declarator_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc init_declarator_table  error!");
        my_state.error_int=10105;
        error_quit();
    }
    memset(my_state.init_declarator_table, 0x00, INIT_DECLARATOR_TABLE_NUM*sizeof(struct init_declarator_infor  *));
    my_state.init_declarator_table_num=0;

 
//--------------------initialize initializer_table
    my_state.initializer_table=(struct initializer_infor **)malloc(INITIALIZER_TABLE_NUM*sizeof(struct initializer_infor *));
    if(0x00==my_state.initializer_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer_table  error!");
        my_state.error_int=10106;
        error_quit();
    }
    memset(my_state.initializer_table, 0x00, INITIALIZER_TABLE_NUM*sizeof(struct initializer_infor  *));
    my_state.initializer_table_num=0;


//--------------------initialize initializer_list_table
    my_state.initializer_list_table=(struct initializer_list_infor **)malloc(INITIALIZER_LIST_TABLE_NUM*sizeof(struct initializer_list_infor *));
    if(0x00==my_state.initializer_list_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer_list_table  error!");
        my_state.error_int=10107;
        error_quit();
    }
    memset(my_state.initializer_list_table, 0x00, INITIALIZER_LIST_TABLE_NUM*sizeof(struct initializer_list_infor  *));
    my_state.initializer_list_table_num=0;

//--------------------initialize initializer_list_one_table
    my_state.initializer_list_one_table=(struct initializer_list_one_infor **)malloc(INITIALIZER_LIST_ONE_TABLE_NUM*sizeof(struct initializer_list_one_infor *));
    if(0x00==my_state.initializer_list_one_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer_list_one_table  error!");
        my_state.error_int=10107;
        error_quit();
    }
    memset(my_state.initializer_list_one_table, 0x00, INITIALIZER_LIST_ONE_TABLE_NUM*sizeof(struct initializer_list_one_infor  *));
    my_state.initializer_list_one_table_num=0;


//--------------------initialize declarator_table
    my_state.declarator_table=(struct declarator_infor **)malloc(DECLARATOR_TABLE_NUM*sizeof(struct declarator_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.declarator_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer declarator_table  error!");
        my_state.error_int=10108;
        error_quit();
    }
    memset(my_state.declarator_table, 0x00, DECLARATOR_TABLE_NUM*sizeof(struct declarator_infor  *));
    my_state.declarator_table_num=0;

//--------------------initialize block_item_table
    my_state.block_item_table=(struct block_item_infor **)malloc(BLOCK_ITEM_TABLE_NUM*sizeof(struct block_item_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.block_item_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer block_item_table  error!");
        my_state.error_int=10109;
        error_quit();
    }
    memset(my_state.block_item_table, 0x00, BLOCK_ITEM_TABLE_NUM*sizeof(struct block_item_infor  *));
    my_state.block_item_table_num=0;
    //printf("11111\n");


//--------------------initialize statement_table
    my_state.statement_table=(struct statement_infor **)malloc(STATEMENT_TABLE_NUM*sizeof(struct statement_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.statement_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer statement_table  error!");
        my_state.error_int=10110;
        error_quit();
    }
    memset(my_state.statement_table, 0x00, STATEMENT_TABLE_NUM*sizeof(struct statement_infor  *));
    my_state.statement_table_num=0;


//--------------------initialize jump_statement_table
    my_state.jump_statement_table=(struct jump_statement_infor **)malloc(JUMP_STATEMENT_TABLE_NUM*sizeof(struct jump_statement_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.jump_statement_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer jump_statement_table  error!");
        my_state.error_int=10110;
        error_quit();
    }
    memset(my_state.jump_statement_table, 0x00, JUMP_STATEMENT_TABLE_NUM*sizeof(struct jump_statement_infor  *));
    my_state.jump_statement_table_num=0;

//--------------------initialize iteration_statement_table
    my_state.iteration_statement_table=(struct iteration_statement_infor **)malloc(ITERATION_STATEMENT_TABLE_NUM*sizeof(struct iteration_statement_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.iteration_statement_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer iteration_statement_table  error!");
        my_state.error_int=10111;
        error_quit();
    }
    memset(my_state.iteration_statement_table, 0x00, ITERATION_STATEMENT_TABLE_NUM*sizeof(struct iteration_statement_infor  *));
    my_state.iteration_statement_table_num=0;

//--------------------initialize selection_statement_table
    my_state.selection_statement_table=(struct selection_statement_infor **)malloc(SELECTION_STATEMENT_TABLE_NUM*sizeof(struct selection_statement_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.selection_statement_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer selection_statement_table  error!");
        my_state.error_int=10112;
        error_quit();
    }
    memset(my_state.selection_statement_table, 0x00, ITERATION_STATEMENT_TABLE_NUM*sizeof(struct selection_statement_infor  *));
    my_state.selection_statement_table_num=0;

//--------------------initialize labeled_statement_table
    my_state.labeled_statement_table=(struct labeled_statement_infor **)malloc(LABELED_STATEMENT_TABLE_NUM*sizeof(struct labeled_statement_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.labeled_statement_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer labeled_statement_table  error!");
        my_state.error_int=10113;
        error_quit();
    }
    memset(my_state.labeled_statement_table, 0x00, LABELED_STATEMENT_TABLE_NUM*sizeof(struct labeled_statement_infor  *));
    my_state.labeled_statement_table_num=0;

//--------------------initialize expression_statement_table
    my_state.expression_statement_table=(struct expression_statement_infor **)malloc(EXPRESSION_STATEMENT_TABLE_NUM*sizeof(struct expression_statement_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.expression_statement_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer expression_statement_table  error!");
        my_state.error_int=10114;
        error_quit();
    }
    memset(my_state.expression_statement_table, 0x00, EXPRESSION_STATEMENT_TABLE_NUM*sizeof(struct expression_statement_infor  *));
    my_state.expression_statement_table_num=0;

//--------------------initialize expression_table
    my_state.expression_table=(struct expression_infor **)malloc(EXPRESSION_TABLE_NUM*sizeof(struct expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer expression_table  error!");
        my_state.error_int=10115;
        error_quit();
    }
    memset(my_state.expression_table, 0x00, EXPRESSION_TABLE_NUM*sizeof(struct expression_infor  *));
    my_state.expression_table_num=0;

//--------------------initialize assignment_expression_table
    my_state.assignment_expression_table=(struct assignment_expression_infor **)malloc(ASSIGNMENT_EXPRESSION_TABLE_NUM*sizeof(struct assignment_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.assignment_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer assignment_expression_table  error!");
        my_state.error_int=10116;
        error_quit();
    }
    memset(my_state.assignment_expression_table, 0x00, ASSIGNMENT_EXPRESSION_TABLE_NUM*sizeof(struct assignment_expression_infor  *));
    my_state.assignment_expression_table_num=0;

//--------------------initialize conditional_expression_table
    my_state.conditional_expression_table=(struct conditional_expression_infor **)malloc(CONDITIONAL_EXPRESSION_TABLE_NUM*sizeof(struct conditional_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.conditional_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer conditional_expression_table  error!");
        my_state.error_int=10117;
        error_quit();
    }
    memset(my_state.conditional_expression_table, 0x00, CONDITIONAL_EXPRESSION_TABLE_NUM*sizeof(struct conditional_expression_infor  *));
    my_state.conditional_expression_table_num=0;

//--------------------initialize logical_or_expression_table
    my_state.logical_or_expression_table=(struct logical_or_expression_infor **)malloc(LOGICAL_OR_EXPRESSION_TABLE_NUM*sizeof(struct logical_or_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.logical_or_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer logical_or_expression_table  error!");
        my_state.error_int=10118;
        error_quit();
    }
    memset(my_state.logical_or_expression_table, 0x00, LOGICAL_OR_EXPRESSION_TABLE_NUM*sizeof(struct logical_or_expression_infor  *));
    my_state.logical_or_expression_table_num=0;

//--------------------initialize logical_and_expression_table
    my_state.logical_and_expression_table=(struct logical_and_expression_infor **)malloc(LOGICAL_AND_EXPRESSION_TABLE_NUM*sizeof(struct logical_and_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.logical_and_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer logical_and_expression_table  error!");
        my_state.error_int=10119;
        error_quit();
    }
    memset(my_state.logical_and_expression_table, 0x00, LOGICAL_AND_EXPRESSION_TABLE_NUM*sizeof(struct logical_and_expression_infor  *));
    my_state.logical_and_expression_table_num=0;

//--------------------initialize inclusive_or_expression_table
    my_state.inclusive_or_expression_table=(struct inclusive_or_expression_infor **)malloc(INCLUSIVE_OR_EXPRESSION_TABLE_NUM*sizeof(struct inclusive_or_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.inclusive_or_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer inclusive_or_expression_table  error!");
        my_state.error_int=10120;
        error_quit();
    }
    memset(my_state.inclusive_or_expression_table, 0x00, INCLUSIVE_OR_EXPRESSION_TABLE_NUM*sizeof(struct inclusive_or_expression_infor  *));
    my_state.inclusive_or_expression_table_num=0;

//--------------------initialize exclusive_or_expression_table
    my_state.exclusive_or_expression_table=(struct exclusive_or_expression_infor **)malloc(EXCLUSIVE_OR_EXPRESSION_TABLE_NUM*sizeof(struct exclusive_or_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.inclusive_or_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer exclusive_or_expression_table  error!");
        my_state.error_int=10121;
        error_quit();
    }
    memset(my_state.exclusive_or_expression_table, 0x00, EXCLUSIVE_OR_EXPRESSION_TABLE_NUM*sizeof(struct exclusive_or_expression_infor  *));
    my_state.exclusive_or_expression_table_num=0;

//--------------------initialize and_expression_table
    my_state.and_expression_table=(struct and_expression_infor **)malloc(AND_EXPRESSION_TABLE_NUM*sizeof(struct and_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.and_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer and_expression_table  error!");
        my_state.error_int=10122;
        error_quit();
    }
    memset(my_state.and_expression_table, 0x00, AND_EXPRESSION_TABLE_NUM*sizeof(struct and_expression_infor  *));
    my_state.and_expression_table_num=0;

//--------------------initialize equality_expression_table
    my_state.equality_expression_table=(struct equality_expression_infor **)malloc(EQUALITY_EXPRESSION_TABLE_NUM*sizeof(struct equality_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.equality_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer equality_expression_table  error!");
        my_state.error_int=10123;
        error_quit();
    }
    memset(my_state.equality_expression_table, 0x00, EQUALITY_EXPRESSION_TABLE_NUM*sizeof(struct equality_expression_infor  *));
    my_state.equality_expression_table_num=0;

//--------------------initialize relational_expression_table
    my_state.relational_expression_table=(struct relational_expression_infor **)malloc(RELATIONAL_EXPRESSION_TABLE_NUM*sizeof(struct relational_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.relational_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer relational_expression_table  error!");
        my_state.error_int=10124;
        error_quit();
    }
    memset(my_state.relational_expression_table, 0x00, RELATIONAL_EXPRESSION_TABLE_NUM*sizeof(struct relational_expression_infor  *));
    my_state.relational_expression_table_num=0;

//--------------------initialize shift_expression_table
    my_state.shift_expression_table=(struct shift_expression_infor **)malloc(SHIFT_EXPRESSION_TABLE_NUM*sizeof(struct shift_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.shift_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer shift_expression_table  error!");
        my_state.error_int=10125;
        error_quit();
    }
    memset(my_state.shift_expression_table, 0x00, SHIFT_EXPRESSION_TABLE_NUM*sizeof(struct shift_expression_infor  *));
    my_state.shift_expression_table_num=0;

//--------------------initialize additive_expression_table
    my_state.additive_expression_table=(struct additive_expression_infor **)malloc(ADDICTIVE_EXPRESSION_TABLE_NUM*sizeof(struct additive_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.additive_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer additive_expression_table  error!");
        my_state.error_int=10126;
        error_quit();
    }
    memset(my_state.additive_expression_table, 0x00, ADDICTIVE_EXPRESSION_TABLE_NUM*sizeof(struct additive_expression_infor  *));
    my_state.additive_expression_table_num=0;

//--------------------initialize multiplicative_expression_table
    my_state.multiplicative_expression_table=(struct multiplicative_expression_infor **)malloc(MULTIPLICATIVE_EXPRESSION_TABLE_NUM*sizeof(struct multiplicative_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.multiplicative_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer multiplicative_expression_table  error!");
        my_state.error_int=10127;
        error_quit();
    }
    memset(my_state.multiplicative_expression_table, 0x00, MULTIPLICATIVE_EXPRESSION_TABLE_NUM*sizeof(struct multiplicative_expression_infor  *));
    my_state.multiplicative_expression_table_num=0;

//--------------------initialize cast_expression_table
    my_state.cast_expression_table=(struct cast_expression_infor **)malloc(CAST_EXPRESSION_TABLE_NUM*sizeof(struct cast_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.cast_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer cast_expression_table  error!");
        my_state.error_int=10128;
        error_quit();
    }
    memset(my_state.cast_expression_table, 0x00, CAST_EXPRESSION_TABLE_NUM*sizeof(struct cast_expression_infor  *));
    my_state.cast_expression_table_num=0;

//--------------------initialize unary_expression_table
    my_state.unary_expression_table=(struct unary_expression_infor **)malloc(UNARY_EXPRESSION_TABLE_NUM*sizeof(struct unary_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.unary_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer unary_expression_table  error!");
        my_state.error_int=10129;
        error_quit();
    }
    memset(my_state.unary_expression_table, 0x00, UNARY_EXPRESSION_TABLE_NUM*sizeof(struct unary_expression_infor  *));
    my_state.unary_expression_table_num=0;

//--------------------initialize postfix_expression_table
    my_state.postfix_expression_table=(struct postfix_expression_infor **)malloc(POSTFIX_EXPRESSION_TABLE_NUM*sizeof(struct postfix_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.postfix_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer postfix_expression_table  error!");
        my_state.error_int=10130;
        error_quit();
    }
    memset(my_state.postfix_expression_table, 0x00, POSTFIX_EXPRESSION_TABLE_NUM*sizeof(struct postfix_expression_infor  *));
    my_state.postfix_expression_table_num=0;

//--------------------initialize primary_expression_table
    my_state.primary_expression_table=(struct primary_expression_infor **)malloc(PRIMARY_EXPRESSION_TABLE_NUM*sizeof(struct primary_expression_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.primary_expression_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer primary_expression_table  error!");
        my_state.error_int=10131;
        error_quit();
    }
    memset(my_state.primary_expression_table, 0x00, PRIMARY_EXPRESSION_TABLE_NUM*sizeof(struct primary_expression_infor  *));
    my_state.primary_expression_table_num=0;

//--------------------initialize IDENTIFIER_table
    my_state.IDENTIFIER_table=(struct IDENTIFIER_infor **)malloc(IDENTIFIER_TABLE_NUM*sizeof(struct IDENTIFIER_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.IDENTIFIER_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer IDENTIFIER_table  error!");
        my_state.error_int=10131;
        error_quit();
    }
    memset(my_state.IDENTIFIER_table, 0x00, IDENTIFIER_TABLE_NUM*sizeof(struct IDENTIFIER_infor  *));
    my_state.IDENTIFIER_table_num=0;

//--------------------initialize symbol_a_table
    my_state.symbol_a_table=(struct symbol_a_infor **)malloc(SYMBOL_A_TABLE_NUM*sizeof(struct symbol_a_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.symbol_a_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer symbol_a_table  error!");
        my_state.error_int=10131;
        error_quit();
    }
    memset(my_state.symbol_a_table, 0x00, SYMBOL_A_TABLE_NUM*sizeof(struct symbol_a_infor  *));
    my_state.symbol_a_table_num=0;


//--------------------initialize instruction_table
    my_state.instruction_table=(struct instruction_infor **)malloc(INSTRUCTION_TABLE_NUM*sizeof(struct instruction_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.instruction_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer instruction_table  error!");
        my_state.error_int=10131;
        error_quit();
    }
    memset(my_state.instruction_table, 0x00, INSTRUCTION_TABLE_NUM*sizeof(struct instruction_infor  *));
    my_state.instruction_table_num=0;


//--------------------initialize function_definition_table
    my_state.function_definition_table=(struct function_definition_infor **)malloc(FUNCTION_DEFINITION_TABLE_NUM*sizeof(struct function_definition_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.function_definition_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer function_definition_table  error!");
        my_state.error_int=10131;
        error_quit();
    }
    memset(my_state.function_definition_table, 0x00, FUNCTION_DEFINITION_TABLE_NUM*sizeof(struct function_definition_infor  *));
    my_state.function_definition_table_num=0;

//--------------------initialize struct_or_union_specifier_table
    my_state.struct_or_union_specifier_table=(struct struct_or_union_specifier_infor **)malloc(STRUCT_OR_UNION_SPECIFIER_TABLE_NUM*sizeof(struct struct_or_union_specifier_infor *));
    //printf("alibaba my_state.declarator_table:%x\n", my_state.declarator_table);
    if(0x00==my_state.struct_or_union_specifier_table)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: malloc initializer struct_or_union_specifier_table  error!");
        my_state.error_int=10131;
        error_quit();
    }
    memset(my_state.struct_or_union_specifier_table, 0x00, STRUCT_OR_UNION_SPECIFIER_TABLE_NUM*sizeof(struct struct_or_union_specifier_infor  *));
    my_state.struct_or_union_specifier_table_num=0;



//-----------------------------------------------------------------------------------------------------------------------

//===================table end

//-------------------initialize scope_list
    initialize_scope_list();
    /*for(i=0; i<SCOPE_NUMBER; i++)
    {
        my_state.cs_scope_list[i]=-1;
    }*/

//-------------------initialize scope_stack
    initialize_scope_stack();

//-------------------initialize scope_current
    my_state.scope_current=0;    


//-------------------not used
    my_state.translation_unit_node=0x00;

//------------------what are we dealing with
    my_state.deal_type=-1;
    my_state.deal_node_index=-1;
    my_state.deal_data1=-1;


    return 0;
}

int destroy_compiler_state()
{
    if(1==my_state.need_dot_file)
    {
        char *dot_stop="}\n";
        write(my_state.dot_file_fd, dot_stop, strlen(dot_stop));
        close(my_state.dot_file_fd);
    }
    free(my_state.symbol_table);
    my_state.symbol_table=0x00;
    free(my_state.node_table);
    my_state.node_table=0x00;

    return 0;
}

int deal_taint_file()
{
  FILE * taint_fd=fopen(my_state.taint_file_str, "r");
  int i=0;
  char taint_buf[MID_MAX_BUF];
  int line_tmp=0;
  int level_tmp=0;
  char name_tmp[MID_MAX_BUF];
  if(taint_fd==0x00)
  {
    snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/compiler_state.c: open taint_file(%s)  error!", my_state.taint_file_str);
    my_state.error_int=10131;
    error_quit();
  }
  
  while(0x00!=fgets(taint_buf, MID_MAX_BUF, taint_fd))
  {
    sscanf(taint_buf, "%d %s %d", &line_tmp, name_tmp, &level_tmp);
    strncpy(my_state.taint_name_array[i], name_tmp, strlen(name_tmp));
    my_state.taint_line_array[i]=line_tmp;
    my_state.taint_level_array[i]=level_tmp; 
    i+=1;
  }

  my_state.taint_num=i;
  fclose(taint_fd);
  return 0;
}

int print_taint_source()
{
  int i=0;
  printf("start taint_source_information start:  ===================\n");
  for(i=0; i<my_state.taint_num; ++i)
  {
    printf("line_num:%d name:%s level:%d\n", my_state.taint_line_array[i], my_state.taint_name_array[i], my_state.taint_level_array[i]); 
  }
  printf("stop  taint_source_information strop   ===================\n");
  return 0;
}















