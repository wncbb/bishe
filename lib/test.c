#include <stdio.h>
#include <stdlib.h>

#include "compiler_state.h"
#include "error.h"

struct compiler_state my_state;

int main(int argc, char ** argv)
{
    initialize_compiler_state(&my_state, 100, 100, argv[1], 0, 0);
    print_compiler_state(&my_state);
    destroy_compiler_state(&my_state);
       
    return 0;
}
