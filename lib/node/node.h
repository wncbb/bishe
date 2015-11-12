#ifndef NODE_H
#define NODE_H
struct node_my{
    unsigned int node_id;
//    enum node_type_enum node_type;
    int node_type;
    unsigned int node_index;

    int node_parent;

    int node_left_brother;
    int node_right_brother;
    int node_brother_num;
    int node_brother_seq;

    int node_first_child;
    int node_child_num;

    int node_inrule_num;

    int node_symbol_index;

    int node_infor_index;

    int node_line_num;

    int node_compound_id;

};
#endif

int print_node(int index, int tree_level);

int write_one_node_to_dot_file(struct node_my *node_ptr);
int write_one_edge_to_dot_file(struct node_my *first_node, struct node_my *second_node);

int preorder_traversal_node_table(int index, int tree_level);

struct node_my * add_node(int node_type, int line_num);
int print_external_declaration_table();
int print_translation_unit_table();
int print_node_all_infor(struct node_my * node_ptr);
int print_node_table();

int node_symbol_type_to_ENUMERATION_CONSTANT_type(struct node_my *enumerator_list_node);
int node_symbol_type_to_enum_type(struct node_my *IDENTIFIER_node);





