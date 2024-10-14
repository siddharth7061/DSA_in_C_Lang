#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted(Slist **head, data_t data)
{
    // Allocating memory and assigning data
    Slist *new = malloc(sizeof(Slist));
    new->data = data;

    // If condition to check if list is empty
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // Ceating two temp pointers
    Slist *temp1 = *head, *temp2 = *head;

    // Traverse through the list
    while (temp1 != NULL)
    {
        // checking if the first node data is greater than the given data
        if ((*head == temp1) && (temp1->data > data))
        {
            // creating link bw new node and fist node
            new->link = temp1;
            // pointing head pointer to the new node
            *head = new;
            return SUCCESS;
        }

        // checking if the middle node data is greater than the given data
        else if ((temp1->link != NULL) && (temp1->link->data > data))
        {
            // updating links
            temp2 = temp1->link;
            temp1->link = new;
            new->link = temp2;
            return SUCCESS;
        }
        temp2 = temp1;
        temp1 = temp1->link;
    }

    // linking new node at last
    temp2->link = new;
    new->link = NULL;
    return SUCCESS;
}