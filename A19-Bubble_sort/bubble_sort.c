#include "main.h"

data_t bubble(data_t *arr, int size)
{
    // temp and flag variable declaration
    int temp, flag;

    // Loop to bubble sort
    for (int i = 0; i < size - 1; i++)
    {
        // Assigning 0 value to flag after each pass
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            // If condition to check next element is smaller than current
            if (arr[j] > arr[j + 1])
            {
                // Swapping the values
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // Incrementing flag value
                flag++;
            }
        }

        // Stop the loop when flag is 0 hence no more sorting required
        if (!flag)
        {
            break;
        }
    }
    return 0;
}
