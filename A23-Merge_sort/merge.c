#include "main.h"

void merge(int *array, int narray, int *left, int nleft, int *right, int nright)
{
    int i, j, k;
    i = j = k = 0;

    while (i < nleft && j < (narray - nleft))
    {
        if (left[i] < right[j])
        {
            array[k] = left[i];
            i++;
            k++;
        }
        else
        {
            array[k] = right[j];
            j++;
            k++;
        }
    }
    while (j < nright)
    {
        array[k] = right[j];
        j++;
        k++;
    }
    while (i < nleft)
    {
        array[k] = right[i];
        i++;
        k++;
    }
}
