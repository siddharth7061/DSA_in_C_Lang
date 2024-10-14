#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
    // Checking if list is empty
    if (*head == NULL)
    {
        return FAILURE;
    }
    
    // Checking if list has one node
    if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }

    // Updating links
    *head = (*head)->next;
    free((*head)->prev);
    (*head)-> prev = NULL;
    return SUCCESS;
}