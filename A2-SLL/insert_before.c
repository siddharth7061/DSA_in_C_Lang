#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    // checking list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // creating temp pointer
    Slist *temp = *head;

    if (temp->data == g_data)
    {
        // creating new node
        Slist *new = malloc(sizeof(Slist));

        // memory validation
        if (new == NULL)
        {
            return FAILURE;
        }

        // assigning new data value to new node
        new->data = ndata;

        // pointing head pointer to new node
        new->link = temp;
        *head = new;
        return SUCCESS;
    }

    // Traversing through the list
    while (temp->link != NULL)
    {
        if (temp->link->data != g_data)
        {
            temp = temp->link;
        }
        else
        {
            // creating new node
            Slist *new = malloc(sizeof(Slist));

            // memory validation
            if (new == NULL)
            {
                return FAILURE;
            }

            // assigning new data value to new node
            new->data = ndata;

            // Updating link
            new->link = temp->link;
            temp->link = new;

            return SUCCESS;
        }
    }
    return DATA_NOT_FOUND;
}