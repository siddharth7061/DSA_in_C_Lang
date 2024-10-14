#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    // checking list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // creating temp pointer
    Dlist *temp = *head;

    // Traversing through the list
    while (temp != NULL)
    {
        // Checking if the node data is equal to the given data
        if (temp->data != gdata)
        {
            temp = temp->next;
        }
        else
        {
            // Creating new node
            Dlist *new = malloc(sizeof(Dlist));

            // Memory validation
            if (new == NULL)
            {
                return FAILURE;
            }

            // Assigning data to the node and updating links
            new->data = ndata;
            new->next = temp->next;
            new->prev = temp;
            
            // Checking if given node is last node
            if (temp != *tail)
            {
                temp->next->prev = new;
            }
            else
            {
                *tail = new;
            }

            // Pointing to next node
            temp->next = new;
            return SUCCESS;
        }
    }
    return DATA_NOT_FOUND;
}