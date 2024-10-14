#include "sll.h"

int sl_delete_list(slist **head)
{
    // checking list is empty or not
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // create local reference pointer and pointing to the first node
    slist *temp = *head;

    while (temp != NULL)
    {
        // pointing head pointer to next node
        *head = temp->link;

        // deallocating first node memory
        free(temp);

        //pointing tep pointer to next node
        temp = *head;
    }
    return SUCCESS;
}