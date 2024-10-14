#include "inverted_search.h"

void search_database(Wlist *head, char *word)
{
	// Check list is empty not and then traverse
	while (head != NULL)
	{

		// Comparing the given word with stored words
		if (!(strcmp(head->word, word)))
		{
			printf("Word %s is present in %d file\n ", head->word, head->file_count);

			Ltable *Thead = head->Tlink;

			while (Thead)
			{
				printf("In File : %s\t%d times \n", Thead->file_name, Thead->word_count);
				Thead = Thead->table_link;
			}
			return;
			// printf("\n");
		}
		head = head->link;
	}
	printf("Error: Search word is not found in list \n");
}
