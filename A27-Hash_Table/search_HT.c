#include"hash.h"

int search_HT(hash_t *arr, int data, int size)
{
    // declaring variable to find the index
    int i = data % size;

    // checking if the the data is stored in the array
    if (arr[i].value == data)
    {
        return SUCCESS;
    }
    
    // declaring temp to traverse through the hash table
    hash_t *temp = arr[i].link;
    while (temp != NULL)
    {
        // if given data found then return success
        if (temp->value == data)
        {
            return SUCCESS;
        }
        
        // Moving to next node
        temp = temp->link;
    }
    
    return DATA_NOT_FOUND;
}