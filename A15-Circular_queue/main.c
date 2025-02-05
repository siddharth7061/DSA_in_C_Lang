/*
Name : Siddharth Singh
Date : 11/10/2022
Description : Circular queue implementation using array
sample input : 3 1 10 1 20 1 30 2 3 4
sample output : Front -> 20 30 <- Rear 
*/

#include "queue.h"
 // Function to create queue
int create_queue(Queue_t *q, int size)
{
  // Heap memory allocation
  q->Que = malloc(sizeof(int) * size);

  // Memory validation
  if (q->Que == NULL)
  {
    return FAILURE;
  }

  // Updating parts
  q->capacity = size;
  q->count = 0;
  q->front = -1;
  q->rear = -1;
  return SUCCESS;
}

int main()
{
	Queue_t q;
	int size;
	printf("Enter the size of the queue : ");
	scanf("%d", &size);
	if (create_queue(&q, size) == FAILURE)
	{
	    printf("INFO : Queue not created\n");
	    return FAILURE;
	}

	char ch;
	int choice, data;
	printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the option : ");
	while (1)
	{
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				/* Function to Enqueue the Queue */
				printf("Enter the element you want to insert : ");
				scanf("%d", &data);
				if (enqueue(&q, data) == FAILURE)
				{
					printf("INFO : Queue full\n");
				}
				break;
			case 2:
				/* Function to dequeueue the queue */
				if (dequeue(&q) == FAILURE)
				{
					printf("INFO : Queue is empty\n");
				}
				else
				{
					printf("INFO : Dequeue successfull\n");
				}
				break;
			case 3:
				/* Function to print the queue */
				print_queue(q);
				break;
			case 4:
				return SUCCESS;
			default:
				printf("Invalid option !!!\n");
		}

	}
}