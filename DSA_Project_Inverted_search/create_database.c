#include "inverted_search.h"

char *fname;
void create_database(Flist *f_head, Wlist *head[])
{
	// Traversing through the file linked list
	while (f_head)
	{
		read_datafile(f_head, head, f_head->file_name);
		f_head = f_head->link;
	}
}

// Reading data file for flist
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
	// Opening file in read mode
	fname = filename;
	FILE *fptr = fopen(filename, "r");
	char word[WORD_SIZE];

	int flag = 1;

	if (fptr == NULL)
	{
		printf("Error in opening %s file\n", filename);
	}
	while (fscanf(fptr, "%s", word) != EOF)
	{
		// index
		int index = tolower(word[0]) % 97;

		// index if apart from alphabets
		if (!(index >= 0 && index <= 25))
			index = 26;

		if (head[index] != NULL)
		{
			Wlist *temp = head[index];

			// Compare the words at each node with new word
			while (temp)
			{
				if (!strcmp(temp->word, word))
				{
					update_word_count(&temp, filename);
					flag = 0;
					break;
				}
				temp = temp->link;
			}
		}
		// calling insert at last function when no words are repeated
		if (flag == 1)
		{
			insert_at_last(&head[index], word);
		}
	}
	printf("Successfully created database for %s file\n", filename);
}

// Updating word count function
int update_word_count(Wlist **head, char *file_name)
{
	Ltable *l_temp = (*head)->Tlink, *prev = NULL;
	while (l_temp)
	{
		// Chercking for same filenames
		if (!strcmp(l_temp->file_name, file_name))
		{
			// Incrementing word count
			l_temp->word_count++;
			return SUCCESS;
		}
		prev = l_temp;
		l_temp = l_temp->table_link;
	}

	// Incrementing file count and updating its value
	(*head)->file_count++;

	// creating new node in ltable
	Ltable *new_link_table_node = malloc(sizeof(Ltable));

	// Memory validation
	if (new_link_table_node == NULL)
	{
		return FAILURE;
	}

	// Upadating values
	strcpy(new_link_table_node->file_name, file_name);
	new_link_table_node->word_count = 1;
	new_link_table_node->table_link = NULL;

	// creating link between prev and new node
	prev->table_link = new_link_table_node;
	return SUCCESS;
}
