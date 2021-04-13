#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "myqueue.h"

//==============================================================================================================
// Core Modules

struct qnode
{
	int val;
	struct qnode * next;
};

struct queue
{
	int size;
	qnode * fp;
	qnode * rp;
};

queue * create_queue()
{
	queue * new_queue = (queue *)malloc(sizeof(queue));
	new_queue->fp = NULL;
	new_queue->rp = NULL;
	new_queue->size = 0;
	return new_queue;
}

void insert_qnode(queue * q_add,int val)
{
	qnode * new_qnode = (qnode *)malloc(sizeof(qnode));
	new_qnode->val = val;
	new_qnode->next = NULL;

	if(q_add->size == 0)
	{
		q_add->fp = new_qnode;
		q_add->rp = new_qnode;
	}
	else
	{
		q_add->rp->next = new_qnode;
		q_add->rp = new_qnode;
	}
	q_add->size++;
}

int remove_qnode(queue * q_add)
{
	if(q_add->size == 0)
		return -1;
	int val = q_add->fp->val;
	qnode * first_node = q_add->fp;
	q_add->fp = q_add->fp->next;
	free(first_node);
	q_add->size--;
	return val;
}

void print_queue(queue * q_add)
{
	qnode * start = q_add->fp;
	for(;start!=NULL;)
	{
		printf("%d <- ",start->val);
		start = start->next;
	}
	printf("EndOfQueue");
	return;
}

//===============================================================================================================
void queue_init()
{
	queue * q = create_queue();
    char ans;
    do{
		perform_as_q_choice(get_q_choice(),q);
		printf("\nPress any key to continue...(\"n\" to exit)");
		scanf(" %c",&ans);
    }while('n' != tolower(ans));
}

int get_q_choice(){
	int choice = 0;
	printf("Choose any operation to perform on Queue :\n");
	printf("Press 1 to Insert an integer element into Queue\n");
	printf("Press 2 to Delete an integer from Queue\n");
	scanf("%d",&choice);
	return choice;
}

void perform_as_q_choice(int choice,queue * q){
	if(choice == 1)
	{
		int val = 0;
		printf("Enter integer value into Queue : ");
		scanf("%d",&val);
		insert_qnode(q,val);
		printf("Queue is : \n");
		print_queue(q);
	}
	else if(choice == 2)
	{
		int poped_item = remove_qnode(q);
		if(poped_item != -1)
		{
			printf("%d is removed from Queue.\n",poped_item);
			print_queue(q);
		}
		else
			printf("Queue is already empty!\n");
	}
	else
		printf("Enter valid option.\n");
}

