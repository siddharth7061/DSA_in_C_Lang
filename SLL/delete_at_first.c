#include "sll.h"

int sl_delete_first(slist **head)
{
    // checking list is empty or not
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // create local reference pointer and pointing to the first node
    slist *temp = *head;

    // pointing head pointer to next node
    *head = temp ->link;

    // deallocating first node memory
    free(temp);

    return SUCCESS;
}