#include "stack.h"

int Pop(Stack_t **top)
{
    // checking if stack is empty
    if (*top == NULL)
    {
        return FAILURE;
    }
    
    // creating temporary pointer
    Stack_t *temp = *top;

    // Pointing the temporary pointer to the first node
    *top = temp->link;

    // Deallocating first node memory
    free(temp);
    return SUCCESS;
}