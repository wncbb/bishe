#include "node.h"
int add_child(struct node_my *father_node, struct node_my *child_node);
struct node_my* make_parent(int parent_type, struct node_my *first_child, int inrule_num, int line_num);
int make_brother(struct node_my *left_brother, struct node_my *right_brother);

int give_compound_id(struct node_my *node_start);


int return_index_from_tree_by_type(struct node_my *tree_node, int node_type, int inrule_num);

int search_tree_by_type_and_inrule(struct node_my *top_node, int type, int inrule, int *match_node_table, int *match_node_num);

