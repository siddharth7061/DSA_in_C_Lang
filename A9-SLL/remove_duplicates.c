#include "sll.h"

// remove duplicate data's from list
int remove_duplicates(Slist **head)
{
    // checking if list is empty
    if (*head == NULL)
    {
        return FAILURE;
    }

    // creating 2 temp pointers and one pointer to store address of duplicates
    Slist *temp1, *temp2, *ref;
    temp1 = temp2 = *head;

    // Traversing through the list
    while (temp1 != NULL)
    {
        // Traversing through the list to find duplicates
        while (temp2->link != NULL)
        {
            if (temp1->data == temp2->link->data && temp1 != temp2->link)
            {
                // Storing address of the node which is to be deleted
                ref = temp2->link;

                // Updating link of previous node
                temp2->link = ref->link;

                // Deallocating memory
                free(ref);
            }
            else
            {
                temp2 = temp2->link;
            }
        }
        temp1 = temp1->link;
        temp2 = temp1;
    }
    return SUCCESS;
}