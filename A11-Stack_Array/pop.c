#include "stack.h"

/* Function for Poping the element */
int Pop(Stack_t *s)
{
    // checking if stack is empty
    if (s->top == -1)
    {
        return FAILURE;
    }
    else
    {
        // decrementing the top variable
        --(s->top);
        return SUCCESS;
    }
}