#include "inverted_search.h"

// Function to print database
void display_database (Wlist *head[])
{
    printf("[index] [word] filecount file/s : file_name word_count\n");
    printf("\n--------------------------------------------------\n");
    
    for (int i = 0 ; i < 27; i++)
    {
	Wlist* temp = head[i];
       
	//Traversing till last node of wlist
        while (temp != NULL)
        {
            printf("[%d] [%s] %d files:\t", i, temp->word, temp->file_count);
            Ltable* Thead = temp->Tlink;

	    //Traversing through link table
            while (Thead != NULL)
            {
                printf("%s %d\t",Thead->file_name, Thead->word_count);
                Thead = Thead->table_link;
            }
            printf("\n");
            
	    //Updating temp to next node
            temp = temp->link;
        }
    }
    printf("\n--------------------------------------------------\n");
}



