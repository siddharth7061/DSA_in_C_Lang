#include "sll.h"

int sorted_merge(Slist **head1, Slist **head2)
{
    // Checking if both lists are empty
    if (*head1 == NULL && *head2 == NULL)
    {
        return LIST_EMPTY;
    }

    // Checking if only first list is empty
    if (*head1 == NULL)
    {
        *head1 = *head2;
        // Calling dort function to sort the list
        if (sort(head1) == SUCCESS)
        {
            return SUCCESS;
        }
        return FAILURE;
    }

    // Checking if only second list is empty
    if (*head2 == NULL)
    {
        *head2 = *head1;
        // Calling dort function to sort the list
        if (sort(head1) == SUCCESS)
        {
            return SUCCESS;
        }
        return FAILURE;
    }

    // Pointing temp to first list
    Slist *temp = *head1;

    // Traversing through the list to point the temp to last node
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    // Establishing link bw last node of first list and the first node of second list
    temp->link = *head2;
    
    // Calling dort function to sort the list
    if (sort(head1) == SUCCESS)
    {
        return SUCCESS;
    }
    return FAILURE;
}