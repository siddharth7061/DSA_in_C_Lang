#include "main.h"

/* Function to search the element using binary search */
data_t binarySearch_recursive(data_t *arr, data_t size, data_t key, data_t first, data_t last)
{
    // Checking if last index is equal to first index
    if (last == first)
    {
        // If key is found in the last index
        if (arr[last] == key)
        {
            // Returing the index value
            return last;
        }
        else
        {
            return DATA_NOT_FOUND;
        }
    }
    else
    {
        // Assigning mid index value
        int mid = (last + first) / 2;

        // Checking if key is found in the mid index
        if (key == arr[mid])
        {
            return mid;
        }
         // Checking if the key is less than the mid index element
        else if (key < arr[mid])
        {
            return binarySearch_recursive(arr, size, key, first, last - 1);
        }
        else
        {
            return binarySearch_recursive(arr, size, key, first + 1, last);
        }
    }
}
