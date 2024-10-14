#include "main.h"

/* Function to partition the array */
int partition(int *arr, int first, int last)
{
    // Declaring start end and temp variable
    int pivot = first, start = first, end = last, temp;

    // run loop until start is greater than end
    while (start < end)
    {
        // incrementing start index value until start element is greater than pivot element
        while (arr[start] <= arr[pivot])
        {
            ++start;
        }

        // increment end index value until end element is less than the pivot element
        while (arr[end] > arr[pivot])
        {
            --end;
        }

        //  Swap the start and end index elements when start is less than end
        if (start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    // Swapping first and end element
    temp = arr[first];
    arr[first] = arr[end];
    arr[end] = temp;
    // returning end element
    return end;
}
