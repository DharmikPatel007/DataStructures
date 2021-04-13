#pragma once


typedef struct node node;

typedef struct stack stack;

stack * create_stack();
bool is_stack_empty(stack *);
void push_node(stack *, int);
int pop_node(stack *);
void print_stack(stack *);


int get_choice();
void perform_as_choice(int,stack *);
void stack_init();
