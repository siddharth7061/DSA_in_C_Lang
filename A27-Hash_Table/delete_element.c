#include "hash.h"

int delete_element(hash_t *arr, int data, int size)
{
    // declaring variable to find the index
    int i = data % size, flag = 0;

    // declaring temp to traverse through the hash table
    hash_t *temp = arr[i].link;
    hash_t *prev = temp;

    // checking if given data is stored in the array
    if (arr[i].value == data)
    {
        // updating value with -1
        arr[i].value = -1;

        // checking if there are other nodes linked to it
        if (temp != NULL)
        {
            // if nodes are found then update the data values and free the node
            arr[i].value = temp->value;
            free(temp);
            arr[i].link = NULL;
        }

        return SUCCESS;
    }

    // Traversing through the table to find the given data
    while (temp != NULL)
    {
        // checking if data found
        if (temp->value == data)
        {
            // updating value
            temp->value = -1;
            
            // checking if it is a middle node
            if (temp->link != NULL)
            {
                // updating link part of the previous node
                prev->link = temp->link;

                // deallocating memory
                free(temp);
            }
            else
            {
                /* When the given node is the last node */

                // updating previous node link part with NULL
                prev->link = NULL;

                // Deallocating memory
                free(temp);
            }

            return SUCCESS;
        }

        // updating the prev pointer to next node only when the temp pointer is ahead with the help of flag variable
        if (flag)
        {
            prev = prev->link;
        }

        // moving temp pointer to next node
        temp = temp->link;
        // Updating flag value
        flag = 1;
    }

    return DATA_NOT_FOUND;
}