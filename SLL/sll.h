#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -1
#define DATA_NOT_FOUND -1

typedef int data_t;
typedef struct  node
{
    data_t data;
    struct node *link;
}slist;

int select_operation();
int insert_at_last(slist **head, data_t data);
int insert_at_first(slist **head, data_t data);
int sl_delete_first(slist **head);
int sl_delete_last(slist **head);
int sl_delete_list(slist **head);
int find_node(slist **head, data_t data);
void print_list(slist *head);

#endif