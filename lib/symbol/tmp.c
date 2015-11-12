#include <stdio.h>
#include <stdlib.h>

#include "smbl_function_definition.h"

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

int add_declaration_specifiers_num()
{
    my_state.declaration_specifiers_table_num+=1;
    return 0;
}


int deal_direct_declarator_one(int node_index)
{
    return 0; 
}

int deal_direct_declarator(int node_index)
{
    struct node_my * node_ptr=my_state.node_table[node_index];
    int node_inrule_num=node_ptr->node_inrule_num;

    struct node_my * child_ptr=node_ptr;
    int child_index=node_index;

    struct direct_declarator_infor struct_infor;

    if(1==node_inrule_num) //deal direct_declarator: ( declarator )
    {
    }
    else
    {
        while(0!=node_inrule_num)
        {
            child_ptr  =child_ptr->node_first_child;
            child_index=child_ptr->node_index;
            node_inrule_num=child_ptr->node_inrule_num;
            deal_direct_declarator_one(child_index, )
        }
    }

    /*
    switch(node_inrule_num)
    {
    case 11:

        break;
    }
    */
    
    
    return 0;
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


int smbl_function_definition(int node_index)
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



//--------------------deal with 0 declaration_specifiers
    //printf("lib/symbol/smbl_function_definition 127 start todd: %s\n", node_type_str[child_0_ptr->node_type]);
    deal_declaration_specifiers(child_0_index);
    //printf("lib/symbol/smbl_function_definition 127 end todd: %s\n", node_type_str[child_0_ptr->node_type]);
    
    add_declaration_specifiers_num();


//--------------------deal with 1 declarator
    //printf("todd: %s\n", node_type_str[child_1_ptr->node_type]);
    



//--------------------deal with 2 declaration_list (maybe NULL)



//--------------------deal with 3 compound_statement
    //printf("todd: %s\n", node_type_str[child_3_ptr->node_type]);




    return 0;
}


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



    return 0;
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
    struct declaration_specifiers_infor ** table_ptr=my_state.declaration_specifiers_table;
    int num=my_state.declaration_specifiers_table_num;
    int i=0;
    for(; i<num; i++)
    {
        print_declaration_specifiers(i);
    }


    return 0;
}


int print_declaration_specifiers(int index)
{
    struct declaration_specifiers_infor * infor_ptr=my_state.declaration_specifiers_table[index];
    unsigned int value1=infor_ptr->scs_1.value;    
    unsigned int value2=infor_ptr->ts_2.value;    
    unsigned int value3=infor_ptr->tq_3.value;    
    unsigned int value4=infor_ptr->fs_4.value;    
    //unsigned int value5=infor_ptr->as_5.value;    

    printf("declaration_specifiers_table[%d] start\n", index);

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
    if(-1==node_index)
    {
        node_index=my_state.node_number;
    }
    struct node_my * node_ptr=my_state.node_table[node_index];
    if(21!=node_ptr->node_type) //DECLARATION_SPECIFIERS_TYPE(21)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/symbol/smbl_function_declaration.c: deal_declaration_specifiers function wrong! The node's type is not declaration_specifiers(21)\n");
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
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->scs_1.value=value_1;
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->ts_2.value =value_2;
    

    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->tq_3.value =value_3;
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->fs_4.value =value_4;
    my_state.declaration_specifiers_table[my_state.declaration_specifiers_table_num]->as_5.value =value_5;

    //printf("lib/symbol/smbl_function_definition:283 \n");



    //printf("20150126 OK\n");
    return 0;
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
    printf("%x\n", str_1_index);
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











