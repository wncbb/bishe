
#ifndef SCOPE_H
#define SCOPE_H

#define SCOPE_NUMBER 65536

struct scope_struct{
    int scope;
    struct scope_struct *next;
};

struct scope_list{
    int list[SCOPE_NUMBER];
};

struct scope_stack{
    int num;
    struct scope_struct *top;
    struct scope_struct *bot;
};




#endif

int initialize_scope_list();
int initialize_scope_stack();

int push_scope_stack();
int pop_scope_stack();

int print_scope_list();
int print_scope_stack();





















