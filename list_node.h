#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef struct list_node
{
    int64_t value;
    struct list_node *next;
    struct list_node *prev;
} list_node;

int64_t list_size(list_node *head)
{
    list_node *p = head;
    int64_t count = 0;
    while (p)
    {
        ++count;
        p = p->next;
    }
    return count;
}

list_node *get_node(list_node *head, int64_t index)
{
    if(index<0)
    {
        printf("index<0");
        assert(index>=0);

    }
    list_node *p = head;
    assert(index < list_size(head));
    for (int64_t i = 0; i < index; ++i)
        p = p->next;
    return p;
}

list_node *get_tail_node(list_node *head)
{
    list_node *p = head;
    while (p->next != NULL)
        p = p->next;
    return p;
}

list_node *create_node(long v)
{
    list_node *p = (list_node *)malloc(sizeof(list_node));
    p->value = v;
    p->next = NULL;
    p->prev = NULL;
    assert(p != NULL);
    return p;
}

list_node *append_node(list_node *head, list_node *node)
{
    list_node *t = get_tail_node(head);
    t->next = node;
    node->prev = t;
    node->next = NULL;
    return head;
}

list_node *pop_node(list_node *head)
{
    list_node *p = get_tail_node(head);
    if (p->prev)
    {
        list_node *pPrev = p->prev;
        pPrev->next = NULL;
    p->prev = NULL;
    }
    free(p);
    return head;
}

list_node *insert_node(list_node *head, uint64_t index, list_node *n)
{
    list_node *p = get_node(head, index)->prev;
    list_node *pNext = p->next;
    p->next = n;
    n->prev = p;
    n->next = pNext;
    if (pNext != NULL)
        pNext->prev = n;
    return head;
}

list_node *remove_node(list_node *head, uint64_t index)
{
    list_node *p = get_node(head, index);
    list_node *pPrev = p->prev;
    list_node *pNext = p->next;
    pPrev->next = pNext;
    pNext->prev = pPrev;
    free(p);
    return head;
}

void clear_node(list_node *head)
{
    int64_t count = list_size(head);
    for (int64_t i = count-1; i >= 0; --i)
    {
        list_node *p = get_tail_node(head);
        if (p->prev)
        {
            list_node *pPrev = p->prev;
            pPrev->next = NULL;
        p->prev = NULL;
        }
        free(p);
    }
}

void print_forward(list_node *head)
{
    list_node *p = head;
    int64_t count = 0;
    while (p)
    {
        printf("list_node[%llu]:value=%lld,nextPointer=%p,prevPointer=%p\n", count++, p->value, p->next, p->prev);
        p = p->next;
    }
}
void print_reverse(list_node *head)
{
    list_node *p = get_tail_node(head);
    int64_t count = list_size(head) - 1;
    while (p)
    {
        printf("list_node[%llu]:value=%lld,nextPointer=%p,prevPointer=%p\n", count--, p->value, p->next, p->prev);
        p = p->prev;
    }
}

#endif
