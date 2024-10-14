#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    // checking list is empty
    if ((*head == NULL) && (n == 1))
    {
        Slist *new = malloc(sizeof(Slist));
        new->link = NULL;
        new->data = data;
        *head = new;
        return SUCCESS;
    }
    else if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // creating temp pointer
    Slist *temp = *head;
    int count = 1;

    if (n == 1)
    {
        Slist *new = malloc(sizeof(Slist));
        // memory validation
        if (new == NULL)
        {
            return FAILURE;
        }
        new->link = *head;
        new->data = data;
        *head = new;
        return SUCCESS;
    }

    while (temp->link != NULL)
    {
        if (count != n - 1)
        {
            count++;
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
            new->data = data;

            // Updating link
            new->link = temp->link;
            temp->link = new;

            return SUCCESS;
        }
    }

    if (n - count == 1)
    {
        // creating new node
        Slist *new = malloc(sizeof(Slist));

        // memory validation
        if (new == NULL)
        {
            return FAILURE;
        }

        // assigning new data value to new node
        new->data = data;

        //Updating link
        new->link = NULL;
        temp->link = new;
    }

    return POSITION_NOT_FOUND;
}