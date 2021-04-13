#include <stdio.h>
#include <stdlib.h>

#include "mydblinkedlist.h"

// TODO : Implement Insert and remove at given location
struct dlnode
{
    int val;
    struct dlnode * next;
    struct dlnode * prev;
};

struct dlinked_list
{
    dlnode * head;
    dlnode * tail;
    int size;
};

dlinked_list * create_dlinked_list()
{
    dlinked_list * new_dlinked_list = (dlinked_list *)malloc(sizeof(dlinked_list));
    new_dlinked_list->head = NULL;
    new_dlinked_list->tail = NULL;
    new_dlinked_list->size = 0;
    return new_dlinked_list;
}

void insert_dlnode_at_first(dlinked_list * dl_add,int val)
{
    dlnode * new_dlnode = (dlnode *)malloc(sizeof(dlnode));
    new_dlnode->val = val;
    if(dl_add->size == 0)
    {
        new_dlnode->next = NULL;
        new_dlnode->prev = NULL;
        dl_add->head = new_dlnode;
        dl_add->tail = new_dlnode;
    }
    else
    {
        new_dlnode->next = dl_add->head;
        new_dlnode->prev = NULL;
        dl_add->head->prev = new_dlnode;
        dl_add->head = new_dlnode;
    }
    dl_add->size++;
    return;
}
void insert_dlnode_at_last(dlinked_list * dl_add, int val)
{
    if(dl_add->tail == NULL)
    {
        insert_dlnode_at_first(dl_add,val);
        return;
    }
    dlnode * new_dlnode = (dlnode *)malloc(sizeof(dlnode));
    new_dlnode->val = val;
    new_dlnode->next = NULL;
    new_dlnode->prev = dl_add->tail;
    dl_add->tail->next = new_dlnode;
    dl_add->tail = new_dlnode;
    dl_add->size++;
    return;
}
int remove_dlnode_from_first(dlinked_list * dl_add)
{
    if(dl_add->size == 0)
    {
        printf("Can't remove. DoublyLinkedList is already empty !\n");
        return -1;
    }
    dlnode * tobe_removed = dl_add->head;
    int val = tobe_removed->val;
    if(tobe_removed->next == NULL)
    {
        dl_add->head = NULL;
        dl_add->tail = NULL;
        free(tobe_removed);
        dl_add->size--;
        return val;
    }
    dl_add->head = tobe_removed->next;
    tobe_removed->next->prev = NULL;
    tobe_removed->next = NULL;
    tobe_removed->prev = NULL;
    free(tobe_removed);
    dl_add->size--;
    return val;

}
int remove_dlnode_from_last(dlinked_list * dl_add)
{
    if(dl_add->size == 0)
    {
        printf("Can't remove. DoublyLinkedList is already empty !\n");
        return -1;
    }
    dlnode * tobe_removed = dl_add->tail;
    int val = tobe_removed->val;
    if(tobe_removed->prev == NULL)
    {
        return remove_dlnode_from_first(dl_add);
    }
    dl_add->tail = tobe_removed->prev;
    tobe_removed->prev->next = NULL;
    tobe_removed->next = NULL;
    tobe_removed->prev = NULL;
    free(tobe_removed);
    dl_add->size--;
    return val;
}


void print_dlinked_list(dlinked_list * dl_add)
{
    dlnode * ptr = dl_add->head;
    for(;ptr!=NULL;)
    {
        printf("%d <=> ",ptr->val);
        ptr = ptr->next;
    }
    printf("EndOfDoublyLinkedList\n");
    return;
}
