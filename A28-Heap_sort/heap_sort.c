#include "main.h"

/* Function to sort the array using heap sort */
int heap_sort(int *heap, int size )
{
    // calling build max heap function
    build_maxheap(heap,size);

     // declaring index variable and finding index value
    int i = size - 1;

    // Looping till index reaches 0
    while(i >= 0)
    {
        // Swapping
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

         // calling maxheap function
        max_heap(heap,0,i);

        // decrementing index value
        i--;
    }
    
}