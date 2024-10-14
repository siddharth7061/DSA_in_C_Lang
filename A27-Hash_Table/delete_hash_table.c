#include "hash.h"

int destroy_HT(hash_t *arr, int size)
{
    // declaring pointers to traverse through the table and delete nodes
    hash_t *temp = NULL, *temp1;

    // Loop to traverse the array
    for (int i = 0; i < size; i++)
    {
        // if the index is not empty
        if (arr[i].value != -1)
        {
            // Updating values and links
            temp = arr[i].link;
            arr[i].value = -1;
            arr[i].link = NULL;
        }

        // Traversing through the table until temp reaches NULL
        while (temp)
        {
            // Storing next node address in temp1
            temp1 = temp->link;
            // Deallocating memory
            free(temp);
            temp = temp1;
        }
    }
    return SUCCESS;
}