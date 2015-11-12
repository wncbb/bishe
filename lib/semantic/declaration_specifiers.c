#include <stdio.h>
#include <stdlib.h>


#include "declaration_specifiers.h"

#include "../compiler_state.h"
#include "../error.h"

#include "../node/node.h"

extern struct compiler_state my_state;

int deal_declaration_specifiers(int node_index)
{
    if(-1==node_index)
    {
        node_index=my_state.node_number;
    }
    struct node_my * node_ptr=my_state.node_table[node_index];
    if(21!=node_ptr->node_type) //DECLARATION_SPECIFIERS_TYPE(21)
    {
        snprintf(my_state.error_str, sizeof(my_state.error_str), "lib/semantic/*.c: deal_declaration_specifers function wrong! the node's type is not declaration_specifiers_type(21)\n");
        my_state.error_int=40101;
        error_quit();
        return 0;
    }
    printf("20150123 ok\n");
    
    return 0;
}







