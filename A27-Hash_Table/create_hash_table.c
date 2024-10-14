#include "hash.h"

void create_HT(hash_t *HT, int size)
{
    // assigning data to all indexes
    for (int i = 0; i < size; i++)
    {
        // updating index
        HT[i].index = i;
        // updating key/value
        HT[i].value = -1;
        // updating link to NULL
        HT[i].link = NULL;
    }
    
}