#include "sll.h"
void print_list(slist *head)
{
    if (head == NULL)
    {
        printf("No nodes to print\n");
    }
    else
    {
        while (head)
        {
            printf("%d -> ", head->data);
            head = head->link;
            if (head == NULL)
            {
                printf("NULL");
            }
            
        }
        printf("\n");
        
    }
    
}