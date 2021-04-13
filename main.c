#include <stdio.h>
#include <stdlib.h>

#include "mydblinkedlist.h"

int main()
{
    dlinked_list * dll = create_dlinked_list();
    insert_dlnode_at_last(dll,777);
    insert_dlnode_at_last(dll,890);
    insert_dlnode_at_last(dll,678);
    insert_dlnode_at_first(dll,321);
    print_dlinked_list(dll);
    printf("%d removed from first.\n",remove_dlnode_from_first(dll));
    printf("%d removed from first.\n",remove_dlnode_from_first(dll));
    printf("%d removed from first.\n",remove_dlnode_from_first(dll));
    printf("%d removed from last.\n",remove_dlnode_from_last(dll));
    print_dlinked_list(dll);
    return 0;
}
