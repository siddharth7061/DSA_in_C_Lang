#include "sll.h"

int sl_delete_last(slist **head)
{
    // check list is empty or not
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    // ceate local reference pointer
    slist *temp = *head;

    // If condition to check if there is only one node left in the list
    if (temp->link == NULL)
    {
        free(temp);
        *head = NULL;
        return SUCCESS;
    }
    
    // traversing through the list to the second last node
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }

    // freeing the last node
    free(temp->link);

    // pointing the last node to NULL
    temp->link = NULL;

    return SUCCESS;
}