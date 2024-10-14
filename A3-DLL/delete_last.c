#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
    // Checking if list is empty
    if (*tail == NULL)
    {
        return FAILURE;
    }

    // Checking if list has only one node
    if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }
    
     
    // Update links
    *tail = (*tail)->prev;
    free((*tail)->next);
    (*tail)->next = NULL;
    return SUCCESS;
}