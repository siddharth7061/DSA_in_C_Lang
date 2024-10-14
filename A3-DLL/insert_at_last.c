#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    // Create new node
    Dlist *new = malloc(sizeof(Dlist));

    // memory validation
    if (new == NULL)
    {
        return FAILURE;
    }
    
    // Updating data
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    // checking list is empty
    if (*head == NULL)
    {
        // Pointing head and tail to new node
        *head = *tail = new;
        return SUCCESS;
    }

    // Updating links
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;

    return SUCCESS;
    
}