#include "sll.h"

int find_node(slist **head, data_t data)
{
	if (*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    slist *temp = *head;
    int count = 1;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return count;
        }
        temp = temp->link;
        count++;
    }
    return FAILURE;
}