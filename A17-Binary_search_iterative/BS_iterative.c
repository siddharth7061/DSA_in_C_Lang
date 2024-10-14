#include "main.h"

/* Function for binary search using iterations */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
    // Declaring low, mid and high variable
    int low = 0, high = size - 1, mid;

    // Searching for the key
    while (low <= high)
    {
        // Assigning mid value
        mid = (low+high)/2;

        // Checking if the key is found
        if (arr[mid] == key)
        {
            return mid;
        }
        // Checing if key is less than the mid array element
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        // When key is greater than the mid array element
        else
        {
            low = mid + 1;
        }
    }
    return DATA_NOT_FOUND;
}