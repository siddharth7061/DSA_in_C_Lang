#include "main.h"

data_t selection(data_t *arr, data_t size)
{
    // declaring min and temp variables
    int min, temp;

    // Traversing through the array to sort elements
    for (int i = 0; i < size - 1; i++)
    {
        // Assining i value to min after each iteration
        min = i;
        // Loop to compare min element with other elements from unsurted subarray
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        // If min element found from unsorted list then swap
        if (min != i)
        {
            // Swapping elements using temp variable
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
