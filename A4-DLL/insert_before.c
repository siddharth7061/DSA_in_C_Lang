#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    // checking list is empty
    if (*head == *tail)
    {
        return LIST_EMPTY;
    }
    
    // creating temp pointer
    Dlist *temp = *head;

    // Checking if first node is equal to given data
    if (temp->data == gdata)
    {
        // creating new node
        Dlist *new = malloc(sizeof(Dlist));

        // memory validation
        if (new == NULL)
        {
            return FAILURE;
        }

        // assigning new data value to new node
        new->data = ndata;

        // pointing head pointer to new node
        new->next = temp;
        *head = new;
        return SUCCESS;
    }

    while (temp->next != NULL)
    {
        if (temp->next->data != gdata)
        {
            temp = temp->next;
        }
        else
        {
            // creating new node
            Dlist *new = malloc(sizeof(Dlist));

            // memory validation
            if (new == NULL)
            {
                return FAILURE;
            }

            // assigning new data value to new node
            new->data = ndata;

            new->next = temp->next;
            new->prev = temp;
            temp->next = new;
            return SUCCESS;
        }
    }
    return DATA_NOT_FOUND;
}