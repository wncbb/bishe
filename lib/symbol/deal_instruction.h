#ifndef DEAL_INSTRUCTION_H
#define DEAL_INSTRUCTION_H


//------------------------------------------20150428 start ----------

struct ins_range{
    int start;
    int end;
};

struct ins_set_one{
    int index;
    struct ins_set_one * next;
};

struct ins_set{
    int num;
    struct ins_set_one * head;
    struct ins_set_one * tail;
};

struct instruction_infor{
    int index;
    int sequence;
    int node_index;
    int prev;
    int next;
    int ins_type;
    int ins_data1;
    int ins_data2;
    int ins_data3;
    int ins_ret;
    int ins_taint_level;
    int ins_taint_src;
    int ins_set_num;
    struct ins_set  ins_set_o;
};



struct compound_statement_infor2{
    int index;
    int statement_number;
    int declaration_number;
    int symbol_a_number;

};



//------------------------------------------20150428 end ------------

#endif


int print_instruction_infor(int index);
int print_instruction_table();

int cur_index_instruction();

int alter_instruction_ins_data1(int index, int ins_data1);
int alter_instruction_ins_data2(int index, int ins_data2);
int alter_instruction_ins_data3(int index, int ins_data3);
int alter_instruction_ins_ret(int index, int ins_ret);

int add_instruction_table_num();
int ret_instruction(int index);
int add_instruction(int in_type, int in_data1, int in_data2, int in_data3, int in_ret, int node_index);
int add_set_instruction(int index, int set_index);
int deal_assignment_expression_infor(int index);
int deal_unary_expression_infor(int index);
int deal_postfix_expression_infor(int index);
int deal_primary_expression_infor(int index);
int deal_IDENTIFIER_expression_infor(int index);
int deal_conditional_expression_infor(int index);
int deal_logical_or_expression_infor(int index);
int deal_logical_and_expression_infor(int index);
int deal_inclusive_or_expression_infor(int index);
int deal_exclusive_or_expression_infor(int index);
int deal_and_expression_infor(int index);
int deal_equality_expression_infor(int index);
int deal_relational_expression_infor(int index);
int deal_shift_expression_infor(int index);
int deal_additive_expression_infor(int index);
int deal_multiplicative_expression_infor(int index);
int deal_cast_expression_infor(int index);


//--------------------------------------20150518

int deal_statement_infor(int index);

int deal_expression_infor(int index);

int deal_compound_statement_infor(int index);
int deal_selection_statement_infor(int index);

int taint_spread_ins(int from_id, int to_id);
int taint_spread_cmp_smbla(int from_id, int to_id, struct instruction_infor * ins_ptr);
int taint_spread_smbla(int from_id, int to_id, struct instruction_infor * ins_ptr);
int check_ins_data_taint(int ins_index);

int taint_2smbla(int ins_data1, int ins_data2, int ins_ret, struct instruction_infor * ins_ptr);

int taint_retsmbla_2_insself(int ins_ret, struct instruction_infor * ins_ptr);

int taint_1ins_2_insself(int ins_data1, struct instruction_infor * ins_ptr);


