#include "sll.h"
int insert_at_last(slist **head, data_t data)
{
    // create new node
    slist *new = malloc(sizeof(slist));

    //Error check
    if (new == NULL)
    {
        return FAILURE;
    }
    
    // Update the node with data and link addres
    new->data = data;
    new->link = NULL; //NULL because every new element will be at last

    // check list is empty or not
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // Create local reference
    slist *temp = *head;

    // traversing through the list
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    //establishing link b/w last node and new node
    temp->link = new;
    
    return SUCCESS;
}
