#include "list_node.h"
#include <stdlib.h>
int main(void)
{
    list_node *p = create_node(100);
    p = append_node(p, create_node(200));

    print_forward(p);
    print_reverse(p);
    printf("\n");

    p = insert_node(p, 1, create_node(300));

    print_forward(p);
    print_reverse(p);
    printf("\n");

    p = pop_node(p);

    print_forward(p);
    print_reverse(p);
    printf("\n");

    p = append_node(p, create_node(400));

    print_forward(p);
    print_reverse(p);
    printf("\n");

    p = remove_node(p, 1);

    print_forward(p);
    print_reverse(p);

    clear_node(p);

    if(p==NULL)
        printf("clear all nodes");

    return 0;
}