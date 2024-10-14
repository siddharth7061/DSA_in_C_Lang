#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    // Checking if list is empty
    if (*head == NULL)
    {
        return FAILURE;
    }

    //  Checking if list has only one node
    if (head == tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }

    // Updating links
    Dlist *temp = *head;
    while (temp != NULL)
    {
        // Pointing temp to next node
        *head = temp->next;

        // Deallocating first node memory
        free(temp);

        // Pointing temp to next node
        temp = *head;
    }
    *tail = NULL;
    return SUCCESS;
}