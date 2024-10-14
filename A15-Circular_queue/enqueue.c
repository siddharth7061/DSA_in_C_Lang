#include "queue.h"

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{
    // If condition to check if queue is full
    if (IsQueueFull(q) == 0)
    {
        return FAILURE;
    }

    //  checking if queue is empty
    if ((q->front) == -1)
    {
        q->front = 0;
    }

    // Updating rear and data
    q->rear = (q->rear + 1) % (q->capacity);
    q->Que[q->rear] = data;
    ++(q->count);
    return SUCCESS;
}