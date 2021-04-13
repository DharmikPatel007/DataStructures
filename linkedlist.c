#include <stdio.h>
#include <stdlib.h>

#include "mylinkedlist.h"

struct lnode
{
	int val;
	struct lnode * next;
};

struct linked_list
{
	int size;
	lnode * head;
};

linked_list * create_linked_list()
{
	linked_list * new_linked_list = (linked_list *)malloc(sizeof(linked_list));
	new_linked_list->head = NULL;
	new_linked_list->size = 0;
	return new_linked_list;
}

void insert_lnode_at_first(linked_list * l_add,int val)
{
	lnode * new_lnode = (lnode *)malloc(sizeof(lnode));
	new_lnode->val = val;
	new_lnode->next = l_add->head;
	l_add->head = new_lnode;
	l_add->size++;
	return;
}

void insert_lnode_at_last(linked_list * l_add, int val)
{
	lnode * new_lnode = (lnode *)malloc(sizeof(lnode));
	new_lnode->val = val;
	new_lnode->next = NULL;
	lnode * start = l_add->head;
	if(start == NULL)
	{
		insert_lnode_at_first(l_add,val);
		return;
	}
	for(;start!=NULL;)
	{
		if(start->next == NULL)
		{
			start->next = new_lnode;
			break;
		}
		start = start->next;
	}
	l_add->size++;
	return;
}

void insert_lnode_at(linked_list * l_add, int val, unsigned int position)
{
	if(position == 1 || position == 0)
	{
		insert_lnode_at_first(l_add,val);
		return;
	}
	else if(position <= l_add->size)
	{
		int counter = 1;
		lnode * start = l_add->head;
		for(;counter<position-1;counter++)
		{
			start = start->next;
		}
		lnode * new_lnode = (lnode *)malloc(sizeof(lnode));
		new_lnode->val = val;
		new_lnode->next = start->next;
		start->next = new_lnode;
		l_add->size++;
		return;
	}
	else if(position == (l_add->size+1))
	{
		insert_lnode_at_last(l_add,val);
		return;
	}
	else
	{
		printf("Can't insert at %dth position,\nSize of LinkedList is : %d\n",position,l_add->size);
		return;
	}
}
int remove_lnode_from_first(linked_list * l_add)
{
    if(l_add->head == NULL)
    {
        return -1;
    }
	int val = l_add->head->val;
	lnode * tobe_removed = l_add->head;
	l_add->head = l_add->head->next;
	free(tobe_removed);
	l_add->size--;
	return val;
}
int remove_lnode_from_last(linked_list * l_add)
{
    if(l_add->head == NULL)
    {
        return -1;
    }
	lnode * ptr = l_add->head;
	int counter = 1;
	for(;counter < l_add->size-1;counter++)
	{
		ptr = ptr->next;
	}
	int val = ptr->next->val;
	free(ptr->next);
	ptr->next = NULL;
	l_add->size--;
	return val;
}

int remove_lnode_from(linked_list * l_add,int position)
{
    if(position == 0 || position == 1)
    {
        return remove_lnode_from_first(l_add);
    }
    else if(position <= l_add->size)
    {
        int counter = 1;
        lnode * ptr = l_add->head;
        for(;counter<position-1;counter++)
        {
            ptr = ptr->next;
        }
        int val = ptr->next->val;
        lnode * tobe_removed = ptr->next;
        ptr->next = ptr->next->next;
        free(tobe_removed);
        l_add->size--;
        return val;
    }
    else
    {
        printf("Can't remove from %dth position,\nSize of linked list is : %d\n",position,l_add->size);
        return -1;
    }
}
void print_linked_list(linked_list * l_add)
{
	lnode * start = l_add->head;
	for(;start!=NULL;)
	{
		printf("%d -> ",start->val);
		start = start->next;
	}
	printf("EndOfLinkedList");
}

//==============================================================================================================



