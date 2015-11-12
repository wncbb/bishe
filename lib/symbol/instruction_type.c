#include "instruction_type.h"

char *instruction_type_str[]= {

    "assignment_ins",  //  11  =
    "mul1_assignment_ins", // 12 *=
    "mul2_assignment_ins", // 13 /=
    "mul3_assignment_ins", // 14 %=
    "add1_assignment_ins", // 15 +=
    "add2_assignment_ins", // 16 -=
    "shift1_assignment_ins", //17 <<=
    "shift2_assignment_ins", //18 >>=
    "and_assignment_ins",          //19 &
    "exclusive_or_assignment_ins", //20 ^
    "inclusive_or_assignment_ins", //21 |
    "inc_op_unary_ins", //22 ++data
    "dec_op_unary_ins", //23 --data
    "ta_op_unary_ins", //24 &data  take address
    "rta_op_unary_ins", //25 *data
    "positive_unary_ins", //26 +data
    "negative_unary_ins", //27 -data
    "bit_reverse_unary_ins", //28 ~data
    "negation_unary_ins", //29 !data
    "sizeof_unary_ins", //30 sizeof unary_expression
    "sizeof_type_ins",  //31 sizeof (type_name)
    "alignof_type_ins", //32 alignof(type_name)

    "bracket_postfix_ins", //33 postfix_expression[]
    "parentheses_postfix_ins", //34 postfix_expression()

    "conditional_exp_ins", //35 logical_or_expression ? expression : conditional_expression
    
    "logical_or_exp_ins", //36 OR_OP  ||
    "logical_and_exp_ins", //37 AND_OP  &&

    "inclusive_or_exp_ins", //38 |
    "exclusive_or_exp_ins", //39 ^
    "and_exp_ins", //40 &

    "eq_op_ins", //41 ==
    "ne_op_ins", //42 !=

    "l_op_ins", //43 <
    "g_op_ins", //44 >
    "le_op_ins", //45 <=
    "ge_op_ins", //46 >=

    "l_shift_op_ins", //47 <<
    "r_shift_op_ins", //48 >>

    "add1_op_ins", //49 +
    "add2_op_ins", //50 -

    "mul1_op_ins", //51 *
    "mul2_op_ins", //52 /
    "mul3_op_ins", //53 %

    "type_op_ins", //54 (type_name) cast_expression

    "just_IDENTIFIER_ins", //55 just IDENTIFIER

    "expression_ins", //56 expression(not expression_statement)
    "compound_statement_ins", //57 compound_statement

    "selection_statement_0_ins", // 58 IF (expression) statement ELSE statement
    "selection_statement_1_ins", // 59 IF (expression) statement
    "selection_statement_2_ins", // 60 SWITCH (expression) statement

    "labeled_statement_0_ins", // 61 IDENTIFIER: statement
    "labeled_statement_1_ins", // 62 CASE constant_expression: statement
    "labeled_statement_2_ins", // 63 DEFAULT: statement

    "jump_statement_0_ins", // 64 GOTO IDENTIFIER ;
    "jump_statement_1_ins", // 65 CONTINUE ;
    "jump_statement_2_ins", // 66 BREAK ;
    "jump_statement_3_ins", // 67 RETURN ;
    "jump_statement_4_ins", // 68 RETURN expression ;

    "iteration_statement_0_ins", //69 WHILE(expression) statement
    "iteration_statement_1_ins", //70 DO statement WHILE(expression)
    "iteration_statement_2_ins", //71 FOR(expression_statement expression_statement) statement
    "iteration_statement_3_ins", //72 FOR(expression_statement expression_statement expression) statement
    "iteration_statement_4_ins", //73 FOR(declaration expression_statement ) statement
    "iteration_statement_5_ins", //74 FOR(declaration expression_statement expression) statement


};









