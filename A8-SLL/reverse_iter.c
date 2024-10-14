#include "sll.h"

/* Function to reverse the given single linked list */
int reverse_iter(Slist **head)
{
    // checking if list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    Slist *temp1 = *head;

    // If list has only one node
    if (temp1->link == NULL)
    {
        return SUCCESS;
    }

    Slist *temp2 = *head;

    // Traversing through the list to assign temp1 and temp2
    while (temp1->link != NULL)
    {
        temp1 = temp1->link;
    }
    
    // using tail pointer to store address of the last node
    Slist *tail = temp1;

    // if list has only 2 nodes
    if (temp2->link == tail)
    {
        tail->link = temp2;
        temp2->link = NULL;
        *head = tail;
        return SUCCESS;
    }
    
    while (1)
    {
        while (temp2->link->link != temp1)
        {
            temp2 = temp2->link;
        }
        temp1->link = temp2->link;
        if (temp2 == *head)
        {
            temp2->link->link = temp2;
            temp2->link = NULL;
            *head = tail;
            return SUCCESS;
        }
        temp1 = temp1->link;
        temp2 = *head;
    }
    
    return LIST_EMPTY;
}