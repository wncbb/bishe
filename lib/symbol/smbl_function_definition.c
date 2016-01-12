#include <stdio.h>
#include <stdlib.h>

#include "smbl_function_definition.h"
#include "deal_instruction.h"
#include "instruction_type.h"

#include "symbol.h"
#include "../compiler_state.h"

#include "../node/node.h"


char *storage_class_specifier_str[]={
    "none", //--------------------------- 0
    "TYPEDEEF(typedef)", //-------------- 1
    "EXTERN(extern)", //----------------- 2
    "STATIC(static)", //----------------- 3
    "THREAD_LOCAL(thread_local)", //----- 4
    "AUTO(auto)", //--------------------- 5
    "REGISTER(register)", //------------- 6  
};



char * type_specifier_str_0[]={
    "default", //-------------------- 0x0000_0000 default
    "void", //----------------------- 0x0000_0001 void
    "char", //----------------------- 0x0000_0002 char
    "int", //------------------------ 0x0000_0003 int
    "float", //---------------------- 0x0000_0004 float
    "double", //--------------------- 0x0000_0005 double
    "bool", //----------------------- 0x0000_0006 bool
    "complex", //-------------------- 0x0000_0007 complex
    "imaginary", //------------------ 0x0000_0008 imaginary
    "atomic_type_specifier", //------ 0x0000_0009 atomic_type_specifier
    "struct_or_union_specifier", //-- 0x0000_000a struct_or_union_specifier
    "enum_specifier", //------------- 0x0000_000b enum_specifier
    "TYPEDEF_NAME", //--------------- 0x0000_000c TYPEDEF_NAME   
};

char * type_specifier_str_1[]={
    "signed", //----signed(0)
    "unsigned", //--unsigned(1) 
};

char * type_specifier_str_2[]={
    "default", //-----------default(0)
    "short", //-------------short(1)
    "long", //--------------long(2)
    "longlong", //----------longlong(3)
};


char * type_specifier_str[]={
    "none", //---------------------------------  0
    "void", //---------------------------------  1
    "bool", //---------------------------------  2

    "singed   char", //------------------------  3
    "unsigned char", //------------------------  4
 
    "signed   short int", //-------------------  5
    "unsigned short int", //-------------------  6
    "signed   int", //-------------------------  7
    "unsigned int", //-------------------------  8
    "signed   long int", //--------------------  9
    "unsigned long int", //-------------------- 10
    "signed   long long int", //--------------- 11
    "unsigned long long int", //--------------- 12

    "float", //-------------------------------- 13
    "double", //------------------------------- 14
    "long double", //-------------------------- 15

    "complex", //------------------------------ 16
    "imaginary", //---------------------------- 17
    "atomic_type_specifier", //---------------- 18
    "struct_or_union_specifier", //------------ 19

    "enum_specifier", //----------------------- 20

    "TYPEDEF_NAME",  //------------------------- 21
};

char * type_qualifier_str[]={
    "none", //------------ 0x0000_0000
    "const", //----------- 0x0000_0001
    "restrict", //-------- 0x0000_0002
    "volatile", //-------- 0x0000_0004
    "atomic", //---------- 0x0000_0008
    
};

char * function_specifier_str[]={
    "none", //----------------------- 0x0000_0000
    "INLINE(inline)", //------------- 0x0000_0001
    "NORETURN(noreturn)", //--------- 0x0000_0002
};

extern char * node_type_str[];

extern struct compiler_state my_state;


//-----------------------------------------------------------------
//-------------------------------20150328 start--------------------
int print_function_definition_infor(int index)
{
    struct function_definition_infor * ptr=my_state.function_definition_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d data3_index:%d data4_index:%d inst_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index, ptr->data3_index, ptr->data4_index, ptr->inst_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_function_definition_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= function_definition_table                =\n");
    printf(    "============================================\n");
    printf("function_definition_table_num:%d\n", my_state.function_definition_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.function_definition_table_num; ++i)
    {
        print_function_definition_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_struct_or_union_specifier_infor(int index)
{
    struct struct_or_union_specifier_infor * ptr=my_state.struct_or_union_specifier_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d \n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_struct_or_union_specifier_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= struct_or_union_specifier_table          =\n");
    printf(    "============================================\n");
    printf("struct_or_union_specifier_table_num:%d\n", my_state.struct_or_union_specifier_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.struct_or_union_specifier_table_num; ++i)
    {
        print_struct_or_union_specifier_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int add_function_definition_infor(int node_index, int category, int data1_index, int data2_index, int data3_index, int data4_index, int inst_index)
{
    int cur_index=add_function_definition_table_num()-1;
    struct function_definition_infor * infor_ptr=(struct function_definition_infor *)malloc(sizeof(struct function_definition_infor));
    if(infor_ptr==NULL)
    {
        printf("%s:%d add_function_definition_infor func malloc wrong!\n", __FILE__, __LINE__);
        return -1;
    }
    my_state.function_definition_table[cur_index]=infor_ptr;
    infor_ptr->index      =cur_index;
    infor_ptr->node_index =node_index;
    infor_ptr->category   =category;
    infor_ptr->data1_index=data1_index;
    infor_ptr->data2_index=data2_index;
    infor_ptr->data3_index=data3_index;
    infor_ptr->data4_index=data4_index;
    infor_ptr->inst_index=inst_index;
    return cur_index;
}


int print_statement_infor(int index)
{
    struct statement_infor * ptr=my_state.statement_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data_index:%d \n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_statement_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= statement_table                          =\n");
    printf(    "============================================\n");
    printf("statement_table_num:%d\n", my_state.statement_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.statement_table_num; ++i)
    {
        print_statement_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_jump_statement_infor(int index)
{
    struct jump_statement_infor * ptr=my_state.jump_statement_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data_index:%d \n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_jump_statement_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= jump_statement_table                     =\n");
    printf(    "============================================\n");
    printf("jump_statement_table_num:%d\n", my_state.jump_statement_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.jump_statement_table_num; ++i)
    {
        print_jump_statement_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_iteration_statement_infor(int index)
{
    struct iteration_statement_infor * ptr=my_state.iteration_statement_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d data3_index:%d data4_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index, ptr->data3_index, ptr->data4_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_iteration_statement_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= iteration_statement_table                =\n");
    printf(    "============================================\n");
    printf("iteration_statement_table_num:%d\n", my_state.iteration_statement_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.iteration_statement_table_num; ++i)
    {
        print_iteration_statement_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_selection_statement_infor(int index)
{
    struct selection_statement_infor * ptr=my_state.selection_statement_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d data3_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index, ptr->data3_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_selection_statement_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= selection_statement_table                =\n");
    printf(    "============================================\n");
    printf("selection_statement_table_num:%d\n", my_state.selection_statement_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.selection_statement_table_num; ++i)
    {
        print_selection_statement_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_labeled_statement_infor(int index)
{
    struct labeled_statement_infor * ptr=my_state.labeled_statement_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_labeled_statement_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= labeled_statement_table                  =\n");
    printf(    "============================================\n");
    printf("labeled_statement_table_num:%d\n", my_state.labeled_statement_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.labeled_statement_table_num; ++i)
    {
        print_labeled_statement_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_expression_statement_infor(int index)
{
    struct expression_statement_infor * ptr=my_state.expression_statement_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d data_index:%d \n", \
        ptr->index, ptr->node_index, ptr->data_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_expression_statement_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= expression_statement_table               =\n");
    printf(    "============================================\n");
    printf("expression_statement_table_num:%d\n", my_state.expression_statement_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.expression_statement_table_num; ++i)
    {
        print_expression_statement_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_expression_infor(int index)
{
    struct expression_infor * ptr=my_state.expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d data_num:%d data_index:%d \n", \
        ptr->index, ptr->node_index, ptr->data_num, ptr->data_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= expression_table                         =\n");
    printf(    "============================================\n");
    printf("expression_table_num:%d\n", my_state.expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.expression_table_num; ++i)
    {
        print_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_assignment_expression_infor(int index)
{
    struct assignment_expression_infor * ptr=my_state.assignment_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d next_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index, ptr->next_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_assignment_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= assignment_expression_table              =\n");
    printf(    "============================================\n");
    printf("assignment_expression_table_num:%d\n", my_state.assignment_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.assignment_expression_table_num; ++i)
    {
        print_assignment_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_conditional_expression_infor(int index)
{
    struct conditional_expression_infor * ptr=my_state.conditional_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d data3_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index, ptr->data3_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_conditional_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= conditional_expression_table             =\n");
    printf(    "============================================\n");
    printf("conditional_expression_table_num:%d\n", my_state.conditional_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.conditional_expression_table_num; ++i)
    {
        print_conditional_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_logical_or_expression_infor(int index)
{
    struct logical_or_expression_infor * ptr=my_state.logical_or_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_logical_or_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= logical_or_expression_table              =\n");
    printf(    "============================================\n");
    printf("logical_or_expression_table_num:%d\n", my_state.logical_or_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.logical_or_expression_table_num; ++i)
    {
        print_logical_or_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}
int print_logical_and_expression_infor(int index)
{
    struct logical_and_expression_infor * ptr=my_state.logical_and_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_logical_and_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= logical_and_expression_table             =\n");
    printf(    "============================================\n");
    printf("logical_and_expression_table_num:%d\n", my_state.logical_and_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.logical_and_expression_table_num; ++i)
    {
        print_logical_and_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_inclusive_or_expression_infor(int index)
{
    struct inclusive_or_expression_infor * ptr=my_state.inclusive_or_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_inclusive_or_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= inclusive_or_expression_table            =\n");
    printf(    "============================================\n");
    printf("inclusive_or_expression_table_num:%d\n", my_state.inclusive_or_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.inclusive_or_expression_table_num; ++i)
    {
        print_inclusive_or_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_exclusive_or_expression_infor(int index)
{
    struct exclusive_or_expression_infor * ptr=my_state.exclusive_or_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_exclusive_or_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= exclusive_or_expression_table            =\n");
    printf(    "============================================\n");
    printf("exclusive_or_expression_table_num:%d\n", my_state.exclusive_or_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.exclusive_or_expression_table_num; ++i)
    {
        print_exclusive_or_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_and_expression_infor(int index)
{
    struct and_expression_infor * ptr=my_state.and_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_and_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= and_expression_table                     =\n");
    printf(    "============================================\n");
    printf("and_expression_table_num:%d\n", my_state.and_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.and_expression_table_num; ++i)
    {
        print_and_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_equality_expression_infor(int index)
{
    struct equality_expression_infor * ptr=my_state.equality_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_equality_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= equality_expression_table                =\n");
    printf(    "============================================\n");
    printf("equality_expression_table_num:%d\n", my_state.equality_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.equality_expression_table_num; ++i)
    {
        print_equality_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_relational_expression_infor(int index)
{
    struct relational_expression_infor * ptr=my_state.relational_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_relational_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= relational_expression_table              =\n");
    printf(    "============================================\n");
    printf("relational_expression_table_num:%d\n", my_state.relational_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.relational_expression_table_num; ++i)
    {
        print_relational_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_shift_expression_infor(int index)
{
    struct shift_expression_infor * ptr=my_state.shift_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_shift_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= shift_expression_table                   =\n");
    printf(    "============================================\n");
    printf("shift_expression_table_num:%d\n", my_state.shift_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.shift_expression_table_num; ++i)
    {
        print_shift_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_additive_expression_infor(int index)
{
    struct additive_expression_infor * ptr=my_state.additive_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_additive_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= additive_expression_table                =\n");
    printf(    "============================================\n");
    printf("additive_expression_table_num:%d\n", my_state.additive_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.additive_expression_table_num; ++i)
    {
        print_additive_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_multiplicative_expression_infor(int index)
{
    struct multiplicative_expression_infor * ptr=my_state.multiplicative_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_multiplicative_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= multiplicative_expression_table          =\n");
    printf(    "============================================\n");
    printf("multiplicative_expression_table_num:%d\n", my_state.multiplicative_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.multiplicative_expression_table_num; ++i)
    {
        print_multiplicative_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_cast_expression_infor(int index)
{
    struct cast_expression_infor * ptr=my_state.cast_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_cast_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= cast_expression_table                    =\n");
    printf(    "============================================\n");
    printf("cast_expression_table_num:%d\n", my_state.cast_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.cast_expression_table_num; ++i)
    {
        print_cast_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_unary_expression_infor(int index)
{
    struct unary_expression_infor * ptr=my_state.unary_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data_index:%d \n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_unary_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= unary_expression_table                   =\n");
    printf(    "============================================\n");
    printf("unary_expression_table_num:%d\n", my_state.unary_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.unary_expression_table_num; ++i)
    {
        print_unary_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_postfix_expression_infor(int index)
{
    struct postfix_expression_infor * ptr=my_state.postfix_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data1_index:%d data2_index:%d\n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_postfix_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= postfix_expression_table                 =\n");
    printf(    "============================================\n");
    printf("postfix_expression_table_num:%d\n", my_state.postfix_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.postfix_expression_table_num; ++i)
    {
        print_postfix_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_primary_expression_infor(int index)
{
    struct primary_expression_infor * ptr=my_state.primary_expression_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_index:%d category:%d data_index:%d \n", \
        ptr->index, ptr->node_index, ptr->category, ptr->data_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_primary_expression_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= primary_expression_table                 =\n");
    printf(    "============================================\n");
    printf("primary_expression_table_num:%d\n", my_state.primary_expression_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.primary_expression_table_num; ++i)
    {
        print_primary_expression_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}
//-------------------------------20150328 start--------------------


int print_block_item_infor2(int index)
{
    //printf("index:%d\n", index);
    struct block_item_infor * ptr=my_state.block_item_table[index];
//    printf("ptr:%x\n", ptr);
    if(ptr!=NULL)
    {
      //  printf("index:%d\n", ptr->index);
        printf("index:%d node_index:%d is_statement:%d data_index:%d child_index:%d block_item_next_index:%d\n", \
        ptr->index, ptr->node_index, ptr->is_statement, ptr->data_index, ptr->child_index, (ptr->next!=NULL)?ptr->next->index:-1);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_block_item_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= block_item_table                         =\n");
    printf(    "============================================\n");
    printf("initializer_block_item_table_num:%d\n", my_state.block_item_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.block_item_table_num; ++i)
    {
        print_block_item_infor2(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
    
}
int print_initializer_list_one_infor(int index)
{
    //printf("index:%d\n", index);
    struct initializer_list_one_infor * ptr=my_state.initializer_list_one_table[index];
//    printf("ptr:%x\n", ptr);
    if(ptr!=NULL)
    {
      //  printf("index:%d\n", ptr->index);
        printf("index:%d designation_node_index:%d initializer_node_index:%d designation__index:%d initializer_index:%d initializer_list_one_next_index:%d\n", \
        ptr->index, ptr->designation_node_index, ptr->initializer_node_index, ptr->designation_index, ptr->initializer_index, (ptr->next!=NULL)?ptr->next->index:-1);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_initializer_list_one_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= initializer_list_one_table               =\n");
    printf(    "============================================\n");
    printf("initializer_list_one_table_num:%d\n", my_state.initializer_list_one_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.initializer_list_one_table_num; ++i)
    {
        print_initializer_list_one_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
    
}

int print_initializer_list_infor(int index)
{
    struct initializer_list_infor * ptr=my_state.initializer_list_table[index];
    if(ptr!=NULL)
    {
        //printf("index:%d\n", ptr->index);
        printf("index:%d node_index:%d initializer_list_one_num:%d first_initializer_list_one_index:%d\n", \
        ptr->index, ptr->node_index, ptr->initializer_list_one_num, (ptr->next!=NULL)?ptr->next->index:-1);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_initializer_list_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= initializer_list_table                   =\n");
    printf(    "============================================\n");
    printf("initializer_list_table_num:%d\n", my_state.initializer_list_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.initializer_list_table_num; ++i)
    {
        print_initializer_list_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
    
}
int print_initializer_infor(int index)
{
    struct initializer_infor * ptr=my_state.initializer_table[index];
    if(ptr!=NULL)
    {
        //printf("index:%d\n", ptr->index);
        printf("index:%d node_index:%d is_assignment_expression:%d data_index:%d\n", \
        ptr->index, ptr->node_index, ptr->is_assignment_expression, ptr->data_index);
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_initializer_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= initializer_table                        =\n");
    printf(    "============================================\n");
    printf("initializer_table_num:%d\n", my_state.initializer_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.initializer_table_num; ++i)
    {
        print_initializer_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
    
}



int print_declarator_infor(int index)
{
    struct declarator_infor * ptr=my_state.declarator_table[index];
    if(ptr!=NULL)
    {
        //printf("index:%d\n", ptr->index);
        printf("index:%d node_index:%d pointer_index:%d direct_declarator_index:%d\n", \
        ptr->index, ptr->node_index, ptr->pointer_index, ptr->direct_declarator_index);
    }
    return 0;
}
int print_declarator_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= declarator_table                         =\n");
    printf(    "============================================\n");
    printf("declarator_table_num:%d\n", my_state.declarator_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.declarator_table_num; ++i)
    {
        print_declarator_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
    
}

int print_declaration_infor(int index)
{
    struct declaration_infor * ptr=my_state.declaration_table[index];
    if(ptr!=NULL)
    {
        //printf("index:%d\n", ptr->index);
        printf("index:%d node_index:%d declaration_specifiers_index:%d static_assert_declaration_index:%d\n \
        init_declarator_num:%d init_declarator_infor->next_id:%d\n", \
        ptr->index, ptr->node_index, ptr->declaration_specifiers_index, \
        ptr->static_assert_declaration_index, ptr->init_declarator_num, (ptr->next!=NULL)?ptr->next->index:-1);
    }
    return 0;
}

int print_declaration_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= declaration_table                        =\n");
    printf(    "============================================\n");
    printf("declaration_table_num:%d\n", my_state.declaration_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.declaration_table_num; ++i)
    {
        print_declaration_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
    
}


int print_init_declarator_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= init_declarator_table                    =\n");
    printf(    "============================================\n");
    printf("init_declarator_table_num:%d\n", my_state.init_declarator_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.init_declarator_table_num; ++i)
    {
        print_init_declarator_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

int print_init_declarator_infor(int index)
{
    struct init_declarator_infor * ptr=my_state.init_declarator_table[index];
    printf("index:%d node_index:%d declarator_index:%d initializer_index:%d next:%d\n", \
    ptr->index, ptr->node_index, ptr->declarator_index, ptr->initializer_index, (ptr->next!=NULL)?ptr->next->index:-1);
    return 0;
}


int add_struct_or_union_specifier_table_num()
{
    my_state.struct_or_union_specifier_table_num+=1;
    return my_state.struct_or_union_specifier_table_num;
}

int add_block_item_table_num()
{
    my_state.block_item_table_num+=1;
    return my_state.block_item_table_num;
}

int add_initializer_list_one_table_num()
{
    my_state.initializer_list_one_table_num+=1;
    return my_state.initializer_list_one_table_num;
}

int add_initializer_list_table_num()
{
    my_state.initializer_list_table_num+=1;
    return my_state.initializer_list_table_num;
}



int add_initializer_table_num()
{
    my_state.initializer_table_num+=1;
    return my_state.initializer_table_num;
}


int add_declarator_table_num()
{
    my_state.declarator_table_num+=1;
    return my_state.declarator_table_num;
}

int add_init_declarator_table_num()
{
    my_state.init_declarator_table_num+=1;
    return my_state.init_declarator_table_num;
}

int add_declaration_table_num()
{
    my_state.declaration_table_num+=1;
    return my_state.declaration_table_num;
}
//----------------------------------------------------------
int add_statement_table_num()
{
    my_state.statement_table_num+=1;
    return my_state.statement_table_num;
}

int add_jump_statement_table_num()
{
    my_state.jump_statement_table_num+=1;
    return my_state.jump_statement_table_num;
}

int add_iteration_statement_table_num()
{
    my_state.iteration_statement_table_num+=1;
    return my_state.iteration_statement_table_num;
}

int add_selection_statement_table_num()
{
    my_state.selection_statement_table_num+=1;
    return my_state.selection_statement_table_num;
}

int add_labeled_statement_table_num()
{
    my_state.labeled_statement_table_num+=1;
    return my_state.labeled_statement_table_num;
}

int add_expression_statement_table_num()
{
    my_state.expression_statement_table_num+=1;
    return my_state.expression_statement_table_num;
}

int add_expression_table_num()
{
    my_state.expression_table_num+=1;
    return my_state.expression_table_num;
}

int add_assignment_expression_table_num()
{
    my_state.assignment_expression_table_num+=1;
    return my_state.assignment_expression_table_num;
}

int add_conditional_expression_table_num()
{
    my_state.conditional_expression_table_num+=1;
    return my_state.conditional_expression_table_num;
}

int add_logical_or_expression_table_num()
{
    my_state.logical_or_expression_table_num+=1;
    return my_state.logical_or_expression_table_num;
}

int add_logical_and_expression_table_num()
{
    my_state.logical_and_expression_table_num+=1;
    return my_state.logical_and_expression_table_num;
}

int add_inclusive_or_expression_table_num()
{
    my_state.inclusive_or_expression_table_num+=1;
    return my_state.inclusive_or_expression_table_num;
}

int add_exclusive_or_expression_table_num()
{
    my_state.exclusive_or_expression_table_num+=1;
    return my_state.exclusive_or_expression_table_num;
}

int add_and_expression_table_num()
{
    my_state.and_expression_table_num+=1;
    return my_state.and_expression_table_num;
}

int add_equality_expression_table_num()
{
    my_state.equality_expression_table_num+=1;
    return my_state.equality_expression_table_num;
}

int add_relational_expression_table_num()
{
    my_state.relational_expression_table_num+=1;
    return my_state.relational_expression_table_num;
}

int add_shift_expression_table_num()
{
    my_state.shift_expression_table_num+=1;
    return my_state.shift_expression_table_num;
}

int add_additive_expression_table_num()
{
    my_state.additive_expression_table_num+=1;
    return my_state.additive_expression_table_num;
}

int add_multiplicative_expression_table_num()
{
    my_state.multiplicative_expression_table_num+=1;
    return my_state.multiplicative_expression_table_num;
}

int add_cast_expression_table_num()
{
    my_state.cast_expression_table_num+=1;
    return my_state.cast_expression_table_num;
}

int add_unary_expression_table_num()
{
    my_state.unary_expression_table_num+=1;
    return my_state.unary_expression_table_num;
}

int add_postfix_expression_table_num()
{
    my_state.postfix_expression_table_num+=1;
    return my_state.postfix_expression_table_num;
}

int add_primary_expression_table_num()
{
    my_state.primary_expression_table_num+=1;
    return my_state.primary_expression_table_num;
}

int add_IDENTIFIER_table_num()
{
    my_state.IDENTIFIER_table_num+=1;
    return my_state.IDENTIFIER_table_num;
}

int add_function_definition_table_num()
{
    my_state.function_definition_table_num+=1;
    return my_state.function_definition_table_num;
}

//----------------------20150328 start-------------------------------

int deal_statement(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.statement_table_num;

    if(node_type!=80)  //statement_type=80
    {
        printf("lib/symbol/smbl_function.c deal_statement : node's type is not statement_type(80)1057   type is%d\n", node_type);
    }
    struct statement_infor * infor_ptr=(struct statement_infor*)malloc(sizeof(struct statement_infor));
    my_state.statement_table[infor_index]=infor_ptr;
    add_statement_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data_index=-1;    

    int child_index=node_ptr->node_first_child;

    printf("deal_statement:1055 inrule_num:%d node_index:%d\n", inrule_num, node_index);
    switch(inrule_num)
    {
        case 0:
            printf("0522s\n");
            infor_ptr->data_index=deal_labeled_statement(child_index); //0522
            break;
        case 1:
            infor_ptr->data_index=deal_compound_statement(child_index);
            break;
        case 2:
            printf("deal_expression_statement 0403\n");
            infor_ptr->data_index=deal_expression_statement(child_index);
            break;
        case 3:
            infor_ptr->data_index=deal_selection_statement(child_index);
            break;
        case 4:
            infor_ptr->data_index=deal_iteration_statement(child_index);
            break;
        case 5:
            infor_ptr->data_index=deal_jump_statement(child_index);
            break;
    }
    
    return infor_index;
}



int deal_jump_statement(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.jump_statement_table_num;
    int child_node=-1;
    if(node_type!=58)  //jump_statement_type=58
    {
        printf("lib/symbol/smbl_function.c deal_jump_statement : node's type is not jump_statement_type(58)\n");
    }

    struct jump_statement_infor * infor_ptr=(struct jump_statement_infor*)malloc(sizeof(struct jump_statement_infor));
    add_jump_statement_table_num();
    my_state.jump_statement_table[infor_index]=infor_ptr;
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data_index=-1;
    switch(inrule_num)
    {
    case 0: //GOTO IDENTIFIER ;
        child_node=node_ptr->node_first_child;
        infor_ptr->data_index=deal_IDENTIFIER(child_node, 1);
        break;
    case 1: //CONTINUE ;
        break;
    case 2: //BREAK ;
        break;
    case 3: //RETURN ;
        break;
    case 4: //RETURN expression ;
        child_node=node_ptr->node_first_child;
        infor_ptr->data_index=deal_expression(child_node);
        break;
    default:
        break;
    }

    return infor_index;
 
}

int deal_iteration_statement(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.iteration_statement_table_num;

    if(node_type!=57)  //iteration_statement_type=57
    {
        printf("lib/symbol/smbl_function.c deal_iteration_statement : node's type is not iteration_statement_type(58)\n");
    }
    struct iteration_statement_infor * infor_ptr=(struct iteration_statement_infor*)malloc(sizeof(struct iteration_statement_infor));
    add_iteration_statement_table_num();
    my_state.iteration_statement_table[infor_index]=infor_ptr;
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;
    infor_ptr->data3_index=-1;
    infor_ptr->data4_index=-1;

    int child1_index=-1;
    int child2_index=-1;
    int child3_index=-1;
    int child4_index=-1;

    switch(inrule_num)
    {
        case 0: //WHILE(expression) statement
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            infor_ptr->data1_index=deal_expression(child1_index);
            infor_ptr->data2_index= deal_statement(child2_index);
            break;
        case 1: //DO statement WHILE (expression)
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            infor_ptr->data1_index= deal_statement(child1_index);
            infor_ptr->data2_index=deal_expression(child2_index);
            break;
        case 2: //FOR (expression_statement expression_statement) statement
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            child3_index=my_state.node_table[child2_index]->node_right_brother;
            infor_ptr->data1_index=deal_expression_statement(child1_index);
            infor_ptr->data2_index=deal_expression_statement(child2_index);
            infor_ptr->data3_index=           deal_statement(child3_index);
            break;
        case 3: //FOR (expression_statement expression_statement expression) statement
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            child3_index=my_state.node_table[child2_index]->node_right_brother;
            child4_index=my_state.node_table[child3_index]->node_right_brother;
            infor_ptr->data1_index=deal_expression_statement(child1_index);
            infor_ptr->data2_index=deal_expression_statement(child2_index);
            infor_ptr->data3_index=          deal_expression(child3_index);
            infor_ptr->data4_index=           deal_statement(child4_index);
            break;
        case 4: //FOR (declaration expression_statement) statement
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            child3_index=my_state.node_table[child2_index]->node_right_brother;
            infor_ptr->data1_index=         deal_declaration(child1_index);
            infor_ptr->data2_index=deal_expression_statement(child2_index);
            infor_ptr->data3_index=           deal_statement(child3_index);
            break;
        case 5: //FOR (declaration expression_statement expression) statement
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            child3_index=my_state.node_table[child2_index]->node_right_brother;
            child4_index=my_state.node_table[child3_index]->node_right_brother;
            infor_ptr->data1_index=         deal_declaration(child1_index);
            infor_ptr->data2_index=deal_expression_statement(child2_index);
            infor_ptr->data3_index=          deal_expression(child3_index);
            infor_ptr->data4_index=           deal_statement(child4_index);
            break;
    }


    return infor_index;
}

int deal_selection_statement(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.selection_statement_table_num;

    if(node_type!=77)  //selection_statement_type=77
    {
        printf("lib/symbol/smbl_function.c deal_selection_statement : node's type is not selection_statement_type(77)\n");
    }
    struct selection_statement_infor * infor_ptr=(struct selection_statement_infor*)malloc(sizeof(struct selection_statement_infor));
    my_state.selection_statement_table[infor_index]=infor_ptr;
    add_selection_statement_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;
    infor_ptr->data3_index=-1;
    int child1_index=-1;
    int child2_index=-1;
    int child3_index=-1;
    switch(inrule_num)
    {
        case 0:
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            child3_index=my_state.node_table[child2_index]->node_right_brother;
            infor_ptr->data1_index=deal_expression(child1_index);                    
            infor_ptr->data2_index= deal_statement(child2_index);                    
            infor_ptr->data3_index= deal_statement(child3_index);                    
            break;
        case 1:
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            infor_ptr->data1_index=deal_expression(child1_index);                    
            infor_ptr->data2_index= deal_statement(child2_index);                    
            break;
        case 2:
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            infor_ptr->data1_index=deal_expression(child1_index);                    
            infor_ptr->data2_index= deal_statement(child2_index);                    
            break;
    }
 


    return infor_index;
}

int deal_labeled_statement(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=add_labeled_statement_table_num()-1;
    

    if(node_type!=60)  //labeled_statement_type=60
    {
        printf("lib/symbol/smbl_function.c deal_labeled_statement : node's type is not labeled_statement_type(60)\n");
    }
    struct labeled_statement_infor * infor_ptr=(struct labeled_statement_infor*)malloc(sizeof(struct labeled_statement_infor));
    my_state.labeled_statement_table[infor_index]=infor_ptr;
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;
    int child1_index=-1;
    int child2_index=-1;
    switch(inrule_num)
    {
        case 0:
            printf("0522a1\n");
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
            printf("0522a2\n");
            printf("0523a: child1_index:%d child2_index:%d\n", child1_index, child2_index);
            //child2_index=my_state.node_table[child1_index]->node_right_brother;
            infor_ptr->data1_index=deal_IDENTIFIER(child1_index, 0);
            infor_ptr->data2_index= deal_statement(child2_index);
            printf("0522a3\n");
            break;
        case 1:
            child1_index=node_ptr->node_first_child;
            child2_index=my_state.node_table[child1_index]->node_right_brother;
         // infor_ptr->data1_index=deal_constant_expression(child1_index);
            infor_ptr->data2_index=          deal_statement(child2_index);
            break;
        case 2:
            child1_index=node_ptr->node_first_child;
            infor_ptr->data1_index=deal_statement(child1_index);
            
            break;
    }

    return infor_index;
}

//---------------------------------------------------tomorrow(20150329 work)------------
int deal_expression_statement(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num    =node_ptr->node_inrule_num;
    int node_type     =node_ptr->node_type;
    int infor_index=my_state.expression_statement_table_num;

    if(node_type!=37)  //expression_statement_type=37
    {
        printf("lib/symbol/smbl_function.c deal_expression_statement : node's type is not expression_statement_type(37)\n");
    }
    struct expression_statement_infor * infor_ptr=(struct expression_statement_infor*)malloc(sizeof(struct expression_statement_infor));
    my_state.expression_statement_table[infor_index]=infor_ptr;
    add_expression_statement_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data_index=-1;

    int child_index=-1;
    child_index=node_ptr->node_first_child;
    
    infor_ptr->data_index=deal_expression(child_index);
    

    return infor_index;
}
// well, this is a little complicative, so we tomorrow go get over it
int deal_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.expression_table_num;

    if(node_type!=38)  //expression_type=38
    {
        printf("lib/symbol/smbl_function.c deal_expression_statement : node's type is not expression_type(38)\n");
    }
    struct expression_infor * infor_ptr=(struct expression_infor*)malloc(sizeof(struct expression_infor));
    my_state.expression_table[infor_index]=infor_ptr;
    add_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->data_num  =node_ptr->node_child_num;

    int child_node_index=node_ptr->node_first_child;
    struct node_my * child_node_ptr=my_state.node_table[child_node_index];

    infor_ptr->data_index=deal_assignment_expression(child_node_index);
    int pre_data_index=infor_ptr->data_index;
    int cur_data_index=-1;
    while(child_node_ptr->node_right_brother!=-1)
    {
        child_node_index=child_node_ptr->node_right_brother;
        child_node_ptr  =my_state.node_table[child_node_index];
        cur_data_index  =deal_assignment_expression(child_node_index);
        my_state.assignment_expression_table[pre_data_index]->next_index=cur_data_index;
        pre_data_index=cur_data_index;
        cur_data_index=-1;
    }

    //deal_expression_infor(infor_index);//key 
    printf("0518 expression_node_index:%d\n", node_index);
    return infor_index;
}

int deal_assignment_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.assignment_expression_table_num;

    if(node_type!=8)  //assignment_expression_type=8
    {
        printf("lib/symbol/smbl_function.c deal_assignment_expression_statement : node's type is not assignment_expression_type(8)\n");
    }
    struct assignment_expression_infor * infor_ptr=(struct assignment_expression_infor*)malloc(sizeof(struct assignment_expression_infor));
    my_state.assignment_expression_table[infor_index]=infor_ptr;
    add_assignment_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    /*
    0 ------- conditional_expression
    1 -------  =
    2 ------- *=
    3 ------- /=
    4 ------- %=
    5 ------- +=
    6 ------- -=
    7 ------ <<=
    8 ------ >>=
    9 ------- &=
   10 ------- ^=
   11 ------- |=
    */
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;
    infor_ptr->next_index=-1;

    int child1_index=-1;
    int child2_index=-1;
    int child3_index=-1;

    int assignment_operator_category=-1;

    if(inrule_num==0)
    {
        child1_index=node_ptr->node_first_child;
        infor_ptr->data1_index=deal_conditional_expression(child1_index);
              
    }
    else
    {
        child1_index=node_ptr->node_first_child;        //unary_expression
        child2_index=my_state.node_table[child1_index]->node_right_brother;  //assignment_operator
        child3_index=my_state.node_table[child2_index]->node_right_brother;  //assignment_expression

        /*
        assignment_operator:
        0 ------   =
        1 ------  *=
        2 ------  /=
        3 ------  %=
        4 ------  +=
        5 ------  -=
        6 ------ <<=
        7 ------ >>=
        8 ------  &=
        9 ------  ^=
       10 ------  |=
        */
        assignment_operator_category=my_state.node_table[child2_index]->node_inrule_num;
        infor_ptr->category+=assignment_operator_category; 

        infor_ptr->data1_index=     deal_unary_expression(child1_index);  //unary_expreesion
        infor_ptr->data2_index=deal_assignment_expression(child3_index);  //assignment_expression

    }
    printf("\n0515x1 %d\n", infor_index);
    //deal_assignment_expression_infor(infor_index);
    return infor_index;
}

int deal_conditional_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.conditional_expression_table_num;

    if(node_type!=15)  //conditional_expression_type=15
    {
        printf("lib/symbol/smbl_function.c deal_conditional_expression_statement : node's type is not conditional_expression_type(15)\n");
    }
    struct conditional_expression_infor * infor_ptr=(struct conditional_expression_infor*)malloc(sizeof(struct conditional_expression_infor));
    my_state.conditional_expression_table[infor_index]=infor_ptr;
    add_conditional_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;
    infor_ptr->data3_index=-1;
    int child1_index=-1;
    int child2_index=-1;
    int child3_index=-1;
    if(inrule_num==0)
    {
        child1_index=node_ptr->node_first_child;
        infor_ptr->data1_index=deal_logical_or_expression(child1_index);
    }
    else
    {
        child1_index=node_ptr->node_first_child;
        child2_index=my_state.node_table[child1_index]->node_right_brother;
        child3_index=my_state.node_table[child2_index]->node_right_brother;

        infor_ptr->data1_index= deal_logical_or_expression(child1_index);
        infor_ptr->data2_index=            deal_expression(child2_index);
        infor_ptr->data3_index=deal_conditional_expression(child3_index);


    }


    return infor_index;
}

int deal_logical_or_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.logical_or_expression_table_num;

    if(node_type!=62)  //logical_or_expression_type=62
    {
        printf("lib/symbol/smbl_function.c deal_logical_or_expression_statement : node's type is not logical_or_expression_type(62)\n");
    }
    struct logical_or_expression_infor * infor_ptr=(struct logical_or_expression_infor*)malloc(sizeof(struct logical_or_expression_infor));
    my_state.logical_or_expression_table[infor_index]=infor_ptr;
    add_logical_or_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;
    int child1_index=-1;
    int child2_index=-1;
    if(inrule_num==0)
    {
        child1_index=node_ptr->node_first_child;
        infor_ptr->data1_index=deal_logical_and_expression(child1_index);  
    }
    else
    {
        child1_index=node_ptr->node_first_child;
        child2_index=my_state.node_table[child1_index]->node_right_brother;
        infor_ptr->data1_index= deal_logical_or_expression(child1_index); 
        infor_ptr->data2_index=deal_logical_and_expression(child2_index);
    }


    return infor_index;
}

int deal_logical_and_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.logical_and_expression_table_num;

    if(node_type!=61)  //logical_and_expression_type=61
    {
        printf("lib/symbol/smbl_function.c deal_logical_and_expression_statement : node's type is not logical_and_expression_type(61)\n");
    }
    struct logical_and_expression_infor * infor_ptr=(struct logical_and_expression_infor*)malloc(sizeof(struct logical_and_expression_infor));
    my_state.logical_and_expression_table[infor_index]=infor_ptr;
    add_logical_and_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;
    int child1_index=-1;
    int child2_index=-1;
    if(inrule_num==0)
    {
        child1_index=node_ptr->node_first_child;
        infor_ptr->data1_index=deal_inclusive_or_expression(child1_index);
    }   
    else
    {
        child1_index=node_ptr->node_first_child;
        child2_index=my_state.node_table[child1_index]->node_right_brother;
        infor_ptr->data1_index= deal_logical_and_expression(child1_index);
        infor_ptr->data2_index=deal_inclusive_or_expression(child2_index);
    }

 


    return infor_index;
}

int deal_inclusive_or_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.inclusive_or_expression_table_num;

    if(node_type!=52)  //inclusive_or_expression_type=52
    {
        printf("lib/symbol/smbl_function.c deal_inclusive_or_expression_statement : node's type is not inclusive_or_expression_type(52)\n");
    }
    struct inclusive_or_expression_infor * infor_ptr=(struct inclusive_or_expression_infor*)malloc(sizeof(struct inclusive_or_expression_infor));
    my_state.inclusive_or_expression_table[infor_index]=infor_ptr;
    add_inclusive_or_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;
    int child1_index=node_ptr->node_first_child;
    int child2_index=-1;
    if(inrule_num==0)
    {
        infor_ptr->data1_index=deal_exclusive_or_expression(child1_index);
    }
    else
    {
        child2_index=my_state.node_table[child1_index]->node_right_brother;
        infor_ptr->data1_index=deal_inclusive_or_expression(child1_index);
        infor_ptr->data2_index=deal_exclusive_or_expression(child2_index);
    }



    return infor_index;
}

int deal_exclusive_or_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.exclusive_or_expression_table_num;

    if(node_type!=36)  //exclusive_or_expression_type=36
    {
        printf("lib/symbol/smbl_function.c deal_exclusive_or_expression_statement : node's type is not exclusive_or_expression_type(36)\n");
    }
    struct exclusive_or_expression_infor * infor_ptr=(struct exclusive_or_expression_infor*)malloc(sizeof(struct exclusive_or_expression_infor));
    my_state.exclusive_or_expression_table[infor_index]=infor_ptr;
    add_exclusive_or_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;  

 
    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;

    if(inrule_num==0)
    {
        infor_ptr->data1_index=deal_and_expression(child1_index);
    }
    else
    {
        infor_ptr->data1_index=deal_exclusive_or_expression(child1_index);
        infor_ptr->data2_index=         deal_and_expression(child2_index);
    } 


    return infor_index;
}


int deal_and_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.and_expression_table_num;

    if(node_type!=6)  //and_expression_type=6
    {
        printf("lib/symbol/smbl_function.c deal_and_expression_statement : node's type is not and_expression_type(6)\n");
    }
    struct and_expression_infor * infor_ptr=(struct and_expression_infor*)malloc(sizeof(struct and_expression_infor));
    my_state.and_expression_table[infor_index]=infor_ptr;
    add_and_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;

    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;

    if(inrule_num==0)
    {
        infor_ptr->data1_index=deal_equality_expression(child1_index);
    }
    else
    {
        infor_ptr->data1_index=     deal_and_expression(child1_index);
        infor_ptr->data2_index=deal_equality_expression(child2_index);
    }


    return infor_index;
}

int deal_equality_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.equality_expression_table_num;

    if(node_type!=35)  //equality_expression_type=35
    {
        printf("lib/symbol/smbl_function.c deal_equality_expression_statement : node's type is not equality_expression_type(35)\n");
    }
    struct equality_expression_infor * infor_ptr=(struct equality_expression_infor*)malloc(sizeof(struct equality_expression_infor));
    my_state.equality_expression_table[infor_index]=infor_ptr;
    add_equality_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;

    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;

    if(inrule_num==0)
    {
        infor_ptr->data1_index=deal_relational_expression(child1_index);
    }
    else
    {
        infor_ptr->data1_index=  deal_equality_expression(child1_index);
        infor_ptr->data2_index=deal_relational_expression(child2_index);
    }


    return infor_index;
}

int deal_relational_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.relational_expression_table_num;

    if(node_type!=74)  //relational_expression_type=74
    {
        printf("lib/symbol/smbl_function.c deal_relational_expression_statement : node's type is not relational_expression_type(35)\n");
    }
    struct relational_expression_infor * infor_ptr=(struct relational_expression_infor*)malloc(sizeof(struct relational_expression_infor));
    my_state.relational_expression_table[infor_index]=infor_ptr;
    add_relational_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;
    
    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;
  
    if(inrule_num==0)
    {
        infor_ptr->data1_index=deal_shift_expression(child1_index);
    } 
    else
    {
        infor_ptr->data1_index=deal_relational_expression(child1_index);
        infor_ptr->data2_index=     deal_shift_expression(child2_index);  
    }



    return infor_index;
}

int deal_shift_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.shift_expression_table_num;

    if(node_type!=78)  //shift_expression_type=78
    {
        printf("lib/symbol/smbl_function.c deal_shift_expression_statement : node's type is not shift_expression_type(78)\n");
    }
    struct shift_expression_infor * infor_ptr=(struct shift_expression_infor*)malloc(sizeof(struct shift_expression_infor));
    my_state.shift_expression_table[infor_index]=infor_ptr;
    add_shift_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;

    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;

    if(inrule_num==0)
    {
        infor_ptr->data1_index=deal_additive_expression(child1_index);        
    }
    else
    {
        infor_ptr->data1_index=   deal_shift_expression(child1_index);
        infor_ptr->data2_index=deal_additive_expression(child2_index);
    }


    return infor_index;
}

int deal_additive_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.additive_expression_table_num;

    if(node_type!=4)  //additive_expression_type=4
    {
        printf("lib/symbol/smbl_function.c deal_additive_expression_statement : node's type is not additive_expression_type(4)\n");
    }
    struct additive_expression_infor * infor_ptr=(struct additive_expression_infor*)malloc(sizeof(struct additive_expression_infor));
    my_state.additive_expression_table[infor_index]=infor_ptr;
    add_additive_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;

    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;

    if(inrule_num==0)
    {
        infor_ptr->data1_index=deal_multiplicative_expression(child1_index);
    }
    else
    {
        infor_ptr->data1_index=      deal_additive_expression(child1_index);
        infor_ptr->data2_index=deal_multiplicative_expression(child2_index);
    }
 


    return infor_index;
}

int deal_multiplicative_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.multiplicative_expression_table_num;

    if(node_type!=65)  //multiplicative_expression_type=65
    {
        printf("lib/symbol/smbl_function.c deal_multiplicative_expression_statement : node's type is not multiplicative_expression_type(65)\n");
    }
    struct multiplicative_expression_infor * infor_ptr=(struct multiplicative_expression_infor*)malloc(sizeof(struct multiplicative_expression_infor));
    my_state.multiplicative_expression_table[infor_index]=infor_ptr;
    add_multiplicative_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;

    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;

    if(inrule_num==0)
    {
        infor_ptr->data1_index=deal_cast_expression(child1_index);
    }
    else
    {
        infor_ptr->data1_index=deal_multiplicative_expression(child1_index);
        infor_ptr->data2_index=          deal_cast_expression(child2_index);
    }




    return infor_index;
}

int deal_cast_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.cast_expression_table_num;

    if(node_type!=13)  //cast_expression_type=13
    {
        printf("lib/symbol/smbl_function.c deal_cast_expression_statement : node's type is not cast_expression_type(13)\n");
    }
    struct cast_expression_infor * infor_ptr=(struct cast_expression_infor*)malloc(sizeof(struct cast_expression_infor));
    my_state.cast_expression_table[infor_index]=infor_ptr;
    add_cast_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-1;

    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;

    if(inrule_num==0)
    {
        infor_ptr->data1_index=deal_unary_expression(child1_index);
    }
    else
    {
    //    infor_ptr->data1_index=      deal_type_name(child1_index);
        infor_ptr->data2_index=deal_cast_expression(child2_index);
    }



    return infor_index;
}

int deal_unary_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.unary_expression_table_num;

    if(node_type!=96)  //unary_expression_type=96
    {
        printf("lib/symbol/smbl_function.c deal_unary_expression_statement : node's type is not unary_expression_type(96)\n");
    }
    struct unary_expression_infor * infor_ptr=(struct unary_expression_infor*)malloc(sizeof(struct unary_expression_infor));
    my_state.unary_expression_table[infor_index]=infor_ptr;
    add_unary_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->data_index=-1;

    /*
    0  postfix_expression
    1  INC_OP unary_expression
    2  DEC_OP unary_expression
    3  unary_operator cast_expression
      3 0  &
      4 1  *
      5 2  +
      6 3  -
      7 4  ~
      8 5  !     
    9 4  SIZEOF unary_expression
   10 5  SIZEOF (type_name)
   11 6  ALIGNOF (type_name)
    */
    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;   
    int child_inrule_num=-1; 
    switch(inrule_num)
    {
    case 0:
        infor_ptr->category= 0;
        infor_ptr->data_index=deal_postfix_expression(child1_index);
        break;
    case 1:
        infor_ptr->category= 1;
        infor_ptr->data_index=deal_unary_expression(child1_index);
        break;
    case 2:
        infor_ptr->category= 2;
        infor_ptr->data_index=deal_unary_expression(child1_index);
        break;
    case 3:
        child_inrule_num=my_state.node_table[child1_index]->node_inrule_num;
        infor_ptr->category=child_inrule_num+3;
        infor_ptr->data_index=deal_cast_expression(child2_index);
        break;
    case 4:
        infor_ptr->category= 9;
        infor_ptr->data_index=deal_unary_expression(child1_index);
        break;
    case 5:
        infor_ptr->category=10;
    //  infor_ptr->data_index=deal_type_name_expression(child1_index);
        break;
    case 6:
        infor_ptr->category=11;
    //  infor_ptr->data_index=deal_type_name_expression(child1_index);
        break;
    }



    return infor_index;
}

int deal_postfix_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.postfix_expression_table_num;

    if(node_type!=71)  //postfix_expression_type=71
    {
        printf("lib/symbol/smbl_function.c deal_postfix_expression_statement : node's type is not postfix_expression_type(71)\n");
    }
    struct postfix_expression_infor * infor_ptr=(struct postfix_expression_infor*)malloc(sizeof(struct postfix_expression_infor));
    my_state.postfix_expression_table[infor_index]=infor_ptr;
    add_postfix_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data1_index=-1;
    infor_ptr->data2_index=-2;
    
    int child1_index=node_ptr->node_first_child;
    int child2_index=my_state.node_table[child1_index]->node_right_brother;

    switch(inrule_num)
    {
    case 0:
        infor_ptr->data1_index=deal_primary_expression(child1_index);
        break;
    case 1:
        infor_ptr->data1_index=deal_postfix_expression(child1_index);
        infor_ptr->data2_index=        deal_expression(child2_index);
        break;
    case 2:
        infor_ptr->data1_index=deal_postfix_expression(child1_index);
        break;
    case 3:
        infor_ptr->data1_index=deal_postfix_expression(child1_index);
    //    infor_ptr->data2_index=deal_argument_expression_list(child2_index); 
        break;
    case 4:
        infor_ptr->data1_index=deal_postfix_expression(child1_index);
   //     infor_ptr->data2_index=deal_IDENTIFIER(child2_index);
        break;
    case 5:
        infor_ptr->data1_index=deal_postfix_expression(child1_index);
        //infor_ptr->data2_index=deal_IDENTIFIER(child2_index, 1);
        break;
    case 6:
        infor_ptr->data1_index=deal_postfix_expression(child1_index);
        break;
    case 7:
        infor_ptr->data1_index=deal_postfix_expression(child1_index);
        break;
    case 8:
    //    infor_ptr->data1_index=deal_type_name(child1_index);
    //    infor_ptr->data2_index=deal_initializer_list(child2_index);
        break;
    case 9:
    //    infor_ptr->data1_index=deal_type_name(child1_index);
    //    infor_ptr->data2_index=deal_initializer_list(child2_index);
        break;
    }


    return infor_index;
}

int deal_primary_expression(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int infor_index=my_state.primary_expression_table_num;

    if(node_type!=72)  //primary_expression_type=72
    {
        printf("lib/symbol/smbl_function.c deal_primary_expression_statement : node's type is not primary_expression_type(72)\n");
    }
    struct primary_expression_infor * infor_ptr=(struct primary_expression_infor*)malloc(sizeof(struct primary_expression_infor));
    my_state.primary_expression_table[infor_index]=infor_ptr;
    add_primary_expression_table_num();
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;
    infor_ptr->category=inrule_num;
    infor_ptr->data_index=-1;
  
    int child_index=node_ptr->node_first_child;

    switch(inrule_num)
    {
    case 0:
        printf("0513bb\n");
        infor_ptr->data_index=deal_IDENTIFIER(child_index, 1);
        break;
    case 1:
    //    infor_ptr->data_index=deal_constant(child_index);
        break;
    case 2:
    //    infor_ptr->data_index=deal_string(child_index);
        break;
    case 3:
    //    infor_ptr->data_index=deal_expression(child_index);
        break;
    case 4:
    //    infor_ptr->data_index=deal_generic_selection(child_index);
        break;
    }
    


//          20150331


    return infor_index;
}












//----------------------20150328 end  -------------------------------

//-----------------------20150321 start-------------------------------

struct initializer_list_one_infor *  deal_initializer_list_one(int designation_index, int initializer_index)
{
    //printf("in deal_initializer_list_one function %d %d\n", designation_index, initializer_index);
    struct initializer_list_one_infor * infor_ptr=(struct initializer_list_one_infor*)malloc(sizeof(struct initializer_list_one_infor));
    int infor_index=my_state.initializer_list_one_table_num;
    add_initializer_list_one_table_num();
    my_state.initializer_list_one_table[infor_index]=infor_ptr;
    infor_ptr->index=infor_index;
    infor_ptr->designation_node_index=designation_index;
    infor_ptr->initializer_node_index=initializer_index;
    infor_ptr->designation_index=-1;
    infor_ptr->initializer_index=-1;
    infor_ptr->next=NULL; 




    struct node_my * designation_ptr=NULL;
    struct node_my * initializer_ptr=my_state.node_table[initializer_index];
    if(designation_index!=-1)
    {
        designation_ptr=my_state.node_table[designation_index];
    //  infor_ptr->designation_index=deal_designation(designation_index);
    }
    printf("777\n");
    infor_ptr->initializer_index=deal_initializer(initializer_index);

   // add_initializer_list_one_table_num();

    return infor_ptr;
}

int deal_initializer_list(int node_index)
{
    printf("xyz:%d\n", node_index);
    struct node_my * node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    int child_num =node_ptr->node_child_num;
    if(55!=node_type)  //initializer_list type is 55
    {
        printf("lib/symbol/smbl_function.c deal_initializer_list function wrong! node's type is not initializer_list_type(55)\n");
    }
    int infor_index=my_state.initializer_list_table_num;
    add_initializer_list_table_num();
    printf("xyz:%d infor_index:%d\n", node_index, infor_index);
    struct initializer_list_infor * infor_ptr=(struct initializer_list_infor*)malloc(sizeof(struct initializer_list_infor));
    my_state.initializer_list_table[infor_index]=infor_ptr;
    infor_ptr->index=infor_index;   
    infor_ptr->node_index=node_index;
    infor_ptr->initializer_list_one_num=0;
    infor_ptr->next=NULL;

    int designation_index=-1;
    struct node_my * designation_ptr=NULL;
    int initializer_index=-1;
    struct node_my * initializer_ptr=NULL;

    int child_index=node_ptr->node_first_child;
    struct node_my * child_ptr=my_state.node_table[child_index];

    int i=0;
    struct initializer_list_one_infor * next=NULL;
    struct initializer_list_one_infor * cur=NULL;
    while(1)
    {
        if(child_ptr->node_type==24)  //designation == 24
        {
            designation_index=child_index;
            designation_ptr  =child_ptr;
            initializer_index=child_ptr->node_right_brother;
            initializer_ptr  =my_state.node_table[initializer_index];
            if(0==i)
            {
                next=deal_initializer_list_one(designation_index, initializer_index);
                cur=next;
            }
            else
            {
                cur->next=deal_initializer_list_one(designation_index, initializer_index);
                cur=cur->next;
            }
            infor_ptr->initializer_list_one_num+=1;

            child_index=initializer_ptr->node_right_brother;
            if(-1==child_index)
            {
                break;
            }
            else
            {
                child_ptr  =my_state.node_table[child_index];
            }
        }  
        else
        {
            designation_index=-1;
            designation_ptr  =NULL;
            initializer_index=child_ptr->node_index;
            initializer_ptr  =my_state.node_table[initializer_index];
            //cur->next=deal_initializer_list_one(designation_index, initializer_index);
            //cur=cur->next;
            if(0==i)
            {
                next=deal_initializer_list_one(designation_index, initializer_index);
                cur=next;
            }
            else
            {
                cur->next=deal_initializer_list_one(designation_index, initializer_index);
                cur=cur->next;
            }
            infor_ptr->initializer_list_one_num+=1;

            child_index=initializer_ptr->node_right_brother;
            if(-1==child_index)
            {
                break;
            }
            else
            {
                child_ptr  =my_state.node_table[child_index];
            }
            
        }
        ++i; 
    }

    infor_ptr->next=next;
    if(node_index==53)
    {
        printf("zhanghai\n");
    }
    // add_initializer_list_table_num();
    printf("xyz:%d infor_index:%d next:%d\n", node_index, infor_index, my_state.initializer_list_table_num);
    print_initializer_list_infor(infor_index); 
    return infor_index;
}




int deal_initializer(int node_index)
{

    printf("node_index:%d\n", node_index);
    struct node_my * node_ptr=my_state.node_table[node_index];
    printf("888\n");
    printf("node_index:%d\n", node_index);
    int node_type=node_ptr->node_type;
    printf("999\n");
    int child_index=node_ptr->node_first_child;
    if(56!=node_type)  //initializer type = 56
    {
        printf("lib/symbol/smbl_function.c deal_initializer function wrong! node's type is not initializer_type(56)\n");
    }
    int inrule_num=node_ptr->node_inrule_num;

    struct initializer_infor * infor_ptr=(struct initializer_infor *)malloc(sizeof(struct initializer_infor));
    int infor_index=my_state.initializer_table_num;
    add_initializer_table_num();
    my_state.initializer_table[infor_index]=infor_ptr;
    infor_ptr->index=infor_index;
    infor_ptr->node_index=node_index;

    int initializer_list_index=-1;
    struct node_my * initializer_list_ptr=NULL;
    int assignment_expression_index=-1;
    struct node_my * assignment_expression_ptr=NULL;


    /*
    initializer
        : (0) {initializer_list}
        | (1) {initializer_list , }
        | (2) assignment_expression
     */
    if(2==inrule_num)
    {
        assignment_expression_index=node_ptr->node_first_child;
        assignment_expression_ptr  =my_state.node_table[assignment_expression_index];
        infor_ptr->is_assignment_expression=1;
    }
    else
    {
        initializer_list_index=node_ptr->node_first_child;
        initializer_list_ptr  =my_state.node_table[initializer_list_index];
        infor_ptr->is_assignment_expression=0;
        printf("111\n");
        infor_ptr->data_index=deal_initializer_list(child_index);
    }
    
   // add_initializer_table_num();



    return infor_index;
}

//-----------------------20150321 end  -------------------------------
//init_declarator:
//                declarator = initializer
//                declarator
struct init_declarator_infor * deal_init_declarator(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index]; 
    int inrule_num=node_ptr->node_inrule_num;
    int node_type =node_ptr->node_type;
    if(node_type!=54)   //54: init_declarator type
    {
        printf("wrong, the node's type is not init_declarator\n");
    }
    else
    {    
        printf("right!!!\n");
    }

    struct init_declarator_infor * infor_ptr=(struct init_declarator_infor*)malloc(sizeof(struct init_declarator_infor));
    int cur_index=my_state.init_declarator_table_num;
    my_state.init_declarator_table[cur_index]=infor_ptr;
    infor_ptr->index=cur_index;
    infor_ptr->node_index=node_ptr->node_index;
    infor_ptr->declarator_index=-1;
    infor_ptr->initializer_index=-1;    
    infor_ptr->next=NULL; 
    add_init_declarator_table_num();

    int declarator_index=-1;
    struct node_my *declarator_ptr=NULL;
    int initializer_index=-1;
    struct node_my *initializer_ptr=NULL;
    if(inrule_num==0)
    {
        declarator_index=node_ptr->node_first_child;
        declarator_ptr  =my_state.node_table[declarator_index];
        initializer_index=declarator_ptr->node_right_brother;
        initializer_ptr  =my_state.node_table[initializer_index];

        infor_ptr->declarator_index =deal_declarator(declarator_index);
        infor_ptr->initializer_index=deal_initializer(initializer_index);
    }
    else
    {
        declarator_index=node_ptr->node_first_child;
        declarator_ptr  =my_state.node_table[declarator_index];

        infor_ptr->declarator_index=deal_declarator(declarator_index);;
    }

    
 

    return infor_ptr; 
}


// init_declarator_list:
//        init_declarator
//        init_declarator_list , init_declarator
struct init_declarator_infor * deal_init_declarator_list(int node_index)
{
    struct init_declarator_infor * ret=NULL;
    struct init_declarator_infor * cur=NULL;
    struct node_my *node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;
    
    int child_index=node_ptr->node_first_child;  //init_declarator 
    struct node_my * child_ptr=my_state.node_table[child_index];
    /* 
    if(child_ptr->node_type==54)
    {
        printf("fucking right\n");
    }
    else
    {
        printf("fucking wrong\n");
    }
    */
    ret=deal_init_declarator(child_index);
    cur=ret;
    child_index=child_ptr->node_right_brother;
    while(child_index!=-1)
    {
        child_ptr=my_state.node_table[child_index]; 
        cur->next=deal_init_declarator(child_index);
        cur=cur->next;
        child_index=child_ptr->node_right_brother;
    }
    cur->next=NULL;
      

/*
    while(child_index!=-1)
    {
        child_ptr=my_state.node_table[child_index];
        deal_init_declarator(child_index);
        
    }
*/

    return ret;
}
int deal_static_assert_declaration(int node_index)
{
    return 0;
}


int deal_declaration(int node_index)
{
    struct node_my* node_ptr=my_state.node_table[node_index];  //declaration
    int inrule_num=node_ptr->node_inrule_num;  
    int node_type =node_ptr->node_type;
    if(node_type!=22)    //declaration_type(22)
    {
        printf("lib/symbol/smbl_function.c func:deal_declaration wrong! the node's type is not declaration(22)\n");
    }



    struct declaration_infor * infor_ptr=(struct declaration_infor *)malloc(sizeof(struct declaration_infor));
    my_state.declaration_table[my_state.declaration_table_num]=infor_ptr; 
    infor_ptr->index=my_state.declaration_table_num;   //0
    infor_ptr->node_index=node_ptr->node_index;        //1
    infor_ptr->declaration_specifiers_index=-1;        //2
    infor_ptr->static_assert_declaration_index=-1;     //3
    infor_ptr->init_declarator_num=0;                  //4
    infor_ptr->next=NULL;                              //5
    printf("0318: %d\n", my_state.declaration_table[0]->node_index);
    add_declaration_table_num();

//--------------------------------deal_type
    my_state.deal_type=22;  //declaration_type(22)
    my_state.deal_node_index=node_index; //declaration_node index
    my_state.deal_data1=infor_ptr->index; // declaration_infor index

//--------------------------------



    int index_0=-1;  //declaration_specifiers
    struct node_my* ptr_0=NULL;

    int index_1=-1;  //init_declarator_list
    struct node_my* ptr_1=NULL;

    int index_2=-1;  //static_assert_declaration
    struct node_my* ptr_2=NULL;
  
    switch(inrule_num)
    {
        case 0:
            index_0=node_ptr->node_first_child;
            ptr_0=my_state.node_table[index_0];
            break;
        case 1:
            index_0=node_ptr->node_first_child;
            ptr_0=my_state.node_table[index_0];
            index_1=ptr_0->node_right_brother;
            ptr_1=my_state.node_table[index_1];           
 
            break;
        case 2:
            index_2=node_ptr->node_first_child;
            ptr_2=my_state.node_table[index_2];

            break;
        default:
            break;
    }
    
    if(-1!=index_0)
    {
        infor_ptr->declaration_specifiers_index=deal_declaration_specifiers(index_0);
        //printf("20150126 OK\n");
        
    }

    if(-1!=index_1)
    {
        infor_ptr->next=deal_init_declarator_list(index_1);
        struct init_declarator_infor *next=infor_ptr->next;   //the purpose is to count the init_declartor_infor's num
        while(NULL!=next)
        {
            infor_ptr->init_declarator_num+=1;
            next=next->next;
        }
    }

    if(-1!=index_2)
    {
        deal_static_assert_declaration(index_2);
    }

 
//--------------------------------deal_type
    my_state.deal_type=-1;  //declaration_type(22)
    my_state.deal_node_index=-1; //declaration_node index
    my_state.deal_data1=-1; // declaration_infor index

//--------------------------------

    deal_declaration_infor(infor_ptr->index);
    return infor_ptr->index;
}






//-----------------------------------------------------------------



int add_declaration_specifiers_table_num()
{
    my_state.declaration_specifiers_table_num+=1;
    return 0;
}

int add_direct_declarator_num()
{
    my_state.direct_declarator_table_num+=1;
    return 0;
}

int add_compound_statement_num()
{
    my_state.compound_statement_table_num+=1;
}



int print_direct_declarator_one(struct direct_declarator_one_infor *ptr)
{
    if(NULL==ptr)
    {
        printf("wrong! lib/symbol/smbl_function_definition.c print_direct_declarator_one ptr is NULL\n");
    }
    int category=ptr->category;
    int index1  =ptr->index1;
    int index2  =ptr->index2;
    printf("category:%d index1:%d index2:%d\n", category, index1, index2);
    return 0;

}



int print_direct_declarator(int index)
{
    struct direct_declarator_infor * ptr=my_state.direct_declarator_table[index];
    struct direct_declarator_one_infor * ddo_infor=NULL;

    printf("index:%d\n", ptr->index);
    printf("is_IDENTIFIER:%d\n", ptr->is_IDENTIFIER);
    printf("node_index:%d\n", ptr->node_index);
    printf("number:%d\n", ptr->number);

    int i=0;
   
    ddo_infor=ptr->next; 
    while(ddo_infor!=NULL)
    {
        printf("%d. ", i);
        print_direct_declarator_one(ddo_infor);
        ddo_infor=ddo_infor->next;
        ++i;
    }
   
    return 0;
}

int print_direct_declarator_table()
{
    printf("\n\n============================================\n");
    printf(    "= print direct_declarator_table            =\n");
    printf(    "============================================\n");
    int num=my_state.direct_declarator_table_num;
    int i=0;
    for(i=0; i<num; ++i)
    {
        print_direct_declarator(i);
        printf("--------------------------------------------\n");
    }   
    printf("\n\n\n\n"); 
    return 0;
}

int print_block_item_infor(struct block_item_infor * next)
{
    printf("is_statement:%d node_index:%d index:%d\n", next->is_statement, next->node_index, next->index);
    return 0;
}

int print_compound_statement_infor(int index)
{
    //printf("liumm %d\n", index);
    struct compound_statement_infor * ptr=my_state.compound_statement_table[index];
    if(ptr==NULL)
    {
        printf("ERROR: NULL\n");
        return -1;
    }
//    printf("compound_statement_infor *ptr:%x\n", ptr);
    printf("index:%d node_index:%d block_item_num:%d\n", ptr->index, ptr->node_index, ptr->block_item_num);
    struct block_item_infor * next=ptr->next;
    while(next!=NULL)
    {
        print_block_item_infor(next);
        next=next->next;
    }
    return 0;
}

int print_compound_statement_table()
{
    int num=my_state.compound_statement_table_num;
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= print compound_statement_table           =\n");
    printf(    "============================================\n");
    for(i=0; i<num; ++i)
    {
        print_compound_statement_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("\n\n\n\n");
    return 0;
}




int deal_compound_statement(int node_index)
{
    printf("227a:%d\n", node_index);
    struct node_my *node_ptr=my_state.node_table[node_index];
    int inrule_num=node_ptr->node_inrule_num;

    int compound_statement_index=my_state.compound_statement_table_num;
    struct compound_statement_infor * infor_ptr=(struct compound_statement_infor*)malloc(sizeof(struct compound_statement_infor));
    my_state.compound_statement_table[compound_statement_index]=infor_ptr;
    //we have to add the number of compound_statement, because compound_statement->block_item_list->block_item->statment->compound_statement, and then we will add again, this will cover the contents.
    add_compound_statement_num();

    if(node_ptr->node_type!=14)
    {
        printf("the type is not compound_statement\n");
    }

    if(infor_ptr==NULL)
    {
        printf("lib/symbol/smbl_function_definition.c deal_compound_statement malloc wrong!\n");
    }
    infor_ptr->index=compound_statement_index;
    infor_ptr->node_index=node_ptr->node_index;
    infor_ptr->block_item_num=0;
    infor_ptr->next=NULL;
    

    if(inrule_num==0)
    {
        infor_ptr->next=NULL;
    }
    else
    {
        unsigned int block_item_list_index=node_ptr->node_first_child;
        struct node_my *block_item_list_ptr=my_state.node_table[block_item_list_index];
        if(block_item_list_ptr->node_type!=11) 
        {
            printf("the node's type is not block_item_list");
        }        
        
        unsigned int block_item_index=block_item_list_ptr->node_first_child;
        struct node_my *block_item_ptr=my_state.node_table[block_item_index];
        if(block_item_ptr->node_type!=12)
        {
            printf("the node's type is not block_item\n");
        }

        
/*
        unsigned int dec_or_state_index=block_item_ptr->node_first_child;
        struct node_my *dec_or_state_ptr=my_state.node_table[dec_or_state_index];
        if(dec_or_state_ptr->node_type!=22 && dec_or_state_ptr->node_type!=80)
        {
            printf("the node's type is not statement or declaration\n");
        }
*/

        struct block_item_infor * block_item_infor_ptr=(struct block_item_infor*)malloc(sizeof(struct block_item_infor));
//20150323 start

        printf("111\n");
        my_state.block_item_table[my_state.block_item_table_num]=block_item_infor_ptr;
        block_item_infor_ptr->index=my_state.block_item_table_num;
        printf("333 %d\n", block_item_infor_ptr->index);
        add_block_item_table_num(); 
        printf("222\n");
        
        
//20150323 end        

        block_item_infor_ptr->is_statement=block_item_ptr->node_inrule_num;
        block_item_infor_ptr->node_index=block_item_ptr->node_index;   
        block_item_infor_ptr->child_index=block_item_ptr->node_first_child;  //declaration or statement 
        block_item_infor_ptr->data_index=-1;
        if(block_item_infor_ptr->is_statement==0)
        {
            printf("0401 : is declaration\n");
            block_item_infor_ptr->data_index=deal_declaration(block_item_infor_ptr->child_index);
        }
        else
        {
            printf("0401 : is statement\n");
            block_item_infor_ptr->data_index=deal_statement(block_item_infor_ptr->child_index);
        }
        block_item_infor_ptr->next=NULL;

        block_item_index=block_item_ptr->node_right_brother;  
        if(block_item_index!=-1)
        {
            block_item_ptr=my_state.node_table[block_item_index];
        }
        else
        {
            block_item_ptr=NULL;   //pointer to declaration or statement
        }

        infor_ptr->block_item_num+=1;
        infor_ptr->next=block_item_infor_ptr;
        
        while(block_item_ptr!=NULL)
        {
            //printf("0318me\n");;
            infor_ptr->block_item_num+=1;
 
            block_item_infor_ptr->next=(struct block_item_infor*)malloc(sizeof(struct block_item_infor));
            block_item_infor_ptr=block_item_infor_ptr->next;
//20150323 start

            my_state.block_item_table[my_state.block_item_table_num]=block_item_infor_ptr;
            block_item_infor_ptr->index=my_state.block_item_table_num;
            printf("333 %d\n", block_item_infor_ptr->index);
            add_block_item_table_num(); 
        
        
//20150323 end        
            block_item_infor_ptr->is_statement=block_item_ptr->node_inrule_num;
            block_item_infor_ptr->node_index=block_item_ptr->node_index;
            block_item_infor_ptr->child_index=block_item_ptr->node_first_child;
            block_item_infor_ptr->data_index=-1;
            if(block_item_infor_ptr->is_statement==0)
            {
                printf("0401 : is declaration\n");
                block_item_infor_ptr->data_index=deal_declaration(block_item_infor_ptr->child_index);
            }
            else
            {
            //0401
                printf("0401 : is statement\n");
                block_item_infor_ptr->data_index=deal_statement(block_item_infor_ptr->child_index);
            }
            //block_item_infor_ptr->index=-1;
            //block_item_infor_ptr->next=NULL;

            //block_item_index=block_item_ptr->node_right_brother;   //pointer to declaration or statement
        
            if(block_item_ptr->node_right_brother!=-1)
            {
                block_item_ptr=my_state.node_table[block_item_ptr->node_right_brother];
            }
            else
            {
                block_item_ptr=NULL;
            }
            
        } 
    }
 
/* 
        int is_statement=block_item_ptr->node_inrule_num;
        unsigned int dec_or_state_index=block_item_ptr->node_first_child;
        struct node_my *dec_or_state_ptr=my_state.node_table[dec_or_state_index];
        struct block_item_infor * block_item_infor_ptr=(struct block_item_infor*)malloc(sizeof(struct block_item_infor));
        struct block_item_infor * block_item_infor_next=block_item_infor_ptr;
        block_item_infor_ptr->is_statement=is_statement;
        block_item_infor_ptr->index=-1;
        //block_item_ptr->index=dec_or_state_ptr->node_index;
   
        infor_ptr->block_item_num+=1;
        infor_ptr->next=block_item_infor_ptr;         
        
        block_item_index=block_item_ptr->node_right_brother;
        if(block_item_index!=-1)
        {
            block_item_ptr=NULL;
        }
        else
        {
            block_item_ptr=my_state.node_table[block_item_index];
        }

         
        printf("204 wrong!!!!\n");
         
        while(block_item_ptr!=NULL)
        {
            printf("256 wrong!!! %x %d\n", block_item_ptr, block_item_ptr->node_index);           
             
            is_statement=block_item_ptr->node_inrule_num;
            dec_or_state_index=block_item_ptr->node_first_child;
            dec_or_state_ptr=my_state.node_table[dec_or_state_index];



            block_item_infor_ptr=(struct block_item_infor*)malloc(sizeof(struct block_item_infor));
            block_item_infor_ptr->is_statement=is_statement;
            block_item_infor_ptr->index=-1;
  
 
            infor_ptr->block_item_num+=1;
            block_item_infor_next->next=block_item_infor_ptr;
            block_item_infor_next=block_item_infor_ptr;   
            
 
            block_item_index=block_item_ptr->node_right_brother;
            if(block_item_index!=-1)
            {
                block_item_ptr=NULL;
            }
            else
            {
                block_item_ptr=my_state.node_table[block_item_index];
            }
            
        }
        block_item_infor_next->next=NULL;
    */

    //my_state.compound_statement_table[my_state.compound_statement_table_num]=(struct)
    /*
    switch(inrule_num)
    {
        case 0:
            
            break;
        case 1:
            break;
        default:
            break;
    }
    */
    //printf("227b:\n");
    //print_compound_statement_table();

    //deal_compound_statement_infor(compound_statement_index);  //key ofcouse, we can't call this function at this position, because it will lead to deal the same compound_statement many times, 
    /*
     *compound_statement1 ---> compound_statement2
     *
     * */
    //for example, first deal compound_statemetn2, and then deal compound_statement1, and during dealing 1, 2 will be dealed again.
    return compound_statement_index;
}

int deal_direct_declarator_one(int node_index, int dd_index)
{
    int i=0;
    struct node_my *node_ptr=my_state.node_table[node_index];
    int node_type=node_ptr->node_type;
    if(node_type!=28)
    {
      printf("wrong lib/symbol/smbl_function.c function:deal_direct_declarator_one node_type is not direct_declarator(28)\n");
    }




    int inrule_num=node_ptr->node_inrule_num;
    printf("haha2 inrule_num:%d\n", inrule_num);
    //printf("20150305002:%d\n", inrule_num);
    struct direct_declarator_infor *dd_infor=my_state.direct_declarator_table[dd_index];
    dd_infor->node_index=node_index;
    struct direct_declarator_one_infor * ddo_infor=(struct direct_declarator_one_infor *)malloc(sizeof(struct direct_declarator_one_infor));

    struct direct_declarator_one_infor * next_one=NULL; 
 
    if(ddo_infor==NULL)
    {
        printf("lib/symbol/smbl_function_.c  deal_direct_declarator_one malloc wrong\n");
    }
    ddo_infor->category=0;   
    ddo_infor->index1=-1;   
    ddo_infor->index2=-1;  
    ddo_infor->next=NULL;  

    int num=dd_infor->number; //
    if(num==0)
    {
        dd_infor->next=ddo_infor;
    }
    else
    {
        next_one=dd_infor->next;
        for(i=1; i<num; ++i)
        {
            next_one=next_one->next;
        }
        next_one->next=ddo_infor;
    }
 
    dd_infor->number+=1;


    switch(inrule_num)
    {
        case  0:   //IDENTIFIER
            ddo_infor->category=0;
      //    ddo_infor->index1=0;//IDENTIFIER index
            ddo_infor->index1=deal_IDENTIFIER(node_ptr->node_first_child, 0);
            printf("3089 index1:%d\n", ddo_infor->index1);
            break;
        case  1:   // ( declarator )
            ddo_infor->category=1;
            ddo_infor->index1=0; // declarator index
            break;
        case  2:   //direct_declarator []
            ddo_infor->category=2;
            break;
        case  3:   //direct_declarator [*]
            ddo_infor->category=3;
            break;
        case  4:   //direct_declarator [STATIC type_qualifier_list assignment_expression]
            ddo_infor->category=4;
            ddo_infor->index1=0;// type_qualifier_list index
            ddo_infor->index2=0;// assignment_exression_index
            break;
        case  5:   //direct_declarator [STATIC assignment_expression]
            ddo_infor->category=5;
            ddo_infor->index1=0;// assignment_expression index
            break;
        case  6:   //direct_declarator [type_qualifier_list *]
            ddo_infor->category=6;
            ddo_infor->index1=0;// type_qualifier_list index
            break;
        case  7:   //direct_declarator [type_qualifier_list STATIC assignment_expression]
            ddo_infor->category=7;
            ddo_infor->index1=0;// type_qualifier_list index
            ddo_infor->index2=0;// assignment_expression index
            break;
        case  8:   //direct_declarator [type_qualifier_list assignment_expression]
            ddo_infor->category=8;
            ddo_infor->index1=0;// type_qualifier_list index
            ddo_infor->index2=0;// assignment_expression index
            break;
        case  9:   //direct_declarator [type_qualifier_list]
            ddo_infor->category=9;
            ddo_infor->index1=0;// type_qualifier_list index
            break;
        case 10:   //direct_declarator [assignment_expression]
            ddo_infor->category=10;
            ddo_infor->index1=0;// assignment_expression index
            break;
        case 11:   //direct_declarator (parameter_type_list)
            ddo_infor->category=11;
            //ddo_infor->index1=0;// parameter_type_list index
            //mask
            int second_child=my_state.node_table[node_ptr->node_first_child]->node_right_brother;
            ddo_infor->index1=deal_parameter_type_list(second_child);
            printf("wncbb0112a: ddo_infor->index1=%d\n", ddo_infor->index1);
            break;
        case 12:   //direct_declarator ()
            ddo_infor->category=12;
            break;
        case 13:   //direct_declarator (identifier_list)
            ddo_infor->category=13;
            ddo_infor->index1=0;// identifier_list index
            break;
    }
    return 0; 
}

//=====================20160104 start====================

//parameter_type_list:
//                    parameter_list , ELLIPSIS
//                    parameter_list
int deal_parameter_type_list(int node_index)
{
  int ret=-1;
  struct node_my *node_ptr=my_state.node_table[node_index];
  ret=deal_parameter_list(node_ptr->node_first_child);
  return ret;
}

int add_parameter_list_table_num(){
  if(my_state.parameter_list_table_num>=PARAMETER_LIST_TABLE_NUM)
  {
    printf("parameter_list_table_num>=PARAMETER_LIST_TABLE_NUM!!! need more space\n");
  }
  my_state.parameter_list_table_num+=1;
  return my_state.parameter_list_table_num;
}

int make_parameter_list_infor(int node_index){
  struct parameter_list_infor * ptr=(struct parameter_list_infor*)malloc(sizeof(struct parameter_list_infor));
  if(ptr==NULL)
  {
    printf("malloc parameter_list_infor wrong! lib/symbol/smbl_function_definition.c\n");
  }
  int index=my_state.parameter_list_table_num;
  my_state.parameter_list_table[index]=ptr;
  ptr->index=index;
  ptr->node_index=node_index;
  ptr->category=-1;
  ptr->child_num=0;
  ptr->first_child=-1;
 
  add_parameter_list_table_num(); 
  return index;
}

int print_parameter_list_infor(int i)
{
  struct parameter_list_infor * ptr=my_state.parameter_list_table[i];
  printf("index(%d) node_index(%d) category(%d) child_num(%d) first_child(%d) \n", ptr->index, ptr->node_index, ptr->category, ptr->child_num, ptr->first_child);
  return 0;
}

int print_parameter_list_table()
{
  int i=0;
  printf("\n\n============================================\n");
  printf(    " parameter_list_table               =\n");
  printf(    "============================================\n");
  for(i=0; i<PARAMETER_LIST_TABLE_NUM && i<my_state.parameter_list_table_num; ++i)
  {
    print_parameter_list_infor(i);
    printf("--------------------------------------------\n\n");
  }
  printf("--------------------------------------------\n\n");
  
}
//parameter_list:
//               parameter_declaration
//               parameter_list , parameter_declaration
int deal_parameter_list(int node_index)
{
  int ret=-1;
  int i=0;
  struct node_my *node_ptr=my_state.node_table[node_index];
  int child_num=node_ptr->node_child_num;
  printf("todd01055 :node_index:%d child_num:%d\n", node_ptr->node_index, node_ptr->node_child_num);
  struct node_my *child_nptr=my_state.node_table[node_ptr->node_first_child];
  int infor_num=make_parameter_list_infor(node_index);
  ret=infor_num;

  struct parameter_list_infor * infor_ptr=my_state.parameter_list_table[infor_num]; 
  infor_ptr->child_num=child_num;
  int node_child_index=node_ptr->node_first_child;
  struct parameter_declaration_infor * pre_pdt_ptr=NULL;
  struct parameter_declaration_infor * cur_pdt_ptr=NULL;
  int pdt_index=-1;
  for(i=0; i<child_num; ++i)
  {
    printf("todd0107: node_child_index:%d\n", node_child_index);
    pdt_index=deal_parameter_declaration(node_child_index);
    if(i==0)
    {
      infor_ptr->first_child=pdt_index;
      printf("todd01081 infor_ptr->first_child:%d\n", infor_ptr->first_child);
    }
    cur_pdt_ptr=my_state.parameter_declaration_table[pdt_index];
    if(pre_pdt_ptr!=NULL && i!=0)
    {
      pre_pdt_ptr->next_sibling=cur_pdt_ptr->index; 
    }
    pre_pdt_ptr=cur_pdt_ptr;
    node_child_index=my_state.node_table[node_child_index]->node_right_brother;

  }
  return ret;
}


int print_parameter_declaration_infor(int i)
{
  struct parameter_declaration_infor * ptr=my_state.parameter_declaration_table[i];
  printf("index(%d) node_index(%d) category(%d) data1_index(%d) data2_index(%d) next_sibling(%d)\n", ptr->index, ptr->node_index, ptr->category, ptr->data1_index, ptr->data2_index, ptr->next_sibling);
  return 0;
}

int print_parameter_declaration_table()
{
  int i=0;
  printf("\n\n============================================\n");
  printf(    " parameter_declaration_table               =\n");
  printf(    "============================================\n");
  for(i=0; i<PARAMETER_DECLARATION_TABLE_NUM && i<my_state.parameter_declaration_table_num; ++i)
  {
    print_parameter_declaration_infor(i);
    printf("--------------------------------------------\n\n");
  }
  printf("--------------------------------------------\n\n");
  
}

int add_parameter_declaration_table_num()
{
  my_state.parameter_declaration_table_num+=1;
}

int make_parameter_declaration_infor(int node_index)
{
  struct node_my * node_ptr=my_state.node_table[node_index];
  struct parameter_declaration_infor * ptr=(struct parameter_declaration_infor*)malloc(sizeof(struct parameter_declaration_infor));
  if(ptr==NULL)
  {
    printf("malloc parameter_declaration_infor wrong! lib/symbol/smbl_function_definition.c\n");
  }
  int index=my_state.parameter_declaration_table_num;
  my_state.parameter_declaration_table[index]=ptr;
  ptr->index=index;
  ptr->node_index=node_index;
  ptr->category=node_ptr->node_inrule_num;
  ptr->data1_index=-1;
  ptr->data2_index=-1;
  ptr->next_sibling=-1;
  int node_child1=node_ptr->node_first_child;
  int node_child2=my_state.node_table[node_child1]->node_right_brother;
  switch(ptr->category)
  {
    case 0:
      ptr->data1_index=deal_declaration_specifiers(node_child1);
      ptr->data2_index=deal_declarator(node_child2);
      break;
    case 1:
      ptr->data1_index=deal_declaration_specifiers(node_child1);
      //ptr->data2_index=deal_abstract_declarator(node_child2);
      break;
    case 2:
      ptr->data1_index=deal_declaration_specifiers(node_child1);
      ptr->data2_index=-1;
      break;
    default:
      break;
  }
  add_parameter_declaration_table_num(); 
  return index;
  
}

//parameter_declaration:
//                      declaration_specifiers declarator
//                      declaration_specifiers abstract_declarator
//                      declaration_specifiers
int deal_parameter_declaration(int node_index)
{
  int ret=-1;
  ret=make_parameter_declaration_infor(node_index);
  return ret;
}


//=====================20160104 stop====================




//direct_declarator:
//                  IDENTIFIER
//                  (declarator)
//                  direct_declarator []
//                  ........
int deal_direct_declarator(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int node_inrule_num=node_ptr->node_inrule_num;

    printf("haha123 node_inrule_num %d\n", node_inrule_num);
    int node_type=node_ptr->node_type;
    struct node_my * child_ptr=node_ptr;
    int child_index=node_index;

    struct direct_declarator_infor struct_infor;

    struct direct_declarator_infor * elem_ptr=(struct direct_declarator_infor*)malloc(sizeof(struct direct_declarator_infor));    
    if(elem_ptr==NULL)
    {
        printf("direct_declarator_infor malloc wrong!\n");
    }
    my_state.direct_declarator_table[my_state.direct_declarator_table_num]=elem_ptr;
    elem_ptr->index=my_state.direct_declarator_table_num;
    elem_ptr->is_IDENTIFIER=0;
    elem_ptr->node_index=node_index;
    elem_ptr->number=0;
    elem_ptr->next=NULL;

    add_direct_declarator_num();

    { 
        //printf("20150305001:%d\n", node_inrule_num);
        //while(0!=node_inrule_num)
        while(node_type==28)
        {
            deal_direct_declarator_one(child_index, elem_ptr->index);
          
            child_index =child_ptr->node_first_child;
            if(child_index==-1)
            {
              break;
            }
            child_ptr   =my_state.node_table[child_index];
            //child_index=child_ptr->node_id;
            node_type=child_ptr->node_type;
        }
        printf("haha wtf %d\n", child_ptr->node_type);
    }

    
    
    return elem_ptr->index;
}

/*
int deal_declarator(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index]; 
    int node_inrule_num=node_ptr->node_inrule_num;

    int node_pointer_index=-1;
    struct node_my * node_pointer_ptr=NULL;
    int node_direct_declarator_index=-1;
    struct node_my * node_direct_declarator_ptr=NULL;

    int pointer_num=0;
    if(0==node_inrule_num)
    {
        node_pointer_index=node_ptr->node_first_child; 
        node_pointer_ptr  =my_state.node_table[node_pointer_index];
        node_direct_declarator_index=node_pointer_ptr->node_right_brother;
        node_direct_declarator_ptr  =my_state.node_table[node_direct_declarator_index];
    }
    else
    {
        node_direct_declarator_index=node_ptr->node_first_child;
        node_direct_declarator_ptr  =my_state.node_table[node_direct_declarator_index];
    }
   

 

 
    return 0;
}
*/


/*
function_definition:
                    declaration_specifiers declarator declaration_list compound_statement
                    declaration_specifiers declarator                  compound_statement
*/
int smbl_function_definition(int node_index)  //key
{
    if(-1==node_index)
    {
        node_index=my_state.node_number-1;
    }
    struct node_my* f_d_node=my_state.node_table[node_index]; 

    if(42!=f_d_node->node_type)  //42 means function_definition_type
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/smbl_function_definition.c:smbl_function_defintion: node is not function_definition_type(42)\n");
        my_state.error_int=30201;
        error_quit();
    }

    int child_0_index=f_d_node->node_first_child;
    struct node_my * child_0_ptr=my_state.node_table[child_0_index];

    int child_1_index=child_0_ptr->node_right_brother;
    struct node_my * child_1_ptr=my_state.node_table[child_1_index];

    int child_2_index=-1;
    struct node_my * child_2_ptr=NULL;
 
    int child_3_index=-1;
    struct node_my * child_3_ptr=NULL;

    if(f_d_node->node_inrule_num==0)
    {
        child_2_index=child_1_ptr->node_right_brother;
        child_2_ptr  =my_state.node_table[child_2_index];
        child_3_index=child_2_ptr->node_right_brother;
        child_3_ptr  =my_state.node_table[child_3_index];
    }
    else
    {
        child_3_index=child_1_ptr->node_right_brother;
        child_3_ptr  =my_state.node_table[child_3_index];
    }

    int cur_index=-1;
    //int node_index=-1;
    int category=f_d_node->node_inrule_num;
    int data1_index=-1;
    int data2_index=-1;
    int data3_index=-1;
    int data4_index=-1;

//--------------------deal with 0 declaration_specifiers
    //printf("lib/symbol/smbl_function_definition 127 start todd: %s\n", node_type_str[child_0_ptr->node_type]);
    //printf("xxxxx OK\n");
    data1_index=deal_declaration_specifiers(child_0_index);
    //printf("xxxxxx OK\n");
    //printf("lib/symbol/smbl_function_definition 127 end todd: %s\n", node_type_str[child_0_ptr->node_type]);
    


//--------------------deal with 1 declarator
    //printf("todd: %s\n", node_type_str[child_1_ptr->node_type]);
    
    data2_index=deal_declarator(child_1_index); 
        printf("wtf01a\n");
    deal_declarator_belong2_function(data2_index);

//--------------------deal with 2 declaration_list (maybe NULL)
    //data3_index=deal_declaration_list(child_2_index);


//--------------------deal with 3 compound_statement
    int mid_inst_index=-1;
    data4_index=deal_compound_statement(child_3_index);
    mid_inst_index=deal_compound_statement_infor(data4_index);  //for test   key
    printf("todd0111e mid_ins_index(%d)\n", mid_inst_index);

    
    cur_index=add_function_definition_infor(node_index, category, data1_index, data2_index, data3_index, data4_index, mid_inst_index);
    deal_function_definition_infor(cur_index);
    return cur_index;
}

int deal_declarator_belong2_function(int declarator_index)
{
  int ret=-1;
  struct declarator_infor * infor_ptr=my_state.declarator_table[declarator_index];
  struct direct_declarator_infor * dd_infor=my_state.direct_declarator_table[infor_ptr->direct_declarator_index];
  struct direct_declarator_one_infor * ddo_para_infor=dd_infor->next;
  printf("wncbb0112m: ddo_para_infor->category:%d\n", ddo_para_infor->category);
  
  if(ddo_para_infor==NULL)
  {
    printf("smbl_function_definition.c:deal_declarator_belong2_function wrong1!!!\n");
  }
  struct direct_declarator_one_infor * ddo_name_infor=ddo_para_infor->next;
  struct IDENTIFIER_infor * i_name_infor=my_state.IDENTIFIER_table[ddo_name_infor->index1];
  //struct IDENTIFIER_infor * func_name_i_infor=my_state.IDENTIFIER_table[func_name_ddo_infor->index1];
  printf("wtf02b  ");
  printf("declarator_index:%s\n", i_name_infor->smbl_name);
  printf("wtf01b\n");

 

  return ret;
}

int deal_function_definition_infor(int index)
{
  int ret=-1;
  if(index<0)
  {
    printf("smbl_function_definition.c deal_function_definition_infor wrong!!!\n");
    return ret;
  }
  struct function_definition_infor * infor_ptr=my_state.function_definition_table[index];
  if(infor_ptr==NULL)
  {
    printf("smbl_function_definition.c deal_function_definition_infor wrong!!!\n");
    return ret;
  }
  printf("todd0111d:\nindex(%d) node_index(%d) category(%d) data1_index(declaration_specifiers%d) data2_index(declarator%d)\n data3_index(declaration_list%d)\
      data4_index(compound_statement%d)\n", infor_ptr->index, infor_ptr->node_index, infor_ptr->category, infor_ptr->data1_index, infor_ptr->data2_index\
      , infor_ptr->data3_index, infor_ptr->data4_index);





  return ret;
}



//declarator:
//           pointer direct_declarator
//           direct_declarator
int deal_declarator(int node_index)
{
    if(-1==node_index)
    {
        node_index=my_state.node_number-1;
    }
    struct node_my* node_ptr=my_state.node_table[node_index]; 

    if(23!=node_ptr->node_type)  //declarator_type(23)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/smbl_function_definition.c:smbl_function_defintion: node is not declarator_type(23)\n");
        my_state.error_int=30201;
        error_quit();
    }

    struct declarator_infor * infor_ptr=(struct declarator_infor*)malloc(sizeof(struct declarator_infor));
    if(infor_ptr==NULL)
    {
        printf("lib/symbol/smbl_function.c deal_declarator function malloc infor_ptr wrong!\n");
    }
    //printf("xxx!!! %d\n", my_state.declarator_table_num);
    //printf("infor_ptr:%x\n", infor_ptr);
    //printf("my_state.declarator_table:%x\n", my_state.declarator_table);
    my_state.declarator_table[my_state.declarator_table_num]=infor_ptr;
    //printf("yyy!!!\n");
    infor_ptr->index=my_state.declarator_table_num;
    infor_ptr->node_index=node_index;
    infor_ptr->pointer_index=-1;
    infor_ptr->direct_declarator_index=-1;

    add_declarator_table_num();


    int pointer_1=-1;
    struct node_my * pointer_1_ptr=NULL;
    
    int direct_declarator_2=-1;
    struct node_my * direct_declarator_2_ptr=NULL;



    switch(node_ptr->node_inrule_num)
    {
        case 0:
            pointer_1=node_ptr->node_first_child;
            pointer_1_ptr=my_state.node_table[pointer_1]; 
            direct_declarator_2=pointer_1_ptr->node_right_brother;
            direct_declarator_2_ptr=my_state.node_table[direct_declarator_2];
            printf("not ready yet\n");           
            break;
        case 1:
            direct_declarator_2=node_ptr->node_first_child;
            direct_declarator_2_ptr=my_state.node_table[direct_declarator_2];
            break;
        default:
            break;
    }
    infor_ptr->direct_declarator_index=deal_direct_declarator(direct_declarator_2);
    printf("wtf1a\n");



    return infor_ptr->index;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int get_node_index(int node_index)
{
    if(-1!=node_index)
    {
        node_index
    }
}
*/

int print_declaration_specifiers_table()
{
    printf("\n\n============================================\n");
    printf(    "= print declaration_specifiers_table       =\n");
    printf(    "============================================\n");
    struct declaration_specifiers_infor ** table_ptr=my_state.declaration_specifiers_table;
    int num=my_state.declaration_specifiers_table_num;
    int i=0;
    for(; i<num; i++)
    {
        print_declaration_specifiers_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("\n\n\n\n");

    return 0;
}


int print_declaration_specifiers_infor(int index)
{
    struct declaration_specifiers_infor * infor_ptr=my_state.declaration_specifiers_table[index];
    unsigned int value1=infor_ptr->scs_1.value;    
    unsigned int value2=infor_ptr->ts_2.value;    
    unsigned int value3=infor_ptr->tq_3.value;    
    unsigned int value4=infor_ptr->fs_4.value;    
    //unsigned int value5=infor_ptr->as_5.value;    

    printf("declaration_specifiers_table[%d] start\n", index);
    printf("index:%d\n", infor_ptr->index);
    print_storage_class_specifier(value1);
    print_type_specifier(value2);
    print_type_qualifier(value3);
    print_function_specifier(value4);
    //print_alignment_specifier(value5);
    printf("declaration_specifiers_table[%d] end\n", index);

    return 0;
}


int deal_declaration_specifiers(int node_index)
{
//    static int times=0;
//    times+=1;
//    printf("times:%d\n", times);
    if(-1==node_index)
    {
        node_index=my_state.node_number;
    }
    struct node_my * node_ptr=my_state.node_table[node_index];
    if(21!=node_ptr->node_type) //DECLARATION_SPECIFIERS_TYPE(21)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/smbl_function_declaration.c: deal_declaration_specifiers function wrong! The node(%d)'s type is not declaration_specifiers(21)\n", node_index);
        my_state.error_int=30202;
        error_quit();
        return 0;        
    }

    //printf("lib/symbol/smbl_function_definition:226 \n");

    int child_num=node_ptr->node_child_num;

    int child_int=node_ptr->node_first_child;
    struct node_my * child_ptr=NULL; 
  
    int child_type=0;

    unsigned int value_1=0;
    unsigned int value_2=0;
    unsigned int value_3=0;
    unsigned int value_4=0;
    unsigned int value_5=0;

    int i=0;
    for(; i<child_num; ++i)
    {
        child_ptr=my_state.node_table[child_int]; 
        child_type=child_ptr->node_type;
        //printf("child_type: %d\n", child_type);
        switch(child_type)
        {
            case 82: //storage_class_specifier
                value_1=deal_storage_class_specifier(child_int, value_1);
                break;
            case 95: //type_specifier
                value_2=deal_type_specifier(child_int, value_2);
                //printf("315 315 315\n");
                break;
            case 94: //type_qualifier
                value_3=deal_type_qualifier(child_int, value_3);
                break;
            case 43: //function_specifier
                value_4=deal_function_specifier(child_int, value_4);
                break;
            case  5: //alignment_specifier
                value_5=deal_alignment_specifier(child_int, value_5);
                break;
        }
        child_int=child_ptr->node_right_brother;
        
    }
    //printf("329999999: %x\n", value_2);
    //printf("lib/symbol/smbl_function_definition:267 \n");

    /*
    int value_1=0;  //storage_class_specifier
    int value_2=0;  //type_specifier
    int value_3=0;  //type_qualifier
    int value_4=0;  //function_specifier
    int value_5=0;  //alignment_specifier
    */

    //printf("267: %d\n", my_state.declaration_specifiers_table_num);
    struct declaration_specifiers_infor * elem_ptr=(struct declaration_specifiers_infor *)malloc(sizeof(struct declaration_specifiers_infor));
    //printf("elem_ptr:%x\n", elem_ptr);
    if(elem_ptr==NULL)
    {
        printf("malloc wrong!\n");
    }  
    else
    {
        //printf("right\n");
    } 
    //printf("todd_284 %x\n", my_state.declaration_specifiers_table); 
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]=elem_ptr;

    //printf("lib/symbol/smbl_function_definition:277 \n");
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->index=my_state.declaration_specifiers_table_num;
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->scs_1.value=value_1;
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->ts_2.value =value_2;
    

    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->tq_3.value =value_3;
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->fs_4.value =value_4;
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->as_5.value =value_5;

    //printf("lib/symbol/smbl_function_definition:283 \n");



    //printf("20150126 OK\n");
    add_declaration_specifiers_table_num();
    return elem_ptr->index;
}

int print_storage_class_specifier(unsigned int value)
{
    printf("storage_class_specifier %s(0x%08x)\n", storage_class_specifier_str[value], value);
    return 0;
}

unsigned int deal_storage_class_specifier(int node_index, unsigned int value)
{
    if(-1==node_index)
    {
        node_index=my_state.node_number;
    }
    struct node_my * node_ptr=my_state.node_table[node_index];
    if(82!=node_ptr->node_type) //STORAGE_CLASS_SPECIFIER_TYPE(82)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/smbl_function_declaration.c: deal_storage_classs_specifier function wrong! The node's type is not storage_class_specifier(82)\n");
        my_state.error_int=30203;
        error_quit();
        return 0;
    }
    if(value!=0)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/smbl_function_declaration.c: deal_storage_class_specifier two storage_class_specifiers!\n");
        my_state.error_int=30204;
        error_quit();
        return 0; 
    }

    unsigned int out_value=0;
    out_value=(unsigned int)node_ptr->node_inrule_num+1;

    return out_value;
}

int print_type_specifier(unsigned int value)
{
    unsigned int data=value;
    unsigned int str_0_index=data&0x0000000f; //default void char ... ...
    unsigned int str_1_index=(data&0x00000010) >>4; //signed(0) unsigned(1) 
    unsigned int str_2_index=0; //default(0) short(1) long(2) longlong(3) 
    if(data&0x00000020)
    {
        str_2_index=1;
    }
    else 
    {
        if(data&0x00000040)
        {
            if(data&0x00000080)
            {
                str_2_index=3;
            }
            else
            {
                str_2_index=2;
            }
        }
    }
    unsigned int str_3_index=(data&0xffffff00)>>8;   


    //printf("%d %d %d\n", str_0_index, str_1_index, str_2_index);
    //char * type_specifier_str_1[]={
    //printf("%x\n", str_1_index);
    printf("type_specifier(0x%08x): %s %s %s index(%d)\n", value, type_specifier_str_1[str_1_index], type_specifier_str_2[str_2_index], type_specifier_str_0[str_0_index], str_3_index);



    return 0;
}


unsigned int deal_type_specifier(int node_index, unsigned int value)
{
    //printf("deal_type_specifier\n");
    node_index=(-1==node_index)?my_state.node_number:node_index;
    struct node_my * node_ptr=my_state.node_table[node_index];
    unsigned int out_value=value;
    int in_value=node_ptr->node_inrule_num;
    printf("deal_type_specifier node_inrule_num %d\n", in_value);
    switch(in_value)
    {
        case  0: //void
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x00000001;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30204;
                error_quit();            
            }
            break;
        case  1: //char
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x00000002;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30205;
                error_quit();            
            }
            break;
        case  2: //short
            if( !(0x00000020&out_value) )
            {
                out_value=out_value|0x00000020;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "short short wrong!\n");
                my_state.error_int=30206;
                error_quit();            
            }
            break;
        case  3: //int
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x00000003;
                //printf("490000000000: %x\n", out_value);
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30207;
                error_quit();            
            }
            break;
        case  4: //long
            if( 0x00000040&out_value )
            {
                if(0x00000080&out_value)
                {
                    snprintf(my_state.error_str, sizeof(my_state.error_str), "three or more long is wrong!\n");
                    my_state.error_int=30208;
                    error_quit();            
                }
                else
                {
                    out_value=out_value|0x00000080;
                }
            }
            else 
            {
                out_value=out_value|0x00000040;
            }
            break;
        case  5: //float
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x00000004;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30209;
                error_quit();            
            }
            break;
        case  6: //double
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x00000005;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30210;
                error_quit();            
            }
            break;
        case  7: //signed
            if( 0x00000010&out_value )
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "unsigned signed is wrong\n");
                my_state.error_int=30211;
                error_quit();            
            }
            break;
        case  8: //unsigned
            if( !(0x00000010&out_value) )
            {
                out_value=out_value|0x00000010;
                printf("unsigned: abcd %x\n", out_value);
            }
            else
            {
                //printf("560: %x\n", out_value);
                snprintf(my_state.error_str, sizeof(my_state.error_str), "unsigned unsigned is wrong\n");
                my_state.error_int=30212;
                error_quit();            
            }
        
            break;
        case  9: //bool
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x00000006;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30213;
                error_quit();            
            }
            break;
        case 10: //complex
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x00000007;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30214;
                error_quit();            
            }
            break;
        case 11: //imaginary
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x00000008;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30215;
                error_quit();            
            }
            break;
        case 12: //atomic_type_specifier
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x00000009;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30216;
                error_quit();            
            }
            break;
        case 13: //struct_or_union_specifier
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x0000000a;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30217;
                error_quit();            
            }
            break;
        case 14: //enum_specifier
            if( !(0x0000000f&out_value) )
            {
                out_value=out_value|0x0000000b;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30218;
                error_quit();            
            }
            break;
        case 15: //TYPEDEF_NAME 
            if( !(0x0000000f&out_value) ) 
            {
                out_value=out_value|0x0000000c;
            }
            else
            {
                snprintf(my_state.error_str, sizeof(my_state.error_str), "void is wrong!\n");
                my_state.error_int=30219;
                error_quit();            
            }
            break;
        default:
            snprintf(my_state.error_str, sizeof(my_state.error_str), "type_specifier's type<=21, lib/symbol/smbl_function_definition.c wrong!\n");
            my_state.error_int=30220;
            error_quit();
            
            break;


    }
    
    return out_value;
}

int deal_struct_or_union_specifier(int node_index)
{
    int ret=-1;
    struct node_my * node_ptr=my_state.node_table[node_index];
    if(node_ptr==NULL || node_ptr->node_type!=88)  //struct_or_union_specifier_type 88
    {
        printf("%s:%d deal_struct_or_union_specifier func wrong! node is wrong!\n", __FILE__, __LINE__);
        return ret;
    }
    int node_inrule_num=node_ptr->node_inrule_num;
    //int node_

    int data1_index=-1;
    int data2_index=-1;
    int data3_index=-1;

    data1_index=node_ptr->node_first_child;

    struct node_my * data1_ptr=my_state.node_table[data1_index];
    struct node_my * data2_ptr=NULL;
    struct node_my * data3_ptr=NULL;

    /*
    struct_or_union_specifier:
                                   data1_index    data2_index         data3_index
                              0. struct_or_union                { struct_declaration_list }
                              1. struct_or_union  IDENTIFIER    { struct_declaration_list }
                              2. struct_or_union  IDENTIFIER
    */



    switch(node_inrule_num)
    {
    case 0:
        data3_index=data1_ptr->node_right_brother;
        data3_ptr=my_state.node_table[data3_index];
        break;
    case 1:
        data2_index=data1_ptr->node_right_brother;
        data2_ptr=my_state.node_table[data2_index];
        data3_index=data2_ptr->node_right_brother;
        data3_ptr=my_state.node_table[data3_index];
        break;
    case 2:
        data2_index=data1_ptr->node_right_brother;
        data2_ptr=my_state.node_table[data2_index];
        break;
    default:
        break;
    }

    return ret;
}


int print_type_qualifier(unsigned int value)
{
    printf("type_qualifier(0x%08x): ", value);
    if(value&0x00000001)
    {
        printf("%s ", type_qualifier_str[1]);
    }
    if(value&0x00000002)
    {
        printf("%s ", type_qualifier_str[2]);
    }       
    if(value&0x00000004)
    {
        printf("%s ", type_qualifier_str[3]);
    }
    if(value&0x00000008)
    {
        printf("%s ", type_qualifier_str[4]);
    }
    printf("\n");
   return 0; 
}



unsigned int deal_type_qualifier(int node_index, unsigned int value)
{
    node_index=(-1==node_index)?my_state.node_number:node_index;
    struct node_my * node_ptr=my_state.node_table[node_index];
    unsigned int out_value=value;
    int in_value=node_ptr->node_inrule_num;

    if(94!=node_ptr->node_type) //TYPE_QUALIFIER_TYPE(94)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/smbl_function_declaration.c: deal_type_qualifier: node's type is not TYPE_QUALIFIER(94)\n");
        my_state.error_int=30221;
        error_quit();
        return 0;
    }

    switch(in_value)
    {
        case 0: //const
            out_value=out_value|0x00000001;
            break;
        case 1: //restrict
            out_value=out_value|0x00000002;
            break;
        case 2: //volatile
            out_value=out_value|0x00000004;
            break;
        case 3: //atomic
            out_value=out_value|0x00000008;
            break;
    }

    return out_value;
}


int print_function_specifier(unsigned int value)
{
    printf("function_specifier(0x%08x): ", value);
    if(value&0x00000001)
    {
        printf("%s ", function_specifier_str[1]);
    }
    if(value&0x00000002)
    {
        printf("%s ", function_specifier_str[2]);
    }       
    printf("\n");
   return 0; 
}



unsigned int deal_function_specifier(int node_index, unsigned int value)
{
    node_index=(-1==node_index)?my_state.node_number:node_index;
    struct node_my * node_ptr=my_state.node_table[node_index];
    unsigned int out_value=value;
    int in_value=node_ptr->node_inrule_num;

    if(43!=node_ptr->node_type) //function_specifier_type(43)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/smbl_function_declaration.c: deal_type_qualifier: node's type is not function_specifier_type(43)\n");
        my_state.error_int=30221;
        error_quit();
        return 0;
    }

    switch(in_value)
    {
        case 0: //INILINE
            out_value=out_value|0x00000001;
            break;
        case 1: //NORETURN
            out_value=out_value|0x00000002;
            break;
        default:
            snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/smbl_function_declaration.c: deal_function_specifier node's node_inrule_num is INLINE(0) or NORETURN(1)\n");
            my_state.error_int=30222;
            error_quit();
            return 0;
            
            break;
    }

    return out_value;
}





unsigned int deal_alignment_specifier(int node_index, unsigned int value)
{
    return 0;
}

//type: 0 is in declaration->init_declarator_list->init_declarator->declarator->direct_declarator->IDENTIFIER
//      1 is another
int deal_IDENTIFIER(int node_index, int type)
{
    printf("3949\n");
    struct node_my *node_ptr=my_state.node_table[node_index];
    if(node_ptr->node_type!=49)  //IDENTIFIER_type(49)
    {
        printf("wrong! lib/symbol/smbl_function.c function:deal_IDENTIFIER the node's type is not IDENTIFER(49)\n");
    }
    int node_type        =node_ptr->node_type;
    //int node_index       =node_ptr->node_index;
    int node_inrule_num  =node_ptr->node_inrule_num;
    int node_symbol_index=node_ptr->node_symbol_index;
    int node_parent      =node_ptr->node_parent;
    int node_parent_type =my_state.node_table[node_parent]->node_type;
    int node_parent_inrule_num =my_state.node_table[node_parent]->node_inrule_num;
    int node_brother_seq =node_ptr->node_brother_seq;
    struct symbol_my * smbl_ptr=my_state.symbol_table[node_symbol_index];

    printf("IDENTIFIER: %s node_type:%d node_inrule_num:%d node_parent:%d node_parent_inrule_num:%d node_parent_type:%d node_brother_seq:%d\n", smbl_ptr->smbl_name, node_type, node_inrule_num, node_parent, node_parent_inrule_num, node_parent_type, node_brother_seq);

    struct IDENTIFIER_infor * infor_ptr=NULL;

    //direct_declarator: IDENTIFIER(0)
//    if(28==node_parent_type && 0==node_brother_seq)  //if father is direct_declarator_type and this node is first child(which is IDENFITIER)
    {
        int infor_index=my_state.IDENTIFIER_table_num;
        infor_ptr=(struct IDENTIFIER_infor*)malloc(sizeof(struct IDENTIFIER_infor));
        my_state.IDENTIFIER_table[infor_index]=infor_ptr;
        add_IDENTIFIER_table_num();
        infor_ptr->index=infor_index;
        infor_ptr->node_index=node_index;
        infor_ptr->node_num=1;
//-------------------------------------------------------
     // only when type is not 0(which is not declaration)
        printf("0513a\n");
        infor_ptr->symbol_a_index=-1;
        if(0!=type)
        {
            printf("todd0513xxx start %s %d %d\n", smbl_ptr->smbl_name, node_ptr->node_compound_id, node_index);
            infor_ptr->symbol_a_index=symbol_a_find(smbl_ptr->smbl_name, node_ptr->node_compound_id, node_index);
            printf("todd0513xxx stop\n");
            printf("4161: %d\n", infor_ptr->symbol_a_index);
            //infor_ptr->symbol_a_index=symbol_a_find(smbl_ptr->smbl_name, -1, node_index);
            printf("%s\n", smbl_ptr->smbl_name);
            printf("0512xxx\n");
        }

//-------------------------------------------------------


        infor_ptr->node_ptr=(struct list_node *)malloc(sizeof(struct list_node));
        printf("infor_ptr->node_ptr=%p\n", infor_ptr->node_ptr);
        infor_ptr->node_ptr->data=node_index;
        printf("infor_ptr->node_ptr=%p\n", infor_ptr->node_ptr);
        infor_ptr->node_ptr->next=NULL;
    
        infor_ptr->smbl_num=1;
        infor_ptr->smbl_ptr=(struct list_node *)malloc(sizeof(struct list_node));
        printf("infor_ptr->smbl_ptr=%p\n", infor_ptr->smbl_ptr);
        infor_ptr->smbl_ptr->data=smbl_ptr->smbl_id;
        infor_ptr->smbl_name=my_state.symbol_table[smbl_ptr->smbl_id]->smbl_name;
        printf("infor_ptr->smbl_ptr=%p\n", infor_ptr->smbl_ptr);
        infor_ptr->smbl_ptr->next=NULL;
        infor_ptr->declaration_specifiers_index=my_state.deal_data1;
    }
    return infor_ptr->index;
}

int print_IDENTIFIER_infor(int index)
{
    struct IDENTIFIER_infor * ptr=my_state.IDENTIFIER_table[index];
    if(ptr!=NULL)
    {
        printf("index:%d node_num:%d smbl_num:%d node_index:%d symbol_a_index:%d\n", \
        ptr->index, ptr->node_num, ptr->smbl_num, ptr->node_index, ptr->symbol_a_index);
        if(ptr->declaration_specifiers_index!=-1)
        {
            print_declaration_specifiers_infor(ptr->declaration_specifiers_index);
        }
        struct list_node *node_cur=ptr->node_ptr;
        struct list_node *smbl_cur=ptr->smbl_ptr;
        while(node_cur!=NULL)
        {
            printf(" node_id:%d\n", node_cur->data);
            node_cur=node_cur->next;
        }
        while(smbl_cur!=NULL)
        {
            printf(" smbl_id:%d\n", smbl_cur->data);
            printf(" smbl_name:%s\n", my_state.symbol_table[smbl_cur->data]->smbl_name);
            smbl_cur=smbl_cur->next;

        }
    }
    else
    {
        printf("NULL\n");
    }
    return 0;
}
int print_IDENTIFIER_table()
{
    int i=0;
    printf("\n\n============================================\n");
    printf(    "= IDENTIFIER_table                         =\n");
    printf(    "============================================\n");
    printf("IDENTIFIER_table_num:%d\n", my_state.IDENTIFIER_table_num);
    printf("--------------------------------------------\n");
    for(i=0; i<my_state.IDENTIFIER_table_num; ++i)
    {
        print_IDENTIFIER_infor(i);
        printf("--------------------------------------------\n");
    }
    printf("--------------------------------------------\n\n");
    return 0;
}

//===============================================================================
/*
struct smbl_f{
    int index;
};
struct smbl_v{
    int index;
    int pointer_index;
    int array_dimension;
    int *every_dimension;
};
struct symbol_a{
    int index;
    int declaration_specifiers_index;
    int IDENTIFIER_index;
    int s_type;
    int pointer_index;
    int array_dimension;
    int *every_dimension;

};
*/

//declaration:
//            init_declarator list
int deal_declaration_infor(int index)
{
    struct declaration_infor * declaration_infor_ptr=my_state.declaration_table[index];
    int init_declarator_num=declaration_infor_ptr->init_declarator_num;

    int node_index=declaration_infor_ptr->node_index;
    int compound_id=my_state.node_table[node_index]->node_compound_id;

    int declaration_specifiers_index=declaration_infor_ptr->declaration_specifiers_index;
    int i1=0;
    int i2=0;
    struct init_declarator_infor *init_declarator_infor_ptr=declaration_infor_ptr->next;
    for(i1=0; i1<init_declarator_num; ++i1)
    {
        //init_declarator:
        //                declarator
        //                declarator = initializer
        int declarator_infor_index =init_declarator_infor_ptr->declarator_index;
        int initializer_infor_index=init_declarator_infor_ptr->initializer_index;

        int symbol_a_index=symbol_a_add(compound_id, node_index);  //symbol_a
        printf("0512xxx:symbol_a_table_num %d\n", my_state.symbol_a_table_num);
        struct symbol_a_infor * symbol_a_infor_ptr=my_state.symbol_a_table[symbol_a_index]; //symbol_a
        symbol_a_infor_ptr->declaration_specifiers_index=declaration_specifiers_index; //symbol_a
        symbol_a_infor_ptr->mod_num=0;
        if(declarator_infor_index>=0)
        {
            //declarator: pointer direct_declarator | direct_declarator
            struct declarator_infor * declarator_infor_ptr=my_state.declarator_table[declarator_infor_index];
            int pointer_index=declarator_infor_ptr->pointer_index;
            int direct_declarator_index=declarator_infor_ptr->direct_declarator_index;

            symbol_a_infor_ptr->pointer_index=pointer_index; //symbol_a
            symbol_a_infor_ptr->s_type=0; //symbol_a

            struct direct_declarator_infor * direct_declarator_infor_ptr=my_state.direct_declarator_table[direct_declarator_index];
            int direct_declarator_one_infor_num=direct_declarator_infor_ptr->number;

            //struct direct_declarator_infor
            //{
            //  struct direct_declarator_one_infor * next;
            //}
            //struct direct_declarator_one_infor
            //{
            //  int category;
            //  int index1;
            //  int index2;
            //  struct direct_declarator_one_infor * next;
            //}
            struct direct_declarator_one_infor * direct_declarator_one_infor_ptr=direct_declarator_infor_ptr->next;
            struct symbol_a_dms * symbol_a_dms_cur_ptr=NULL;
            struct symbol_a_dms * symbol_a_dms_pre_ptr=NULL;
            for(i2=0; i2<direct_declarator_one_infor_num; ++i2)
            {
                int category=direct_declarator_one_infor_ptr->category;
                int index1  =direct_declarator_one_infor_ptr->index1;
                int index2  =direct_declarator_one_infor_ptr->index2;
                if(category==0)
                {
                    symbol_a_infor_ptr->IDENTIFIER_index=index1;  //symbol_a
                    symbol_a_infor_ptr->smbl_name=my_state.IDENTIFIER_table[index1]->smbl_name;

                    //now symbl_a_infor has the smbl_name, can find out if this variable is in the taint file
                    //printf("1109todd:smbl_name:%s line_num:%d\n", symbol_a_infor_ptr->smbl_name, symbol_a_infor_ptr->line_num);
                    if(my_state.need_taint_file==1)
                    {
                      symbol_a_infor_ptr->taint_m=is_in_taint_file(symbol_a_infor_ptr->smbl_name, symbol_a_infor_ptr->line_num);
                    }
                }
                if(category>=2&&category<=10)
                {
                    symbol_a_infor_ptr->mod_num+=1;
                    symbol_a_dms_cur_ptr=(struct symbol_a_dms*)malloc(sizeof(struct symbol_a_dms));
                    symbol_a_dms_cur_ptr->category=category;
                    symbol_a_dms_cur_ptr->seq=i2;
                    symbol_a_dms_cur_ptr->index1=index1;
                    symbol_a_dms_cur_ptr->index2=index2;
                    symbol_a_dms_cur_ptr->next=NULL;
                    if(i2==0)
                    {
                      symbol_a_infor_ptr->next=symbol_a_dms_cur_ptr;
                      symbol_a_dms_pre_ptr=symbol_a_dms_cur_ptr;
                    }
                    else
                    {
                      symbol_a_dms_pre_ptr->next=symbol_a_dms_cur_ptr;
                      symbol_a_dms_pre_ptr=symbol_a_dms_cur_ptr;
                    }

                    symbol_a_infor_ptr->array_dimension+=1;  //symbol_a
                    symbol_a_infor_ptr->s_type=0;  //symbol_a
                }
                if(category>=11&&category<=13)
                {
                    symbol_a_infor_ptr->mod_num+=1;
                    symbol_a_dms_cur_ptr=(struct symbol_a_dms*)malloc(sizeof(struct symbol_a_dms));
                    symbol_a_dms_cur_ptr->category=category;
                    symbol_a_dms_cur_ptr->seq=i2;
                    symbol_a_dms_cur_ptr->index1=index1;
                    symbol_a_dms_cur_ptr->index2=index2;
                    symbol_a_dms_cur_ptr->next=NULL;
                    if(i2==0)
                    {
                      symbol_a_infor_ptr->next=symbol_a_dms_cur_ptr;
                      symbol_a_dms_pre_ptr=symbol_a_dms_cur_ptr;
                    }
                    else
                    {
                      symbol_a_dms_pre_ptr->next=symbol_a_dms_cur_ptr;
                      symbol_a_dms_pre_ptr=symbol_a_dms_cur_ptr;
                    }

                    symbol_a_infor_ptr->array_dimension+=1;  //symbol_a
                    symbol_a_infor_ptr->s_type=2;  //symbol_a
                }
                direct_declarator_one_infor_ptr=direct_declarator_one_infor_ptr->next;
            }
        }

        init_declarator_infor_ptr=init_declarator_infor_ptr->next;
    }
    return 0;
}















