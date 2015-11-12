#include <stdio.h>
#include <stdlib.h>

#include "node_tree.h"

#include "node.h"

#include "../compiler_state.h"

//come from ../cbison.y
extern struct compiler_state my_state;


int add_child_front(struct node_my *father_node, struct node_my *child_node)
{
    child_node->node_parent=father_node->node_index;
    int child_first_origin=father_node->node_first_child;
    child_node->node_right_brother=child_first_origin;
    my_state.node_table[child_first_origin]->node_left_brother=child_node->node_index;
    father_node->node_first_child=child_node->node_index;
    father_node->node_child_num+=1;
    
    return 0;
}

int add_child(struct node_my *father_node, struct node_my *child_node)
{
    int child_num=father_node->node_child_num;
    //printf("node_tree.c:22 child_num: %d\n", child_num);
    int child_index=father_node->node_first_child;
    int i;
    //print_node_table(); 
    while(my_state.node_table[child_index]->node_right_brother!=-1)
    {
        child_index=my_state.node_table[child_index]->node_right_brother;  
        //printf("node_tree.c:30 child_index: %d\n", child_index);
         
    }
    //printf("node_tree.c:31 child_index: %d\n", child_index);
    //printf("node_tree.c:31 child_num: %d\n", child_num);

    make_brother(my_state.node_table[child_index], child_node);   //call make_brother, and the parent's node_child_num will add 1, there is no need to add another time
    //printf("node_tree.c:34 child_num: %d\n", child_num);
    //father_node->node_child_num+=1;

    return 0;
}
struct node_my* make_parent(int parent_type, struct node_my *first_child, int inrule_num, int line_num)
{
    int node_table_index=my_state.node_number;
    struct node_my *parent=add_node(parent_type, line_num);

    my_state.node_table[node_table_index]=parent;

    if(first_child!=0x00)
    {
        parent->node_first_child=first_child->node_index;
        parent->node_child_num=1;
        parent->node_inrule_num=inrule_num;
        
        first_child->node_parent=parent->node_index;
        first_child->node_brother_seq=0;
        first_child->node_brother_num=1;
    }
    else
    {
        parent->node_inrule_num=inrule_num;
    }

     

    return parent;
}

int make_brother(struct node_my *left_brother, struct node_my *right_brother)
{
    //printf("node_tree.c:68\n");
    left_brother->node_right_brother=right_brother->node_index;
    //printf("node_tree.c:70\n");
    left_brother->node_brother_num+=1;
    //printf("node_tree.c:71\n");
    
    right_brother->node_parent=left_brother->node_parent;
    right_brother->node_left_brother=left_brother->node_index;
    right_brother->node_brother_num=left_brother->node_brother_num;
    right_brother->node_brother_seq=left_brother->node_brother_seq+1;

    my_state.node_table[left_brother->node_parent]->node_child_num+=1;

    return 0;
}


int give_compound_id(struct node_my *node_start)
{
    if(NULL==node_start)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "error!:lib/node/node_tree.c give_compound_id (node_start is NULL)\n");
        my_state.error_int=20201;
        error_quit();
        return -1;
    }
    if(node_start->node_compound_id!=0)
    {
        return 0;
    }
    int compound_id=my_state.node_number-1;
    node_start->node_compound_id=compound_id;
    int i=0;
    struct node_my * node_child;
    node_child=my_state.node_table[node_start->node_first_child];
    for(i=0; i<node_start->node_child_num; ++i)
    {
        give_compound_id(node_child);
        node_child=my_state.node_table[node_child->node_right_brother];
        
    }

    
    
    return 0;
}



//------------------------------------------------not ready-----------------------------------------------
int return_index_from_tree_by_type(struct node_my *tree_node, int node_type, int inrule_num)
{
    int ret=-1;
    if(tree_node==0x00)
    {
        printf("node_tree.c:92 tree_node is 0x00 wrong!\n");
        return 0;
    }

    if(tree_node->node_type==node_type && tree_node->node_inrule_num==inrule_num)
    {
        return tree_node->node_index;
    }

    int child=tree_node->node_first_child;
    if(child==-1)
    {
        return -1;
    }
    
    while(child!=-1)
    {
        ret=return_index_from_tree_by_type(my_state.node_table[child], node_type, inrule_num);
        if(ret!=-1)
        {
            break;
        }
        child=my_state.node_table[child]->node_right_brother;
    }
    return ret;

}


int search_tree_by_type_and_inrule(struct node_my *top_node, int type, int inrule, int *match_node_table, int *match_node_num)
{

    // work out
    if(top_node==0x00)
    {
        return -1;
    }
    if(inrule>-1)
    {
        if(top_node->node_type==type && top_node->node_inrule_num==inrule)
        {
            match_node_table[*match_node_num]=top_node->node_index;
            (*match_node_num)+=1;
        }
    }
    else
    {
        if(top_node->node_type==type)
        {
            match_node_table[*match_node_num]=top_node->node_index;
            (*match_node_num)+=1;
        }
        
    }
    int child_index=top_node->node_first_child;
    while(child_index!=-1)
    {
        search_tree_by_type_and_inrule(my_state.node_table[child_index], type, inrule, match_node_table, match_node_num);
        child_index=my_state.node_table[child_index]->node_right_brother;
    }

    return 0;
}











