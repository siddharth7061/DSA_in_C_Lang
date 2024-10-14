#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    // checking list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // creating temp pointer
    Slist *temp = *head;

    // Checking if 1st node is equal to the given data
    if (temp->data == data)
    {
        // Storing address of the node which is to be deleted
        Slist *ref = temp->link;

        // Pointing head to next node
        *head = ref;

        // Deallocating memory
        free(temp);
        return SUCCESS;
    }

    // Checking the list from 2nd node
    while (temp->link != NULL)
    {
        if (temp->link->data != data)
        {
            temp = temp->link;
        }
        else
        {
            // Storing address of the node which is to be deleted
            Slist *ref = temp->link;

            // Updating link of previous node
            temp->link = ref->link;

            // deallocating memory
            free(ref);
            return SUCCESS;
        }
    }

    return DATA_NOT_FOUND;
}