#include "main.h"

void build_maxheap(int *heap, int size)
{
    // Declaring index variable and finiding index
    int i = size/2;

    // Looping till it reaches 0
    while(i >= 0)
    {
        // calling maxheap function
        max_heap(heap,i,size);

        // decrementing index
        i--;
    }
}