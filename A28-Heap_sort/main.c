
/*
Name : Siddharth Singh
Date : 27/10/2022
Description : Sorting array using heap sort
sample input : 5 5 4 3 2 1
sample output : Sorted array is : 1 2 3 4 5
*/

#include "main.h"

/* Main Function */
int main()
{
	int i, limit;

	/* Scanning the size */
	printf("Enter the size of an array\n");
	scanf("%d", &limit);

	/* Declaring the array with size */
	int heap[limit];

		
	printf("Enter the array elements\n");
	for (i = 0; i < limit; i++)
	{
	    /* Scanning the array elements */
		scanf("%d", &heap[i]);
	}
		

    build_maxheap(heap, limit);
    
	/* Calling the function to bubble sort */
	heap_sort(heap, limit);
	
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", heap[i]);
	}
		
	return 0;
}
