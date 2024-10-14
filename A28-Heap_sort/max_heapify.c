#include "main.h"

/* Function to check the number is minimum or maximum to decide the position */
void max_heap(int *heap, int i, int size)
{
    // Declaring large variable, left and right child indexes
    int large, l = 2*i + 1, r = 2*i + 2;

    // checking if array of index is less than array of left child and left is less than size
    if (heap[i] < heap[l] && l < size)
    {
       // intialising large with left child index
       large = l; 
    }
    else
    {
      // storing index value in large
      large = i;  
    }

    // checking if array of large is less than array of right child and right is less than size
    if (heap[large] < heap[r] && r < size)
    {
       // storing right child index in large
       large = r; 
    }

    // checking index is not equal to large
    if (i != large)  
    {
        //swapping
        int temp = heap[large];
        heap[large] = heap[i];
        heap[i] = temp;
        max_heap(heap, large, size); 
        
    }
      
}