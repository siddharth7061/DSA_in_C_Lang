#include "sll.h"

// sortList() will sort nodes of the list in ascending order
int sort(Slist **head)
{
    // Checking if list is empty
    if ((*head)->link == NULL)
    {
        return SUCCESS;
    }

    // Declaring pointers and temporary variable
    Slist *prev, *next;
    int temp;

    // Loop to sort the list
    for (prev = *head; prev != NULL; prev = prev->link)
    {
        // Inner loop to compare all elements with prev node
        for (next = *head; next->link != NULL; next = next->link)
        {
            // Swap elements
            if (next->data > next->link->data)
            {
                temp = next->data;
                next->data = next->link->data;
                next->link->data = temp;
            }
        }
    }
    
    return SUCCESS;
}
