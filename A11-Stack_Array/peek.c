#include "stack.h"

/* Function for display the top of the element in Stack */
int Peek(Stack_t *s)
{
    // checking if stack is empty
    if (s->top == -1)
    {
        return FAILURE;
    }
    else
    {
        // returning the the top most element
        return s->item[s->top];
    }
}