#include "stack.h"

int Peek(Stack_t *top)
{
    if (top == NULL)
    {
        return FAILURE;
    }
    else
    {
        return top->data;
    }
    
}