#include "queue.h"

/* Function to deque the element */
int dequeue(Queue_t *q)
{
    // Checking if queue is empty
    if (IsQueueEmpty(q) == 0)
    {
        return FAILURE;
    }
    
    // Declaring element variable to store the data which is to be deleted
    int element = q->Que[q->front];

    // Updating front and count value
    q->front = ((q->front + 1) % (q->capacity));
    --(q->count);
    return SUCCESS;
}