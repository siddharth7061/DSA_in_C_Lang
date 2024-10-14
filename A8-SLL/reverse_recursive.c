#include "sll.h"

int reverse_recursive(Slist **head)
{
    // checking if list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // Declaring two pointers where next stays ahead
    Slist *prev = *head;
    Slist *next = prev->link;

    // checking if list has only one node
    if (next == NULL)
    {
        *head = prev;
        return SUCCESS;
    }
    
    // Calling function till last node
    reverse_recursive(&next);
    prev->link->link = prev;

    // Passing NULL to prev in each iteration
    prev->link = NULL;

    // Pointing head 
    *head = next;
    SUCCESS;
}
