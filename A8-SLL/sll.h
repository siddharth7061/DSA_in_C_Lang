#ifndef SLL_H
#define SLL_L

#include <stdio.h>
#include <stdlib.h>


#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2

typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *link;
}Slist;

int insert_at_last(Slist **head, data_t data);
/* You can modify the function declaration based on your logic */
int reverse_iter(Slist **head); 
int reverse_recursive(Slist **head);
void recur(Slist *prev, Slist **head);
void print_list(Slist *head);

#endif