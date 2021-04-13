#pragma once

typedef struct lnode lnode;

typedef struct linked_list linked_list;

linked_list * create_linked_list();
void insert_lnode_at_first(linked_list * l_add,int val);
void insert_lnode_at_last(linked_list * l_add, int val);
void insert_lnode_at(linked_list * l_add, int val, unsigned int position);
int remove_lnode_from_first(linked_list * l_add);
int remove_lnode_from_last(linked_list * l_add);
int remove_lnode_from(linked_list * l_add,int position);

void print_linked_list(linked_list * l_add);

