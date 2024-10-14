#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    // checking list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // creating temp pointer
    Slist *temp = *head;

    // Traversing through the list
    while (temp != NULL)
    {
        // Comparing given data with the nodes
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

            // Updating link
            new->link = temp->link;
            temp->link = new;
            
            return SUCCESS;
        }
        // Moving temp to next node
        temp = temp->link;
    }
    return DATA_NOT_FOUND;
}