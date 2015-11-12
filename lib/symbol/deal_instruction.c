#include <stdio.h>
#include <stdlib.h>

#include "deal_instruction.h"
#include "smbl_function_definition.h"
#include "instruction_type.h"

#include "symbol.h"
#include "../compiler_state.h"

#include "../node/node.h"

extern char *instruction_type_str[]; //coming from instruction_type.c

extern char *node_type_str[]; //coming from ../node/node_type.c
extern struct compiler_state my_state;
// postorder traversal


int print_instruction_infor(int index)
{
    struct ins_set_one * iso_ptr=NULL;
    int i=0;
    struct instruction_infor * ptr=my_state.instruction_table[index];
    struct node_my * node_ptr=NULL;
    if(ptr!=NULL)
    {
        node_ptr=my_state.node_table[ptr->node_index];
        printf("index:%d sequence:%d node_index:%d prev:%d next:%d ins_type:%d ins_set_num:%d\n", ptr->index, ptr->sequence, ptr->node_index, ptr->prev, ptr->next, ptr->ins_type, ptr->ins_set_num);
        printf("line_num:%d inst_type:%d ins_ret:%d ins_data1:%d ins_data2:%d ins_data3:%d\n", node_ptr->node_line_num, ptr->ins_type, ptr->ins_ret, ptr->ins_data1, ptr->ins_data2, ptr->ins_data3);
        if(ptr->ins_type-11>=0)
        {
            printf("instruction description: %s(%d)\n", instruction_type_str[ptr->ins_type-11], ptr->ins_type);
        }
        else
        {
            printf("instruction description: not known(%d)\n", ptr->ins_type);
        }
        iso_ptr=ptr->ins_set_o.head;
        for(i=0; i<ptr->ins_set_o.num; ++i)
        {
            if(iso_ptr!=NULL)
            {
                printf("including %d instruction: %d\n", i, iso_ptr->index);
            }
            else
            {
                printf("including NULL\n");
            }
            iso_ptr=iso_ptr->next;
        }
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_instruction_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= instruction_table                        =\n");
    printf(    "============================================\n");
    printf("instruction_table_num:%d\n", my_state.instruction_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.instruction_table_num; ++i)
    {
        print_instruction_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}



int cur_index_instruction()
{
    return my_state.instruction_table_num;
}

int add_instruction_table_num()
{
    my_state.instruction_table_num+=1;
    return my_state.instruction_table_num;
}

int ret_instruction(int index)
{
    if(index==-1)
    {
        return -1;
    }
    struct instruction_infor * ins_ptr=my_state.instruction_table[index];
    return ins_ptr->ins_ret;
}

int alter_instruction_ins_data1(int index, int ins_data1)
{
    struct instruction_infor * infor_ptr=my_state.instruction_table[index];
    if(ins_data1!=-2)
    {
        infor_ptr->ins_data1=ins_data1;
    }
    return index;
}

int alter_instruction_ins_data2(int index, int ins_data2)
{
    struct instruction_infor * infor_ptr=my_state.instruction_table[index];
    if(ins_data2!=-2)
    {
        infor_ptr->ins_data2=ins_data2;
    }
    return index;
}
int alter_instruction_ins_data3(int index, int ins_data3)
{
    struct instruction_infor * infor_ptr=my_state.instruction_table[index];
    if(ins_data3!=-2)
    {
        infor_ptr->ins_data3=ins_data3;
    }
    return index;
}
int alter_instruction_ins_ret(int index, int ins_ret)
{
    struct instruction_infor * infor_ptr=my_state.instruction_table[index];
    if(ins_ret!=-2)
    {
        infor_ptr->ins_ret=ins_ret;
    }
    return index;
}
int add_instruction(int in_type, int in_data1, int in_data2, int in_data3, int in_ret, int node_index)
{
    static int test=-1;
    test+=1;
    printf("0521r:%d %d\n", test, in_type);
    
    int index=add_instruction_table_num()-1;
    int sequence=0;
    int prev=0;
    int next=0;
    int ins_type=in_type;
    int ins_data1=in_data1;
    int ins_data2=in_data2;
    int ins_data3=in_data3;
    int ins_ret  =in_ret;

    struct instruction_infor * infor_ptr=(struct instruction_infor*)malloc(sizeof(struct instruction_infor));
    if(infor_ptr==NULL)
    {
        printf("%s %d malloc wrong!\n", __FILE__, __LINE__);
        exit(-1);
    }
    else
    {
        my_state.instruction_table[index]=infor_ptr;
    }
    infor_ptr->index=index;
    infor_ptr->sequence=index;
    infor_ptr->node_index=node_index;
    infor_ptr->prev=prev;
    infor_ptr->next=next;
    infor_ptr->ins_type=ins_type;
    infor_ptr->ins_data1=ins_data1;
    infor_ptr->ins_data2=ins_data2;
    infor_ptr->ins_data3=ins_data3;
    infor_ptr->ins_ret  =ins_ret;
    infor_ptr->ins_set_o.num=0;
    infor_ptr->ins_set_o.head=NULL;
    infor_ptr->ins_set_o.tail=NULL;
    return index;
}

int add_set_instruction(int index, int set_index)
{
    struct instruction_infor * infor_ptr=my_state.instruction_table[index];
    struct ins_set_one  *iso_ptr=(struct ins_set_one*)malloc(sizeof(struct ins_set_one));

    infor_ptr->ins_set_num+=1;
    iso_ptr->index=set_index;
    iso_ptr->next =NULL;

    infor_ptr->ins_set_o.num+=1;
    
    if(infor_ptr->ins_set_o.head==NULL)
    {
        infor_ptr->ins_set_o.head=iso_ptr;
        infor_ptr->ins_set_o.tail=iso_ptr;
    }
    else
    {
        infor_ptr->ins_set_o.tail->next=iso_ptr;
        infor_ptr->ins_set_o.tail=iso_ptr;
    }


}


int deal_assignment_expression_infor(int index)
{
    printf("0521abc:%d\n", index);
    printf("0515aa %d\n", index);
    struct assignment_expression_infor * a_e_infor_ptr=my_state.assignment_expression_table[index];
    /*
     0 ---- conditional_expression
     1 ----  =
     2 ---- *=
     3 ---- /=
     4 ---- %=
     5 ---- +=
     6 ---- -=
     7 ----<<=
     8 ---->>=
     9 ---- &=
    10 ---- ^=
    11 ---- |=
    */
    int category   =a_e_infor_ptr->category;
    int node_index =a_e_infor_ptr->node_index;
    int data1_index=a_e_infor_ptr->data1_index; //unary_expression or conditional_expression
    int data2_index=a_e_infor_ptr->data2_index; //assignment_expression

    int ret=-1;
    int ins_type=-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct instruction_infor * ins_ptr=NULL;
    
    printf("\n0514a\n");
    switch(category)
    {
        case  0:
            printf("\n0514r1  %d %d\n", index, data1_index);
            ins_index=deal_conditional_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514r2\n");
            break;
        case  1:
            printf("\n0514b\n");
            ins_type=assignment_ins; // = (11)

            ins_index=deal_unary_expression_infor(data1_index);  //all return the index of instruction
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            
            break;
        case  2:
            ins_type=mul1_assignment_ins; // *= (12)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);

            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  3:
            ins_type=mul2_assignment_ins; // /= (13)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data1=ret_instruction(ins_index);

            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  4:
            ins_type=mul3_assignment_ins; // %= (14)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);

            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  5:
            ins_type=add1_assignment_ins; // += (15)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);

            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  6:
            ins_type=add2_assignment_ins; // -= (16)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);

            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            
            break;
        case  7:
            ins_type=shift1_assignment_ins; // <<= (17)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            
            break;
        case  8:
            ins_type=shift2_assignment_ins; // >>= (18)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            
            break;
        case  9:
            ins_type=and_assignment_ins; // & (19)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            
            break;
        case 10:
            ins_type=exclusive_or_assignment_ins; // ^ (20)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);

            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            
            break;
        case 11:
            ins_type=inclusive_or_assignment_ins; // | (21)
            ins_index=deal_unary_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_assignment_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);

            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            
            break;
        default:
            break;
          
    }
    printf("\n0514c\n");

    return ret;
}
//-------------------------20150513-------------start
int deal_unary_expression_infor(int index)
{
    struct unary_expression_infor * infor_ptr=my_state.unary_expression_table[index];
    int category  =infor_ptr->category;
    int node_index =infor_ptr->node_index;
    int data_index=infor_ptr->data_index;

    //compound_id == action_scope
    int compound_id=my_state.node_table[node_index]->node_compound_id;

    int ret=-1;
    int ins_type=-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    /*
    unary_expression:
                     0.postfix_expression
                     1.INC_OP unary_expression
                     2.DEC_OP unary_expression
                     3.unary_operator cast_expression
                     4.SIZEOF unary_expression
                     5.SIZEOF (type_name)
                     6.ALIGNOF (type_name)
    */
    switch(category)
    {
        case  0:
            ins_index=deal_postfix_expression_infor(data_index);
            ret=ins_index;
            break;
        case  1:
            ins_type=inc_op_unary_ins; //22 ++data
            ins_index=deal_unary_expression_infor(data_index);
            ins_ret=ret_instruction(ins_index);
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);

            break;
        case  2:
            ins_type=dec_op_unary_ins; //23 --data
            ins_index=deal_unary_expression_infor(data_index);
            ins_ret=ret_instruction(ins_index);
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  3:
            ins_type=ta_op_unary_ins; //24 &data
            ins_index=deal_cast_expression_infor(data_index);

            ins_ret=symbol_a_add(compound_id, node_index);
            alter_symbol_a_s_type(ins_ret, 4);
            ins_data1=ins_index;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  4:
            ins_type=rta_op_unary_ins; //25 *data
            ins_index=deal_cast_expression_infor(data_index);

            ins_ret=symbol_a_add(compound_id, node_index);
            alter_symbol_a_s_type(ins_ret, 4);
            ins_data1=ins_index;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  5:
            ins_type=positive_unary_ins; //26 +data
            ins_index=deal_cast_expression_infor(data_index);

            ins_ret=symbol_a_add(compound_id, node_index);
            alter_symbol_a_s_type(ins_ret, 4);
            ins_data1=ins_index;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);

            break;
        case  6:
            ins_type=negative_unary_ins; //27 -data
            ins_index=deal_cast_expression_infor(data_index);

            ins_ret=symbol_a_add(compound_id, node_index);
            alter_symbol_a_s_type(ins_ret, 4);
            ins_data1=ins_index;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  7:
            ins_type=bit_reverse_unary_ins; //28 ~data
            ins_index=deal_cast_expression_infor(data_index);

            ins_ret=symbol_a_add(compound_id, node_index);
            alter_symbol_a_s_type(ins_ret, 4);
            ins_data1=ins_index;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  8:
            ins_type=negation_unary_ins; //29 !data
            ins_index=deal_cast_expression_infor(data_index);

            ins_ret=symbol_a_add(compound_id, node_index);
            alter_symbol_a_s_type(ins_ret, 4);
            ins_data1=ins_index;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case  9:
            ins_type=sizeof_unary_ins; //30 sizeof unary_expression
            break;
        case 10:
            ins_type=sizeof_type_ins; //31 sizeof type
            break;
        case 11:
            ins_type=alignof_type_ins; //32 alignof type
            break;
        default:
            break;
    }

    return ret;
}

int deal_postfix_expression_infor(int index)
{
    struct postfix_expression_infor * infor_ptr=my_state.postfix_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type=-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    switch(category)
    {
      case  0:
          ins_index=deal_primary_expression_infor(data1_index);
          ret=ins_index;
          break;
      case  1:
          break;
      case  2:
          break;
      case  3:
          break;
      case  4:
          break;
      case  5:
          break;
      case  6:
          break;
      case  7:
          break;
      case  8:
          break;
      case  9:
          break;
      default:
          break;
    }

    return ret;
}

int deal_primary_expression_infor(int index)
{
    struct primary_expression_infor * infor_ptr=my_state.primary_expression_table[index];
    int category  =infor_ptr->category;
    int node_index =infor_ptr->node_index;
    int data_index=infor_ptr->data_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    switch(category)
    {
        case 0:
            ins_index=deal_IDENTIFIER_infor(data_index);
            ret=ins_index;
            break;
        case 1:
            printf("here is the constant\n");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
    printf("01519\n");
    return ret;
}

int deal_IDENTIFIER_infor(int index)
{
    if(index==-1)
    {
        return -2;
    }
    struct IDENTIFIER_infor * infor_ptr=my_state.IDENTIFIER_table[index];
    int symbol_a_index=infor_ptr->symbol_a_index;
    int node_index    =infor_ptr->node_index;
    int ret=-1;
    int ins_type=just_IDENTIFIER_ins;
    int ins_data1=symbol_a_index;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret=symbol_a_index;
    int ins_index=-1;

    ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);

    return ret;

}


/*
conditional_expression:
                       logical_or_expression
                       logical_or_expression ? expression : conditional_expression
*/
int deal_conditional_expression_infor(int index)
{
    
    struct conditional_expression_infor * infor_ptr=my_state.conditional_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;
    int data3_index=infor_ptr->data3_index;
    
    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;

    switch(category)
    {
        case 0:
            printf("\n0514c1 %d\n", data1_index);
            ins_index=deal_logical_or_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514c2\n");
            break;
        case 1:
            ///*
            ins_type=conditional_exp_ins;
            ins_index=deal_logical_or_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);

            ins_index=deal_conditional_expression_infor(data3_index);
            ins_data3=ret_instruction(ins_index);

            ins_ret  =ins_data1;
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            //*/
            break;
        default:
            break;
    }
    return ret;
}

int deal_logical_or_expression_infor(int index)
{
    struct logical_or_expression_infor * infor_ptr=my_state.logical_or_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;


    int compound_id=my_state.node_table[node_index]->node_compound_id;

    //logical_or_expression:
    //                      logical_and_expression
    //                      logical_or_expression OR_OP logical_and_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514l1 %d\n", data1_index);
            ins_index=deal_logical_and_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514l2\n");
            break;
        case 1:
            ///*
            ins_type=logical_or_exp_ins; //OR_OP(||) 36
            ins_index=deal_logical_or_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_logical_and_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            //s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            //s_a_infor_ptr->s_type=4;
            alter_symbol_a_s_type(ins_ret, 4);
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ///*
            break;
        default:
            break;
    }

    return ret;
}

int deal_logical_and_expression_infor(int index)
{
    struct logical_and_expression_infor * infor_ptr=my_state.logical_and_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;
    
    int compound_id=my_state.node_table[node_index]->node_compound_id;

    //logical_or_expression:
    //                      inclusive_or_expression
    //                      logical_and_expression AND_OP inclusive_or_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514a1 %d\n", data1_index);
            ins_index=deal_inclusive_or_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514a2\n");
            break;
        case 1:
            ///*
            ins_type=logical_and_exp_ins; //AND_OP(&&) 37
            ins_index=deal_logical_and_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_inclusive_or_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }

    return ret;
}

int deal_inclusive_or_expression_infor(int index)
{
    struct inclusive_or_expression_infor * infor_ptr=my_state.inclusive_or_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;


    int compound_id=my_state.node_table[node_index]->node_compound_id;

    //inclusive_or_expression:
    //                      exclusive_or_expression
    //                      inclusive_or_expression | exclusive_or_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514i1 %d\n", data1_index);
            ins_index=deal_exclusive_or_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514i2\n");
            break;
        case 1:
            ///*
            ins_type=inclusive_or_exp_ins; //inclusive_or (|) 38
            ins_index=deal_inclusive_or_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_exclusive_or_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }

    return ret;
}


int deal_exclusive_or_expression_infor(int index)
{
    struct exclusive_or_expression_infor * infor_ptr=my_state.exclusive_or_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;
    
    int compound_id=my_state.node_table[node_index]->node_compound_id;
    
    //exclusive_or_expression:
    //                        and_expression
    //                        exclusive_or_expression ^ and_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514e1 %d\n", data1_index);
            ins_index=deal_and_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514e2\n");
            break;
        case 1:
            ///*
            ins_type=exclusive_or_exp_ins; //exclusive_or (^) 39
            ins_index=deal_exclusive_or_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_and_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }

    return ret;
}

int deal_and_expression_infor(int index)
{
    struct and_expression_infor * infor_ptr=my_state.and_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;
    
    int compound_id=my_state.node_table[node_index]->node_compound_id;
    
    //and_expression:
    //                        equality_expression
    //                        and_expression & equality_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514n1 %d\n", data1_index);
            ins_index=deal_equality_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514n2\n");
            break;
        case 1:
            ///*
            ins_type=and_exp_ins; // (&) 40
            ins_index=deal_and_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_equality_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }

    return ret;
}

int deal_equality_expression_infor(int index)
{
    struct equality_expression_infor * infor_ptr=my_state.equality_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;

    int compound_id=my_state.node_table[node_index]->node_compound_id;

    //equality_expression:
    //                    relational_expression
    //                    equality_expression EQ_OP relational_expression
    //                    equality_expression NE_OP relational_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514q1 %d\n", data1_index);
            ins_index=deal_relational_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514q2\n");
            break;
        case 1:
            ///*
            ins_type=eq_op_ins; // (==) 41
            ins_index=deal_equality_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_relational_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case 2:
            ins_type=ne_op_ins; // (!=) 42
            ins_index=deal_equality_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_relational_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }

    return ret;
}

int deal_relational_expression_infor(int index)
{
    struct relational_expression_infor * infor_ptr=my_state.relational_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;

    int compound_id=my_state.node_table[node_index]->node_compound_id;
    
    //relational_expression:
    //                      shift_expression
    //                      relational_expression < shift_expression
    //                      relational_expression > shift_expression
    //                      relational_expression <= shift_expression
    //                      relational_expression >= shift_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514o1 %d\n", data1_index);
            ins_index=deal_shift_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514o2\n");
            break;
        case 1:
            ///*
            ins_type=l_op_ins; // (<) 43
            ins_index=deal_relational_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);

            ins_index=deal_shift_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        case 2:
            ///*
            ins_type=g_op_ins; // (>) 44
            ins_index=deal_relational_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_shift_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        case 3:
            ///*
            ins_type=le_op_ins; // (<=) 45
            ins_index=deal_relational_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_shift_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        case 4:
            ///*
            ins_type=ge_op_ins; // (>=) 46
            ins_index=deal_relational_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_shift_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }

    return ret;
}

int deal_shift_expression_infor(int index)
{
    struct shift_expression_infor * infor_ptr=my_state.shift_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;

    int compound_id=my_state.node_table[node_index]->node_compound_id;

    //shift_expression:
    //                      additive_expression
    //                      shift_expression << additive_expression
    //                      shift_expression >> additive_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514t1 %d\n", data1_index);
            ins_index=deal_additive_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514t2\n");
            break;
        case 1:
            ///*
            ins_type=l_shift_op_ins; // (<<) 47
            ins_index=deal_shift_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_additive_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        case 2:
            ///*
            ins_type=r_shift_op_ins; // (>>) 48
            ins_index=deal_shift_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_additive_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }

    return ret;
}


int deal_additive_expression_infor(int index)
{
    printf("20150515b:%d\n", index);
    
    struct additive_expression_infor * infor_ptr=my_state.additive_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;

    int compound_id=my_state.node_table[node_index]->node_compound_id;

    //additive_expression:
    //                    multiplicative_expression
    //                    additive_expression + multiplicative_expression
    //                    additive_expression - multiplicative_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514v1\n");
            ins_index=deal_multiplicative_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514v2\n");
            break;
        case 1:
            ///*
            printf("20150515a:%d\n", index);
            ins_type=add1_op_ins; // (+) 49
            ins_index=deal_additive_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_multiplicative_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        case 2:
            ///*
            ins_type=add2_op_ins; // (-) 50
            ins_index=deal_additive_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_multiplicative_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }

    return ret;
}

int deal_multiplicative_expression_infor(int index)
{
    struct multiplicative_expression_infor * infor_ptr=my_state.multiplicative_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;

    int compound_id=my_state.node_table[node_index]->node_compound_id;

    //multiplicative_expression:
    //                          cast_expression
    //                          multiplicative_expression * cast_expression
    //                          multiplicative_expression / case_expression
    //                          multiplicative_expression % cast_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            printf("\n0514u1\n");
            ins_index=deal_cast_expression_infor(data1_index);
            ret=ins_index;
            printf("\n0514u2\n");
            break;
        case 1:
            ///*
            ins_type=mul1_op_ins; // (*) 51
            ins_index=deal_multiplicative_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_cast_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        case 2:
            ///*
            ins_type=mul2_op_ins; // (/) 52
            ins_index=deal_multiplicative_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_cast_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
        case 3:
            ///*
            ins_type=mul3_op_ins; // (%) 53
            ins_index=deal_multiplicative_expression_infor(data1_index);
            ins_data1=ret_instruction(ins_index);
            
            ins_index=deal_cast_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }
    printf("\n0514u3\n");

    return ret;
}

int deal_cast_expression_infor(int index)
{
    struct cast_expression_infor * infor_ptr=my_state.cast_expression_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;

    int compound_id=my_state.node_table[node_index]->node_compound_id;

    //cast_expression:
    //                unary_expression
    //                (type_name) cast_expression
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;

    int ret=-1;
    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    int ins_index=-1;
    struct symbol_a_infor * s_a_infor_ptr=NULL;

    switch(category)
    {
        case 0:
            ins_index=deal_unary_expression_infor(data1_index);
            ret=ins_index;
            break;
        case 1:
            ///*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_index=deal_cast_expression_infor(data2_index);
            ins_data2=ret_instruction(ins_index);

            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            
            ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            break;
            //*/
        default:
            break;
    }

    return ret;
}


//---------------------------------------20150515











int deal_statement_infor(int index)
{
    /*
    statement:
              0 labeled_statement
              1 compound_statement
              2 expression_statement
              3 selection_statement
              4 iteration_statement
              5 jump_statement
    struct statement_infor{
        int index;
        int node_index;
        int category;
        int data_index;
    };
    */
    struct statement_infor * infor_ptr=my_state.statement_table[index];
    int category   =infor_ptr->category;
    int node_index =infor_ptr->node_index;
    int data_index=infor_ptr->data_index;
    int ret=-1;
    

    switch(category)
    {
        case 0:
            ret=deal_labeled_statement_infor(data_index);
            break;
        case 1:
            ret=deal_compound_statement_infor(data_index);
            break;
        case 2:
            ret=deal_expression_statement_infor(data_index);
            break;
        case 3:
            ret=deal_selection_statement_infor(data_index);
            printf("659a:%d\n", ret);
            printf("659a2:%d\n", my_state.instruction_table_num);
            break;
        case 4:
            ret=deal_iteration_statement_infor(data_index);
            break;
        case 5:
            printf("%s:%d 0525a\n", __FILE__, __LINE__);
            ret=deal_jump_statement_infor(data_index);
            printf("%s:%d 052ba\n", __FILE__, __LINE__);
            break;
        default:
            break;
    }

    return ret;
}

int deal_expression_statement_infor(int index)
{
    int ret=-1;
    struct expression_statement_infor * infor_ptr=my_state.expression_statement_table[index];
    int node_index=infor_ptr->node_index;
    int category  =infor_ptr->category;
    int data_index=infor_ptr->data_index;

    ret=deal_expression_infor(data_index);

    return ret;
}

int deal_compound_statement_infor(int index)
{
    struct compound_statement_infor * infor_ptr=my_state.compound_statement_table[index];
    int block_item_num =infor_ptr->block_item_num;
    int node_index     =infor_ptr->node_index;
    struct block_item_infor * next=infor_ptr->next;

    printf("343b:%d block_item_num:%d\n", index, block_item_num);
    int ret=0;

    int i=0;
    int cur_ins_index=-1;
    int is_statement=-1;
    int data_index  =-1;
    int child_index =-1;
    int start_ins_index=-1;
    int   end_ins_index=-1;

    int ins_type=compound_statement_ins;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;

    int ins_tmp=-1;

    cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
    ret=cur_ins_index;
    printf("701a:%d\n", cur_ins_index);
    printf("701a:%d\n", my_state.instruction_table_num);
    for(i=0; i<block_item_num; ++i)
    {
        is_statement=next->is_statement;
        data_index  =next->data_index;
        child_index =next->child_index;
        if(is_statement)
        {
            printf("343a:%d\n", data_index);
            ins_tmp=deal_statement_infor(data_index);
            printf("657a:%d\n", ins_tmp);
            add_set_instruction(cur_ins_index, ins_tmp);

        }
        else
        {
            //deal_declaration_infor(data_index);
        }
        next=next->next;

    }



    struct symbol_a_infor * s_a_infor_ptr=NULL;
    return ret;
}

int deal_expression_infor(int index)
{
    int ret=-1;
    struct expression_infor * infor_ptr=my_state.expression_table[index];
    int node_index=infor_ptr->node_index;
    int data_num  =infor_ptr->data_num;
    int data_index=infor_ptr->data_index;
    int cur_index =data_index;
    int ins_tmp=-1;
    int start_ins_index=cur_index_instruction();
    
    int ins_type=expression_ins;
    int ins_data1=start_ins_index;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    ret=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
    int cur_ins_index  =cur_index_instruction()-1;  //cur_index_instruction return the next instruction which is not assigned

    while(cur_index!=-1)
    {
        printf("0521:aaa %d\n", cur_index);
        ins_tmp=deal_assignment_expression_infor(cur_index);
        add_set_instruction(cur_ins_index, ins_tmp);
        ins_ret=ret_instruction(ins_tmp);
        struct assignment_expression_infor * a_e_infor_ptr=my_state.assignment_expression_table[cur_index];
        cur_index=a_e_infor_ptr->next_index;
        printf("0521:aaa\n");
    }
    int end_ins_index=cur_index_instruction()-1;
    ins_data2=  end_ins_index;

    alter_instruction_ins_data2(cur_ins_index, ins_data2);





    printf("0521c: start_ins_index:end_ins_index  %d:%d\n", start_ins_index, end_ins_index);



    return ret;
}

/*
iteration_statement:
                    0.WHILE(expression) statement
                    1.DO statement WHILE(expression)
                    2.FOR(expression_statement expression_statement) statement
                    3.FOR(expression_statement expression_statement expression) statement
                    4.FOR(declaration expression_statement) statement
                    5.FOR(declaration expression_statement expression) statement
*/
int deal_iteration_statement_infor(int index)
{
    struct iteration_statement_infor *infor_ptr=my_state.iteration_statement_table[index];
    int category   =infor_ptr->category;
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;
    int data3_index=infor_ptr->data3_index;
    int data4_index=infor_ptr->data4_index;
    int node_index =infor_ptr->node_index;


    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    
    int cur_ins_index=-1;

    int ret=-1;

    switch(category)
    {
        case 0: //WHILE(expression) statement
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=iteration_statement_0_ins;
            printf("0521s:%d\n", ins_type);
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            ins_data1=deal_expression_infor(data1_index);
            ins_data2= deal_statement_infor(data2_index);
            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);

            break;
        case 1: //DO statement WHILE(expression)
            
            ins_type=iteration_statement_1_ins;
            printf("0521s:%d\n", ins_type);
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            ins_data1= deal_statement_infor(data1_index);
            ins_data2=deal_expression_infor(data2_index);
            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);
            
            break;
        case 2: //FOR(expression_statement expression_statement) statement
            ins_type=iteration_statement_2_ins;
            printf("0521s:%d\n", ins_type);
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            ins_data1=deal_expression_statement_infor(data1_index);
            ins_data2=deal_expression_statement_infor(data2_index);
            ins_data3=deal_statement_infor(data3_index);

            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);

            break;
        case 3: //FOR(expression_statement expression_statement expression) statement
            ins_type=iteration_statement_3_ins;
            printf("0521s:%d\n", ins_type);
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            ins_data1=deal_expression_statement_infor(data1_index);
            ins_data2=deal_expression_statement_infor(data2_index);
            ins_data3=deal_expression_infor(data3_index);
            ins_ret  =deal_statement_infor(data4_index);

            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);

            break;
        case 4: //FOR(declaration expression_statement) statement
            ins_type=iteration_statement_4_ins;
            printf("0521s:%d\n", ins_type);
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            //ins_data1=deal_declaration_infor(data1_index);
            ins_data2=deal_expression_statement_infor(data2_index);
            ins_data3=deal_statement_infor(data3_index);

            //alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);

            break;
        case 5: //FOR(declaration expression_statement expression) statement
            ins_type=iteration_statement_5_ins;
            printf("0521s:%d\n", ins_type);
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            //ins_data1=deal_declaration_infor(data1_index);
            ins_data2=deal_expression_statement_infor(data2_index);
            ins_data3=deal_expression_infor(data3_index);
            ins_ret  =deal_statement_infor(data4_index);

            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);

            break;
        default:
            break;
    }


    return ret;
}




/*
jump_statement:
               0.GOTO IDENTIFIER ;
               1.CONTINUE ;
               2.BREAK ;
               3.RETURN;
               4.RETURN expression ;
*/
int deal_jump_statement_infor(int index)
{
    struct jump_statement_infor *infor_ptr=my_state.jump_statement_table[index];
    int node_index =infor_ptr->node_index;
    int category   =infor_ptr->category;
    int data_index=infor_ptr->data_index;


    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    
    int cur_ins_index=-1;

    int ret=-1;
    int tmp_index=-1;

    switch(category)
    {
        case 0:  //GOTO IDENTIFIER ;
            printf("%s:%d 0525c\n", __FILE__, __LINE__);
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id,node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=jump_statement_0_ins;
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            printf("%s:%d 0525d %d\n", __FILE__, __LINE__, data_index);

            //ins_data1 : IDENTIFIER's ins_ret
            //ins_data2 : statement's ins_ret
            //ins_data3 : statement's instruction index
            //ins_ret   : statement;s ins_ret

            tmp_index=deal_IDENTIFIER_infor(data_index);
            printf("%s:%d 0525e\n", __FILE__, __LINE__);
            ins_data1=ret_instruction(tmp_index);




            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);

            break;
        case 1:  // CONTINUE ;
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=jump_statement_1_ins;
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;

            //ins_data1 : constant_expression's ins_ret
            //ins_data2 : statement's ins_ret
            //ins_data3 : statement's instruction index
            //ins_ret   : statement;s ins_ret

            //tmp_index=deal_constant_expression_infor(data1_index);
            //ins_data1=ret_instruction(tmp_index);


            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);
            break;
        case 2: //BREAK;
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=jump_statement_2_ins;
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;

            //ins_data1 : IDENTIFIER's ins_ret
            //ins_data2 : statement's ins_ret
            //ins_data3 : statement's instruction index
            //ins_ret   : statement;s ins_ret


            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);
            break;
        case 3: //RETURN;
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=jump_statement_3_ins;
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;

            //ins_data1 : IDENTIFIER's ins_ret
            //ins_data2 : statement's ins_ret
            //ins_data3 : statement's instruction index
            //ins_ret   : statement;s ins_ret


            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);
            break;
        case 4:  //RETURN expression ;
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=jump_statement_4_ins;
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;

            //ins_data1 : IDENTIFIER's ins_ret
            //ins_data2 : statement's ins_ret
            //ins_data3 : statement's instruction index
            //ins_ret   : statement;s ins_ret

            tmp_index=deal_expression_infor(data_index);
            ins_data1=ret_instruction(tmp_index);
            ins_ret  =ins_data1;



            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);

            break;
        default:
            break;
    }


    return ret;
}





/*
labeled_statement:
                  0.IDENTIFIER : statement
                  1.CASE constant_expression : statement
                  2.DEFAULT : statement
*/
int deal_labeled_statement_infor(int index)
{
    struct labeled_statement_infor *infor_ptr=my_state.labeled_statement_table[index];
    int node_index =infor_ptr->node_index;
    int category   =infor_ptr->category;
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;


    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    
    int cur_ins_index=-1;

    int ret=-1;
    int tmp_index=-1;

    switch(category)
    {
        case 0:  //IDENTIFIER: statement
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=labeled_statement_0_ins;
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;

            //ins_data1 : IDENTIFIER's ins_ret
            //ins_data2 : statement's ins_ret
            //ins_data3 : statement's instruction index
            //ins_ret   : statement;s ins_ret

            tmp_index=deal_IDENTIFIER_infor(data1_index);
            ins_data1=ret_instruction(tmp_index);

            tmp_index=deal_statement_infor(data2_index);
            ins_data2=ret_instruction(tmp_index);

            ins_data3=tmp_index;

            ins_ret=ins_data2;  

            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);

            break;
        case 1:  //CASE constant_expression : statement
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=labeled_statement_1_ins;
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;

            //ins_data1 : constant_expression's ins_ret
            //ins_data2 : statement's ins_ret
            //ins_data3 : statement's instruction index
            //ins_ret   : statement;s ins_ret

            //tmp_index=deal_constant_expression_infor(data1_index);
            //ins_data1=ret_instruction(tmp_index);

            tmp_index=deal_statement_infor(data2_index);
            ins_data2=ret_instruction(tmp_index);

            ins_data3=tmp_index;

            ins_ret=ins_data2;  

            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);
            break;
        case 2:
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=labeled_statement_2_ins;
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;

            //ins_data1 : IDENTIFIER's ins_ret
            //ins_data2 : statement's ins_ret
            //ins_data3 : statement's instruction index
            //ins_ret   : statement;s ins_ret

            tmp_index=deal_statement_infor(data1_index);
            ins_data1=ret_instruction(tmp_index);
            ins_data2=tmp_index;
            ins_ret=ins_data1;  

            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_ret(cur_ins_index, ins_ret);
            break;
        default:
            break;
    }


    return ret;
}





/*
selection_statement:
                    IF ( expression ) statement ELSE statement
                    IF ( expression ) statement
                    SWITCH ( expression ) statement
*/
int deal_selection_statement_infor(int index)
{
    struct selection_statement_infor *infor_ptr=my_state.selection_statement_table[index];
    int category   =infor_ptr->category;
    int data1_index=infor_ptr->data1_index;
    int data2_index=infor_ptr->data2_index;
    int data3_index=infor_ptr->data3_index;
    int node_index =infor_ptr->node_index;


    int ins_type =-1;
    int ins_data1=-1;
    int ins_data2=-1;
    int ins_data3=-1;
    int ins_ret  =-1;
    
    int cur_ins_index=-1;

    int ret=-1;

    switch(category)
    {
        case 0:
            /*
            ins_type=type_op_ins; // (type_name) 54
            //ins_data1=deal_type_name_expression_infor(data1_index);
            ins_data2=deal_cast_expression_infor(data2_index);
            
            ins_ret=symbol_a_add(compound_id, node_index);
            s_a_infor_ptr=my_state.symbol_a_table[ins_ret];
            s_a_infor_ptr->s_type=4;
            */
            ins_type=selection_statement_0_ins;
            printf("0521s:%d\n", ins_type);
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            ins_data1=deal_expression_infor(data1_index);
            ins_data2=deal_statement_infor(data2_index);
            ins_data3=deal_statement_infor(data3_index);
            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            alter_instruction_ins_data3(cur_ins_index, ins_data3);

            break;
        case 1:
            
            ins_type=selection_statement_1_ins;
            printf("0521s:%d\n", ins_type);
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            ins_data1=deal_expression_infor(data1_index);
            ins_data2=deal_statement_infor(data2_index);
            //ins_data3=deal_statement_infor(data3_index);
            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            //alter_instruction_ins_data3(cur_ins_index, ins_data3);
            
            break;
        case 2:
            ins_type=selection_statement_2_ins;
            printf("0521s:%d\n", ins_type);
            cur_ins_index=add_instruction(ins_type, ins_data1, ins_data2, ins_data3, ins_ret, node_index);
            ret=cur_ins_index;
            ins_data1=deal_expression_infor(data1_index);
            ins_data2=deal_statement_infor(data2_index);
            //ins_data3=deal_statement_infor(data3_index);
            alter_instruction_ins_data1(cur_ins_index, ins_data1);
            alter_instruction_ins_data2(cur_ins_index, ins_data2);
            //alter_instruction_ins_data3(cur_ins_index, ins_data3);

            break;
        default:
            break;
    }


    return ret;
}










