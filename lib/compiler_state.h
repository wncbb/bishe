#include "scope.h"


#ifndef GLOBAL_H
#define GLOBAL_H

#define SYMBOL_MAX_NUMBER 65536
#define NODE_MAX_NUMBER   65536
#define ERROR_STR_NUMBER 100
#define FILE_NAME_LENGTH 100

#define OTHER_NODE_MAX_NUMBER 65536

#define DECLARATION_SPECIFIERS_TABLE_NUM 1024
#define DIRECT_DECLARATOR_TABLE_NUM 1024
#define COMPOUND_STATEMENT_TABLE_NUM 1024

#define DECLARATION_TABLE_NUM 1024
#define INIT_DECLARATOR_TABLE_NUM 1024
#define INITIALIZER_TABLE_NUM 1024
#define INITIALIZER_LIST_TABLE_NUM 1024
#define INITIALIZER_LIST_ONE_TABLE_NUM 1024 
#define DECLARATOR_TABLE_NUM 1024
#define BLOCK_ITEM_TABLE_NUM 1024

#define STATEMENT_TABLE_NUM 1024

#define JUMP_STATEMENT_TABLE_NUM 1024
#define ITERATION_STATEMENT_TABLE_NUM 1024
#define SELECTION_STATEMENT_TABLE_NUM 1024
#define LABELED_STATEMENT_TABLE_NUM 1024
#define EXPRESSION_STATEMENT_TABLE_NUM 1024

#define EXPRESSION_TABLE_NUM 1024

#define ASSIGNMENT_EXPRESSION_TABLE_NUM 1024
#define CONDITIONAL_EXPRESSION_TABLE_NUM 1024
#define LOGICAL_OR_EXPRESSION_TABLE_NUM 1024
#define LOGICAL_AND_EXPRESSION_TABLE_NUM 1024
#define INCLUSIVE_OR_EXPRESSION_TABLE_NUM 1024
#define EXCLUSIVE_OR_EXPRESSION_TABLE_NUM 1024
#define AND_EXPRESSION_TABLE_NUM 1024
#define EQUALITY_EXPRESSION_TABLE_NUM 1024
#define RELATIONAL_EXPRESSION_TABLE_NUM 1024
#define SHIFT_EXPRESSION_TABLE_NUM 1024
#define ADDICTIVE_EXPRESSION_TABLE_NUM 1024
#define MULTIPLICATIVE_EXPRESSION_TABLE_NUM 1024
#define CAST_EXPRESSION_TABLE_NUM 1024
#define UNARY_EXPRESSION_TABLE_NUM 1024
#define POSTFIX_EXPRESSION_TABLE_NUM 1024
#define PRIMARY_EXPRESSION_TABLE_NUM 1024

#define STRUCT_OR_UNION_SPECIFIER_TABLE_NUM 1024


#define FUNCTION_DEFINITION_TABLE_NUM 1024

#define IDENTIFIER_TABLE_NUM 1024

#define SYMBOL_A_TABLE_NUM 1024
#define INSTRUCTION_TABLE_NUM 4096

#define PARAMETER_LIST_TABLE_NUM 1024 
#define PARAMETER_DECLARATION_TABLE_NUM 1024

#define TAINT_MAX_NUM 1024
#define MID_MAX_BUF 1024

struct compiler_state
{
    struct symbol_my **symbol_table;
    int symbol_max_number;
    int symbol_number;
    
    struct node_my **node_table;
    int node_max_number;
    int node_number;

    char c_file_str[FILE_NAME_LENGTH];
    FILE *c_file_fd;

    int need_dot_file;
    char dot_file_str[FILE_NAME_LENGTH];
    int dot_file_fd;

    int need_taint_file;
    char taint_file_str[FILE_NAME_LENGTH];
    int taint_file_fd;
    char taint_name_array[TAINT_MAX_NUM][FILE_NAME_LENGTH];
    int taint_line_array[TAINT_MAX_NUM];
    int taint_level_array[TAINT_MAX_NUM];
    int taint_num; 

    int need_infor;

    char error_str[ERROR_STR_NUMBER];
    int error_int;

//table declaration_specifiers
    struct declaration_specifiers_infor ** declaration_specifiers_table;
    int declaration_specifiers_table_num;

//table direct_declarator
    struct direct_declarator_infor ** direct_declarator_table;
    int direct_declarator_table_num;

//table compound_statement
    struct compound_statement_infor ** compound_statement_table;
    int compound_statement_table_num;    

//--------------------------------------------------------------------------

//table block_item
    struct block_item_infor ** block_item_table;
    int block_item_table_num;

//table declaration
    struct declaration_infor ** declaration_table;
    int declaration_table_num;

//table init_declarator
    struct init_declarator_infor ** init_declarator_table;
    int init_declarator_table_num;

//table initializer
    struct initializer_infor ** initializer_table;
    int initializer_table_num;

//table initializer_list
    struct initializer_list_infor ** initializer_list_table;
    int initializer_list_table_num;

//table initializer_list_one
    struct initializer_list_one_infor ** initializer_list_one_table;
    int initializer_list_one_table_num;

//table declarator_table
    struct declarator_infor ** declarator_table;
    int declarator_table_num; 

//--------------------------------------------------------------------------
//-----------------------------------------20150327 start--------------------------

//table statement
    struct statement_infor ** statement_table;
    int statement_table_num;


//table jump_statement
    struct jump_statement_infor ** jump_statement_table;
    int jump_statement_table_num;

//table iteration_statement
    struct iteration_statement_infor ** iteration_statement_table;
    int iteration_statement_table_num;

//table selection_statement
    struct selection_statement_infor ** selection_statement_table;
    int selection_statement_table_num;

//table labeled_statement
    struct labeled_statement_infor ** labeled_statement_table;
    int labeled_statement_table_num;

//table expression_statement
    struct expression_statement_infor ** expression_statement_table;
    int expression_statement_table_num;

//table expression
    struct expression_infor ** expression_table;
    int expression_table_num;
 
//table assignement_expression
    struct assignment_expression_infor ** assignment_expression_table;
    int assignment_expression_table_num;

//table conditional_expression
    struct conditional_expression_infor ** conditional_expression_table;
    int conditional_expression_table_num;

//table logical_or_expression
    struct logical_or_expression_infor ** logical_or_expression_table;
    int logical_or_expression_table_num;

//table logical_and_expression
    struct logical_and_expression_infor ** logical_and_expression_table;
    int logical_and_expression_table_num;

//table inclusive_or_expression
    struct inclusive_or_expression_infor ** inclusive_or_expression_table;
    int inclusive_or_expression_table_num;

//table exclusive_or_expression
    struct exclusive_or_expression_infor ** exclusive_or_expression_table;
    int exclusive_or_expression_table_num;

//table and_expression
    struct and_expression_infor ** and_expression_table;
    int and_expression_table_num;

//table equality_expression
    struct equality_expression_infor ** equality_expression_table;
    int equality_expression_table_num;

//table relational_expression
    struct relational_expression_infor ** relational_expression_table;
    int relational_expression_table_num;

//table shift_expression
    struct shift_expression_infor ** shift_expression_table;
    int shift_expression_table_num;

//table additive_expression
    struct additive_expression_infor ** additive_expression_table;
    int additive_expression_table_num;
 
//table multiplicative expression
    struct multiplicative_expression_infor ** multiplicative_expression_table;
    int multiplicative_expression_table_num;

//table cast_expression
    struct cast_expression_infor ** cast_expression_table;
    int cast_expression_table_num;

//table unary_expression
    struct unary_expression_infor ** unary_expression_table;
    int unary_expression_table_num;

//table postfix_expression
    struct postfix_expression_infor ** postfix_expression_table;
    int postfix_expression_table_num;

//table primary_expression
    struct primary_expression_infor ** primary_expression_table;
    int primary_expression_table_num;

//table IDENTIFIER
    struct IDENTIFIER_infor ** IDENTIFIER_table;
    int IDENTIFIER_table_num;

//table function_definition
    struct function_definition_infor ** function_definition_table;
    int function_definition_table_num;


//-----------------------------------------20150327 end  --------------------------

//-----------------------------------------20160104 start
  struct parameter_list_infor ** parameter_list_table;
  int parameter_list_table_num;
  
  struct parameter_declaration_infor ** parameter_declaration_table;
  int parameter_declaration_table_num;



//-----------------------------------------20160104 stop





//-------------------scope
    struct scope_list cs_scope_list;
    struct scope_stack cs_scope_stack;
    int scope_current;    




//-------------------not used yet
    struct node_my *translation_unit_node;

    struct node_my **external_declaration_table;
    int external_declaration_number;

//------------------- what we are dealing now
    int deal_type; //just like node_type
    int deal_node_index; //
    int deal_data1;

//------------------- symbol_a
    struct symbol_a_infor ** symbol_a_table;
    int symbol_a_table_num;

//------------------ instruction_table
    struct instruction_infor ** instruction_table;
    int instruction_table_num;

//------------------ struct_or_union_specifier_table
    struct struct_or_union_specifier_infor ** struct_or_union_specifier_table;
    int struct_or_union_specifier_table_num;
};

#endif

int print_compiler_state();
int initialize_compiler_state(int node_max_num, int symbol_max_num);
int destroy_compiler_state();

int deal_taint_file();
int print_taint_source();





