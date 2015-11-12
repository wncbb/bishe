#include <stdio.h>
#include <stdlib.h>

#include "node.h"

#include "node_type.h"

#include "../compiler_state.h"
#include "../error.h"

#include "../symbol/symbol.h"


//come from node_type.c
extern char *node_type_str[];

//come from ../../cbison.y
extern struct compiler_state my_state;

//come from clex.l
extern int yylineno;

int print_node(int index, int tree_level)
{
    struct node_my* node_ptr=my_state.node_table[index];
    if(node_ptr==0x00)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "None data for node_table[%d]\n", index);
        my_state.error_int=20101;
        error_quit();
        return 0;
    }
    while(tree_level>0)
    {
        printf(" ");
        tree_level--;
    }
    printf("+%s node_id:%d child_number:%d inrule_num:%d line_num:%d\n", node_type_str[node_ptr->node_type], node_ptr->node_id, node_ptr->node_child_num, node_ptr->node_inrule_num, node_ptr->node_line_num);
   
    if(node_ptr->node_type==not_know_type)
    {
        printf(" %s\n", my_state.symbol_table[node_ptr->node_symbol_index]->smbl_name);
    }
    return 0;
}


int write_one_node_to_dot_file(struct node_my * node_ptr)
{
    char tmp_str[1024];
    memset(tmp_str, 0x00, 1024);
    if(-1==node_ptr->node_symbol_index)
    {
        snprintf(tmp_str, sizeof(tmp_str), "%d[shape=box, label=\"%d %s(%d):%d:%d\"];\n", node_ptr->node_index, node_ptr->node_index, node_type_str[node_ptr->node_type], node_ptr->node_type, node_ptr->node_inrule_num, node_ptr->node_compound_id);
    }
    else
    {
        snprintf(tmp_str, sizeof(tmp_str), "%d[shape=box, label=\"%d %s(%d):%d:%d:%s\"];\n", node_ptr->node_index, node_ptr->node_index, node_type_str[node_ptr->node_type], node_ptr->node_type, node_ptr->node_inrule_num, node_ptr->node_compound_id, my_state.symbol_table[node_ptr->node_symbol_index]->smbl_name);
        
    }
    write(my_state.dot_file_fd, tmp_str, strlen(tmp_str));
    
    return 0;
}
int write_one_edge_to_dot_file(struct node_my *first_node, struct node_my *second_node)
{
    char tmp_str[1024];
    memset(tmp_str, 0x00, 1024);
    snprintf(tmp_str, sizeof(tmp_str), "%d->%d;\n", first_node->node_index, second_node->node_index);
    write(my_state.dot_file_fd, tmp_str, strlen(tmp_str));
    return 0;
}

int preorder_traversal_node_table(int index, int tree_level)
{
    struct node_my* node_ptr=my_state.node_table[index];
    print_node(index, tree_level);
//    char *tmp=node_type_str[node_ptr->node_type];
    if(1==my_state.need_dot_file)
    {
        //char tmp_str[1024];
        write_one_node_to_dot_file(node_ptr);


        /*
        char node_index[30];
        memset(node_index, 0x00, 30);
        sprintf(node_index, "%d", node_ptr->node_index);
        write(my_state.dot_file_fd, node_index, strlen(node_index));
        write(my_state.dot_file_fd, "[label=\"", 8);
        write(my_state.dot_file_fd, node_type_str[node_ptr->node_type], strlen(node_type_str[node_ptr->node_type]));
    
        memset(node_index, 0x00, 30);
        sprintf(node_index, "%d", node_ptr->node_inrule_num);
        write(my_state.dot_file_fd, "(", 1);
        write(my_state.dot_file_fd, node_index, strlen(node_index));
        memset(node_index, 0x00, 30);
        sprintf(node_index, "%d", node_ptr->node_inrule_num);
        write(my_state.dot_file_fd, ")\"]", 3);
        write(my_state.dot_file_fd, ";\n", 2);   
        */
    }
//    printf("%s %d\n", tmp, strlen(tmp));
//    fwrite(tmp, strlen(tmp), 1, dot_fd);
//    fprintf(stdout, "aaaa");
//      printf("%s %d\n",node_type_str[node_ptr->node_type], strlen(node_type_str[node_ptr->node_type]));
//    fwrite(";\n", 2, 1, dot_fd);
    int child_index=node_ptr->node_first_child;
   
    while(child_index!=-1) 
    {
        if(1==my_state.need_dot_file)
        {
            write_one_node_to_dot_file(my_state.node_table[child_index]);
            write_one_edge_to_dot_file(node_ptr, my_state.node_table[child_index]);
            /*
            char node_index[30];
            memset(node_index, 0x00, 30);
            sprintf(node_index, "%d", child_index);
            //itoa(child_index, node_index, 10);
            write(my_state.dot_file_fd, node_index, strlen(node_index));
            write(my_state.dot_file_fd, "[label=\"", 8);
            write(my_state.dot_file_fd, node_type_str[my_state.node_table[child_index]->node_type], strlen(node_type_str[my_state.node_table[child_index]->node_type]));
            memset(node_index, 0x00, 30);
            sprintf(node_index, "%d", my_state.node_table[child_index]->node_inrule_num);
            write(my_state.dot_file_fd, "(", 1);
            write(my_state.dot_file_fd, node_index, strlen(node_index));
            write(my_state.dot_file_fd, ")\"]", 3);
            write(my_state.dot_file_fd, ";\n", 2);
            */
            /*
            memset(node_index, 0x00, 30);
            sprintf(node_index, "%d", node_ptr->node_index);
            //itoa(node_ptr->node_index, node_index, 10);
            write(my_state.dot_file_fd, node_index, strlen(node_index));
            
//        write(dot_fd, "[label=\"", 8);
//        write(dot_fd, node_type_str[node_ptr->node_type], strlen(node_type_str[node_ptr->node_type]));
//        write(dot_fd, "\"]", 2);

            write(my_state.dot_file_fd, "->", 2);

            memset(node_index, 0x00, 30);
            sprintf(node_index, "%d", child_index);
        //itoa(child_index, node_index, 10);
            write(my_state.dot_file_fd, node_index, strlen(node_index));
//        write(dot_fd, "[label=\"", 8);
//        write(dot_fd, node_type_str[node_table[child_index]->node_type], strlen(node_type_str[node_table[child_index]->node_type]));
//        write(dot_fd, "\"]", 2);

            write(my_state.dot_file_fd, ";\n", 2);
            */
           
        }
        preorder_traversal_node_table(child_index, 1+tree_level);
        child_index=my_state.node_table[child_index]->node_right_brother;
     

      
       // write(dot_fd, node_type_str[node_table[child_index]->node_type], strlen(node_type_str[node_table[child_index]->node_type]));


/*
        fwrite(node_type_str[node_table[child_index]->node_type], strlen(node_type_str[node_table[child_index]->node_type]), 1, dot_fd);
        fwrite(";\n", 2, 1, dot_fd);
        fwrite(node_type_str[node_ptr->node_type], strlen(node_type_str[node_ptr->node_type]), 1, dot_fd);
        fwrite("->", 2, 1, dot_fd);
        fwrite(node_type_str[node_table[child_index]->node_type], strlen(node_type_str[node_table[child_index]->node_type]), 1, dot_fd);
        fwrite(";\n", 2, 1, dot_fd);
*/      
    }
    return 0;
}




/*
int print_external_declaration_table()
{
    int i;
    printf("----------print_external_declaration_table :\n");
    for(i=0; i<external_declaration_number; i++)
    {
        printf("%d\n", external_declaration_table[i]->node_index);
    }
    printf("----------print_external_declaration_table !\n");
    return 0;
}

int print_translation_unit_table()
{
    int i;
    printf("----------print_translation_unit_table :\n");
    for(i=0; i<translation_unit_number; i++)
    {
        printf("%d\n", translation_unit_table[i]->node_index);
    }
    printf("----------print_translation_unit_table !\n");
    return 0;
}
*/

struct node_my * add_node(int node_type, int line_num)
{
    //printf("161:line_num:%d\n", line_num);
    int node_index=my_state.node_number;
    int node_id   =my_state.node_number;

    if(my_state.node_table[node_index]==0x00)
    {
        my_state.node_table[node_index]=(struct node_my*)malloc(sizeof(struct node_my));
        if(my_state.node_table[node_index]==0x00)
        {
            snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/node/node.c: add_node function wrong! malloc wrong!\n");
            my_state.error_int=20102;
            error_quit();
            return 0;
        }
        //node_number++;
        ++my_state.node_number;
    }
    else
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/node/node.c: add_node function wrong! node_index wrong!\n");
        my_state.error_int=20103;
        error_quit();
        return 0;
    }
    struct node_my *node_ptr=my_state.node_table[node_index];
    node_ptr->node_id=node_id;
    node_ptr->node_type=node_type;
    node_ptr->node_index=node_index;
   
    node_ptr->node_parent=-1;

    node_ptr->node_left_brother=-1;
    node_ptr->node_right_brother=-1;
    node_ptr->node_brother_num=1;
    node_ptr->node_brother_seq=0;
    
    node_ptr->node_first_child=-1;
    node_ptr->node_child_num=0;
  
    node_ptr->node_inrule_num=-1;

    node_ptr->node_symbol_index=-1;
   
    node_ptr->node_infor_index=-1;
   
    node_ptr->node_line_num=line_num;
    
    node_ptr->node_compound_id=0;

    return my_state.node_table[node_index];
}

int print_node_all_infor(struct node_my * node_ptr)
{
    //printf("node_ptr:%x\n", node_ptr);
    
    printf("id(%u):",            node_ptr->node_id);
    printf("type(%s[%d]):",      node_type_str[node_ptr->node_type], node_ptr->node_type);
    
    printf("index(%d):",         node_ptr->node_index);
    printf("parent(%d):",        node_ptr->node_parent);
    printf("left_brother(%d):",  node_ptr->node_left_brother);
    printf("right_brother(%d):", node_ptr->node_right_brother);
    
    printf("brother_num(%d):", node_ptr->node_brother_num);
    printf("brother_seq(%d):", node_ptr->node_brother_seq);
    
    printf("first_child(%d):", node_ptr->node_first_child);
    printf("child_num(%d):",   node_ptr->node_child_num);
    printf("inrule_num(%d):",  node_ptr->node_inrule_num);
    if(-1==node_ptr->node_symbol_index) 
    {
        printf("symbol_index([%d]):", node_ptr->node_inrule_num);
    }
    else
    {
        printf("symbol_index(%s[%d]):", my_state.symbol_table[node_ptr->node_symbol_index]->smbl_name, node_ptr->node_symbol_index);
    }
    printf("infor_index(%d):",   node_ptr->node_infor_index);
    printf("line_num(%d):",      node_ptr->node_line_num);
    printf("compound_id(%d):\n", node_ptr->node_compound_id);
    printf("\n");


    return 0;
}


int print_node_table()
{
    int i=0;
    printf("----------print_node_table:\n");
    printf("node_index node_parent node_child_num node_type_str node_symbol_index node_line_num node_compound_id\n");
    for(; my_state.node_table[i]!=0x00; i++)
    {
        print_node_all_infor(my_state.node_table[i]);
        //printf("%d %d %d %s %d %d %d\n", my_state.node_table[i]->node_id, my_state.node_table[i]->node_parent, my_state.node_table[i]->node_chIld_num, node_type_str[my_state.node_table[i]->node_type], my_state.node_table[i]->node_symbol_index, my_state.node_table[i]->node_line_num, my_state.node_table[i]->node_compound_id);
    }
    printf("----------print_node_table!\n");
    return 0;
}

int node_symbol_type_to_ENUMERATION_CONSTANT_type(struct node_my *enumerator_list_node)
{
    if(enumerator_list_node->node_type!=enumerator_list_type)
    {   
        snprintf(my_state.error_str, sizeof(my_state.error_str), "/lib/node/node.c node_symbol_type_to_ENUMERATION_CONSTANT func wrong!\nnode's type is not enumerator_list_type\n");
        my_state.error_int=20104;
        error_quit();
        return 0;
    }

    int enumerator_child=enumerator_list_node->node_first_child;
    while(enumerator_child!=-1)
    {
        int enumeration_constant_child=my_state.node_table[enumerator_child]->node_first_child;
        enumerator_child=my_state.node_table[enumerator_child]->node_right_brother;
        if(enumeration_constant_child==-1)
        {
            continue;
        }
        int IDENTIFIER_child=my_state.node_table[enumeration_constant_child]->node_first_child;
        if(IDENTIFIER_child==-1)
        {
            continue;
        }
        int node_symbol_index=my_state.node_table[IDENTIFIER_child]->node_symbol_index;
        if(node_symbol_index==-1)
        {
            continue;
        }
        if(my_state.symbol_table[node_symbol_index]==0x00)
        {
            continue;
        }
        my_state.symbol_table[node_symbol_index]->smbl_type=ENUMERATION_CONSTANT_type;
    }

    return 0;
}

int node_symbol_type_to_enum_type(struct node_my *IDENTIFIER_node)
{
    if(IDENTIFIER_node==0x00)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/nodenode.c: IDENTIFIER_node is 0x00");
        my_state.error_int=20105;
        error_quit();
        return 0;
    }
    
    int symbol_index=IDENTIFIER_node->node_symbol_index;
    if(symbol_index==-1)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/node/node.c: symbol_index is -1");
        my_state.error_int=20106;
        error_quit();
        return 0;
    }

    my_state.symbol_table[symbol_index]->smbl_type=enum_type;


    return 0;
}





