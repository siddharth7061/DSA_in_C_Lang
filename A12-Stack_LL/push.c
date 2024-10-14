#include "stack.h"

int Push(Stack_t **top, data_t data)
{
    /* Creating the new node */
    Stack_t *new = malloc(sizeof(Stack_t));

    /* Check whether new node created or not */
    if (new == NULL)
    {
        return FAILURE;
    }

    /* Fill the parts of the node */
    new->data = data;
    new->link = NULL;

    /* If stack is empty */
    if (*top == NULL)
    {
        /* If stack is empty then create the first node */
        *top = new;
        return SUCCESS;
    }
    else
    {
        /* stack is not empty then store link address in the temp pointer */
        Stack_t *temp = *top;

        /* Stroring new link in the top inserting the element at first */
        *top = new;

        /* Creating the link to next node */
        new->link = temp;
    }

    return SUCCESS;
}