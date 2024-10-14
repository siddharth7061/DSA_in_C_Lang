#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
    // checking if list is empty
    if (*front == NULL)
    {
        return FAILURE;
    }
    
    // creating a temp pointer
    Queue_t *temp = *front;

    // pointing the front pointer to next node
    *front = (*front)->link;

    // deallocating memory
    free(temp);
    return SUCCESS;
}