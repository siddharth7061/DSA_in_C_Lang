#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{	
    // checking list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // creating temp pointer poiting to first node
    Dlist *temp = *head;

    // Checking if first node is equal to gievn data
    if (temp->data == data)
    {
        // Pointing head pointer to the next node
        *head = temp->next;
        temp->next->prev = NULL;

        // Deallocating memory
        free(temp);
        return SUCCESS;
    }
    
    // Traversing through the list
    while (temp->next != NULL)
    {
        // Checking if the node data is equal to the given data
        if (temp->next->data == data)
        {
            // creating a reference pointer to store address of the node which is to be deleted
            Dlist *ref = temp->next;
            temp->next = ref->next;

            // Checking if the given node is the last node
            if (ref->next != NULL)
            {
                ref->next->prev = temp;
            }
            else
            {
                *tail = temp;
            }

            // Deallocating memory
            free(ref);
            return SUCCESS;
        }

        // Moving to next node
        temp = temp->next;
    }
    return DATA_NOT_FOUND;
}