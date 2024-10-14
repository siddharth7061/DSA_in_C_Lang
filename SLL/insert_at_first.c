#include "sll.h"

int insert_at_first(slist **head, data_t data)
{
    // create new node
    slist *new = malloc(sizeof(slist));

    // check node is created or not
    if (new == NULL)
    {
        return FAILURE;
    }

    // update data link part of new node
    new->data = data;
    new->link = NULL;

    // checking list is empty or not
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // creating link with first node and new node
    new->link = *head;

    // Pointing the head pointer to the new node
    *head = new;
    
    return SUCCESS;
}