#include "queue.h"

int enqueue(Queue_t **front, Queue_t **rear, int data)
{
    // checking if list queue is empty
    if (*front == NULL)
    {
        // creating new node
        Queue_t *new = malloc(sizeof(Queue_t));

        // memory validation
        if (new == NULL)
        {
            return FAILURE;
        }

        // updating parts of node
        new->data = data;
        *front = new;
        *rear = new;
        return SUCCESS;
    }

    // creating new node
    Queue_t *new = malloc(sizeof(Queue_t));

    // memory validation
    if (new == NULL)
    {
        return FAILURE;
    }

    // updating data of node
    new->data = data;

    // Pointing the last node to new node
    (*rear)->link = new;

    // Pointing rear pointer to new node
    *rear = new;

    // Pointing new node link to NULL
    new->link = NULL;

    return SUCCESS;    
}