#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{
	// checking if stack is empty
    if (s->top == s->capacity - 1)
    {
        return FAILURE;
    }
    else
    {
        // incrementing top variable
        s->top++;

        // Storing element
        s->item[s->top] = element;
        return SUCCESS;
    }
}