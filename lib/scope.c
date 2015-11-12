#include <stdio.h>
#include <stdlib.h>

#include "scope.h"

#include "compiler_state.h"

extern struct compiler_state my_state;


int initialize_scope_list()
{
    struct scope_list *list=&my_state.cs_scope_list;

    int i=0;
    for(; i<SCOPE_NUMBER; ++i)
    {
        list->list[i]=-1;
    }
    return 0;
}

int initialize_scope_stack()
{
    struct scope_stack *stack=&my_state.cs_scope_stack;    

    stack->num=1;
    stack->top=(struct scope_struct *)malloc(sizeof(struct scope_struct));
    stack->top->scope=0;
    stack->top->next=NULL;
    stack->bot=stack->top;
    return 0;
}

int push_scope_stack()
{
    my_state.scope_current+=1;
    int data=my_state.scope_current;
    struct scope_stack *stack=&my_state.cs_scope_stack;
    struct scope_list  *list =&my_state.cs_scope_list;    

    stack->num+=1;
    struct scope_struct *tmp_ptr=(struct scope_struct *)malloc(sizeof(struct scope_struct));
    tmp_ptr->scope=data;
    tmp_ptr->next=stack->top;
    stack->top=tmp_ptr;
    if(NULL!=stack->top->next)
    {
        list->list[data]=stack->top->next->scope;
    }
    return 0;
}

int pop_scope_stack()
{
    struct scope_stack *stack=&my_state.cs_scope_stack;
    
    stack->num-=1;
    int ret=stack->top->scope;
    struct scope_struct *tmp_ptr=stack->top;
    stack->top=stack->top->next;
    free(tmp_ptr);
    
    return ret;
}

int print_scope_list()
{
    struct scope_list *list=&my_state.cs_scope_list;
    int i=0;
    for(; i<SCOPE_NUMBER; i++)
    {
        if(-1!=list->list[i])
        {
            printf("%d has father %d\n", i, list->list[i]);
        }
    }
    return 0;
}

int print_scope_stack()
{
    struct scope_stack * stack=&my_state.cs_scope_stack;

    struct scope_struct * tmp_ptr=stack->top;
    printf("stack: ");
    while(NULL!=tmp_ptr)    
    {
        printf("%d ", tmp_ptr->scope);
        tmp_ptr=tmp_ptr->next;
    }
    printf("\n");

    return 0;
}





















