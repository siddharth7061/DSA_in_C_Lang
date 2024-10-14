#include "main.h"

int merge_sort(int *array, int narray)
{
    // checking if only 1 element is present in the array
    if (narray == 1)
    {
        return SUCCESS;
    }
    else if (narray < 1)
    {
        return FAILURE;
    }

    // finding mid value
    int mid = narray / 2;

    // allocation of memory for left subarray
    int *left = (int *)malloc(sizeof(int) * mid);
    if (NULL == left)
    {
        return FAILURE;
    }

    // allocate memory right sub array
    int *right = (int *)malloc(sizeof(int) * (narray - mid));
    if (NULL == right)
    {
        return FAILURE;
    }

    // copying elements to left subarray
    for (int i = 0; i < mid; i++)
    {
        left[i] = array[i];
    }

    // copying elements to right subarray
    for (int i = mid; i < narray; i++)
    {
        right[i - mid] = array[i];
    }

    // dividing array into aubarrays
    merge_sort(left, mid);
    merge_sort(right, (narray - mid));

    // merging all subarrays
    merge(array, narray, left, mid, right, (narray - mid));

    // Deallocating
    free(left);
    free(right);
}