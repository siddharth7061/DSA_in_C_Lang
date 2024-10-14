#include "sll.h"
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid)
{
    // Checking if list is empty
    if (head == NULL)
    {
        return LIST_EMPTY;
    }

    // Checking if list has only one node
    if (head->link == NULL)
    {
        // Dereferencing and storing the data present at the first node
        *mid = head->data;
        return SUCCESS;
    }

    // Declaring two temp pointers pointing to the first node
    Slist *temp1, *temp2;
    temp1 = temp2 = head;

   // Traversing through the list
    while (temp1 != NULL && temp1->link != NULL)
    {
        // Pointing two nodes ahead
        temp1 = temp1->link->link;

        // Pointing the next node to reach halfway of temp1
        temp2 = temp2->link;
    }

    // Dereferencing assigning middle node value to the mid variable, using pass by reference
    *mid = temp2->data;
    return SUCCESS;
}