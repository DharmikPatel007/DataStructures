#pragma once


typedef struct dlnode dlnode;

typedef struct dlinked_list dlinked_list;

dlinked_list * create_dlinked_list();
void insert_dlnode_at_first(dlinked_list * dl_add,int val);
void print_dlinked_list(dlinked_list * dl_add);
void insert_dlnode_at_last(dlinked_list * dl_add, int val);
int remove_dlnode_from_first(dlinked_list * dl_add);
int remove_dlnode_from_last(dlinked_list * dl_add);
