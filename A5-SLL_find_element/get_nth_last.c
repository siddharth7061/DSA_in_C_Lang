#include "sll.h"
/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{ 
    // Checking if list is empty
    if (head == NULL)
    {
        return LIST_EMPTY;
    }
    
    // Declaring temp pointer and pointing it to first node
    Slist *temp = head;
    int num = 1, n = 1;

    // Traversing through the list and finding the size of list
    while (temp->link != NULL)
    {
        temp = temp->link;

        // Incrementing num to find the size of list
        num++;
    }

    // Checking if given position is valid or not
    if (pos < 1 || pos > num)
    {
        return FAILURE;
    }
    
    // Again pointing temp pointer to first node
    temp = head;

    // Traversing till the nth last node
    while (n <= num - pos)
    {
        temp = temp->link;

        // Incrementing n value for each iteration
        n++;
    }

    // Dereferencing the data pointer and storing the data
    *data = temp->data;
    return SUCCESS;

    
    
} 