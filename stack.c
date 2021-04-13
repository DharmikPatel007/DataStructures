#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "mystack.h"

//================================================================================================
// Core Modules

struct node
{
	int value;
	struct node * next;
};

struct stack
{
	node * top;
	int size;
};

stack * create_stack()
{
	stack * s = (stack *)malloc(sizeof(stack));
	s->top = NULL;
	s->size = 0;
	return s;
}
bool is_stack_empty(stack * s_add)
{
	return s_add->size == 0;
}
void push_node(stack * s_add, int val)
{
	node * new_node = (node *)malloc(sizeof(node));
	new_node->value = val;
	new_node->next = s_add->top;
	s_add->top = new_node;
	s_add->size++;
	return;
}

int pop_node(stack * s_add)
{
	if(!is_stack_empty(s_add)){
		int val = s_add->top->value;
		node * first = s_add->top;
		s_add->top = s_add->top->next;
		free(first);
		s_add->size--;
		return val;
	}
	return -1;
}

void print_stack(stack * s_add)
{
	node * start = s_add->top;
	for(;start != NULL;){
		printf(" %d ->",start->value);
		start = start->next;
	}
	printf(" EndOfStack");
	return;
}

//===============================================================================================================

void stack_init()
{
	stack * s = create_stack();
    char ans;
    do{
		perform_as_choice(get_choice(),s);
		printf("\nPress any key to continue...(\"n\" to exit)");
		scanf(" %c",&ans);
    }while('n' != tolower(ans));
}

int get_choice(){
	int choice = 0;
	printf("Choose any operation to perform on stack :\n");
	printf("Press 1 to Insert an integer element\n");
	printf("Press 2 to Delete an integer from stack\n");
	scanf("%d",&choice);
	return choice;
}
void perform_as_choice(int choice,stack * s){
	if(choice == 1)
	{
		int val = 0;
		printf("Enter integer value into stack : ");
		scanf("%d",&val);
		push_node(s,val);
		printf("stack is : \n");
		print_stack(s);
	}
	else if(choice == 2)
	{
		int poped_item = pop_node(s);
		if(poped_item != -1)
		{
			printf("%d is removed from stack.\n",poped_item);
			print_stack(s);
		}
		else
			printf("Stack is already empty!\n");
	}
	else
		printf("Enter valid option.\n");
}

