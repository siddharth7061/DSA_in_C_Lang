#include "main.h"

data_t insertion(data_t *arr, data_t size)
{
    // Declaring variables
    int temp,j;
    
    // Starting loop from 2nd element onwards
    for (int i = 1; i < size; i++)
    {
        // Storing the ith element in temp which is compared with sorted elements
        temp = arr[i];
        // Updating j value
        j = i-1;

        // Sorting elements
        while ((j>=0) && (arr[j] > temp))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    return 0;
}
