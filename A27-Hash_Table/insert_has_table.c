#include"hash.h"

int insert_HT(hash_t *arr, int element, int size)
{
    // declaring variable for indexing and finding value
    int i = element % size;
    if (arr[i].value == -1)
    {
        arr[i].value = element;
        return SUCCESS;
    }
    
    // allocate heap memory
    hash_t *new = malloc(sizeof(hash_t));

    // memory validation
    if (new == NULL)
    {
        return FAILURE;
    }
    
    // updating values
    new->value = element;
    new->index = i;

    // establishing links
    if (arr[i].link == NULL)
    {
        arr[i].link = new;
        return SUCCESS;
    }
    
    // Traversing through the table to the last node
    hash_t *temp = arr[i].link;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    // establishing link bw last node and the new node
    temp->link = new;
    return SUCCESS;
}