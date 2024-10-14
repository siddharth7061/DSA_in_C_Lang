#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
    // Checking if list is empty
    if (head == NULL)
    {
        return LIST_EMPTY;
    }
    
    // Creating two temp pointers
    Slist *temp1 = head;
    Slist *temp2 = head;

    // Traversing through the list to find loop
    while ((temp1 != NULL) && (temp2 != NULL) && (temp2->link != NULL))
    {
        // Moving temp1 by 1 node
        temp1 = temp1->link;

        // Moving temp2 by 2 nodes
        temp2 = temp2->link->link;

        // Checking if both pointers are pointing to the same node
        if (temp1 == temp2)
        {
            return SUCCESS;
        }
    }
    
    return LOOP_NOT_FOUND;
}