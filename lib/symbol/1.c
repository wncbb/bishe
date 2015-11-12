int check_ins_data_taint(int ins_index)
{
  struct instruction_infor *ins_ptr=my_state.instruction_table[ins_index];
  int ins_data1=ins_ptr->ins_data1;
  int ins_data2=ins_ptr->ins_data2;
  int ins_data3=ins_ptr->ins_data3;
  int ins_ret=ins_ptr->ins_ret;
  struct symbol_a_infor *smbl_a_data1_ptr=NULL;
  struct symbol_a_infor *smbl_a_data2_ptr=NULL;
  struct symbol_a_infor *smbl_a_data3_ptr=NULL;
  struct symbol_a_infor *smbl_a_ret_ptr=NULL;

  if(ins_data1>=0)
  {
    smbl_a_data1_ptr=my_state.symbol_a_table[ins_data1];
  }

  if(ins_data2>=0)
  {
    smbl_a_data2_ptr=my_state.symbol_a_table[ins_data2];
  }

  if(ins_data3>=0)
  {
    smbl_a_data3_ptr=my_state.symbol_a_table[ins_data3];
  }
  
  if(ins_ret>=0)
  {
    smbl_a_ret_ptr=my_state.symbol_a_table[ins_ret];
  }

  int ins_type=ins_ptr->ins_type;
  int tmp_taint_level=0;
  switch(ins_type)
  {
    case assignment_ins:  //  11  =
      taint_spread(ins_data1, ins_ret);
      break;
    case mul1_assignment_ins: // 12 *=
      taint_spread(ins_data1, ins_ret);
      break;
    case mul2_assignment_ins: // 13 /=
      taint_spread(ins_data1, ins_ret);
      break;
    case mul3_assignment_ins: // 14 %=
      taint_spread(ins_data1, ins_ret);
      break;
    case add1_assignment_ins: // 15 +=
      taint_spread(ins_data1, ins_ret);
      break;
    case add2_assignment_ins: // 16 -=
      taint_spread(ins_data1, ins_ret);
      break;
    case shift1_assignment_ins: //17 <<=
      taint_spread(ins_data1, ins_ret);
      break;
    case shift2_assignment_ins: //18 >>=
      taint_spread(ins_data1, ins_ret);
      break;
    case and_assignment_ins:          //19 &
      taint_spread(ins_data1, ins_ret);
      break;
    case exclusive_or_assignment_ins: //20 ^
      taint_spread(ins_data1, ins_ret);
      break;
    case inclusive_or_assignment_ins: //21 |
      taint_spread(ins_data1, ins_ret);
      break;
    //unary_expression
    case inc_op_unary_ins: //22 ++data
      break;
    case dec_op_unary_ins: //23 --data
      break;
    case ta_op_unary_ins: //24 &data  take address
      break;
    case rta_op_unary_ins: //25 *data
      break;
    case positive_unary_ins: //26 +data
      break;
    case negative_unary_ins: //27 -data
      break;
    case bit_reverse_unary_ins: //28 ~data
      break;
    case negation_unary_ins: //29 !data
      break;
    case sizeof_unary_ins: //30 sizeof unary_expression
      break;
    case sizeof_type_ins:  //31 sizeof (type_name)
      break;
    case alignof_type_ins: //32 alignof(type_name)
      break;

    case bracket_postfix_ins: //33 postfix_expression[]
      break;
    case parentheses_postfix_ins: //34 postfix_expression()
      break;

    case conditional_exp_ins: //35 logical_or_expression ? expression : conditional_expression
      break;
    
    case logical_or_exp_ins: //36 OR_OP  ||
      break;
    case logical_and_exp_ins: //37 AND_OP  &&
      break;

    case inclusive_or_exp_ins: //38 |
      break;
    case exclusive_or_exp_ins: //39 ^
      break;
    case and_exp_ins: //40 &
      break;

    case eq_op_ins: //41 ==
      break;
    case ne_op_ins: //42 !=
      break;

    case l_op_ins: //43 <
      break;
    case g_op_ins: //44 >
      break;
    case le_op_ins: //45 <=
      break;
    case ge_op_ins: //46 >=
      break;

    case l_shift_op_ins: //47 <<
      break;
    case r_shift_op_ins: //48 >>
      break;

    case add1_op_ins: //49 +
      if(smbl_a_data1_ptr->taint_m > smbl_a_data2_ptr->taint_m)
      {
        taint_spread(ins_data1, ins_ret);
      }
      else
      {
        taint_spread(ins_data2, ins_ret);
      }

      break;
    case add2_op_ins: //50 -
      break;

    case mul1_op_ins: //51 *
      break;
    case mul2_op_ins: //52 /
      break;
    case mul3_op_ins: //53 %
      break;

    case type_op_ins: //54 (type_name) cast_expression
      break;
      
    case just_IDENTIFIER_ins: //55 just IDENTIFI]ER
      taint_spread(ins_data1, ins_ret); 
      break;

    case expression_ins: //56 expresssion(not expression_statement)
      break;

    case compound_statement_ins: //57 compound_statement
      break;

    case selection_statement_0_ins: //58 IF(expression) statement ELSE statement
      break;
    case selection_statement_1_ins: //59 IF(expression) statement
      break;
    case selection_statement_2_ins: //60 SWITCH (expression) statement
      break;

    case labeled_statement_0_ins: //61 IDENTIFIER: statement
      break;
    case labeled_statement_1_ins: //62 CASE constant_expression : statement
      break;
    case labeled_statement_2_ins: //63 DEFAULT: statement
      break;

    case jump_statement_0_ins: //64 GOTO IDENTIFIER;
      break;
    case jump_statement_1_ins: //65 CONTINUE;
      break;
    case jump_statement_2_ins: //66 BREAK;
      break;
    case jump_statement_3_ins: //67 RETURN;
      break;
    case jump_statement_4_ins: //68 RETURN expression;
      break;

    case iteration_statement_0_ins: //69 WHILE(expression) statement
      break;
    case iteration_statement_1_ins: //70 DO statement WHILE(expression)
      break;
    case iteration_statement_2_ins: //71 FOR(expression_statement expression_statement) statement
      break;
    case iteration_statement_3_ins: //72 FOR(expression_statement expression_statement expression) statement
      break;
    case iteration_statement_4_ins: //73 FOR(declaration expression_statement) statement
      break;
    case iteration_statement_5_ins: //74 FOR(declaration expression_statement expression) statement
      break;
    default: 
      break;
  }
  return 0;
}
