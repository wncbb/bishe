#include <stdio.h>
#include <stdlib.h>

#include "error.h"

#include "compiler_state.h"

extern struct compiler_state my_state;

int error_quit()
{
    printf("error:%d information:%s\n", my_state.error_int, my_state.error_str);
    exit(my_state.error_int);
    return 0;
}





