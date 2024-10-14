#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data)
{
    // checking if list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    // Creating two temp pointers
    Slist *temp1 = *head;
    Slist *temp2 = *head;

    int flag = 0;

    // Traversing through the list
    while (temp1->link != NULL)
    {
        // Pointing temp1 to next node
        temp1 = temp1->link;

        // Checking if node data is equal to the given data
        if (temp1->data == data)
        {
            temp2 =temp1;
            flag++;
        }
    }
    
    // Checking if last node data is equal to the given data
    if (temp1->data == data)
    {
        temp1->link = temp1;
        return SUCCESS;
    }
    
    // Checking if given data is found
    if (flag)
    {
        temp1->link = temp2;
        return SUCCESS;
    }

    return DATA_NOT_FOUND;
    
}