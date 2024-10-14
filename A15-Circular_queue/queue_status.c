#include "queue.h"

// Function to check if queue is full
int IsQueueFull(Queue_t *q)
{
    if ((q->count) == (q->capacity))
    {
        return SUCCESS;
    }
    return FAILURE;
    
}

// Function to check if queue is empty
int IsQueueEmpty(Queue_t *q)
{
   if (q->count == 0)
   {
      return SUCCESS;
   }
   return FAILURE;
}