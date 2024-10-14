#include "inverted_search.h"

extern char *fname;
int insert_at_last(Wlist **head, data_t *data)
{
    // Creating new node
    Wlist *new = malloc(sizeof(Wlist));
    if (new == NULL)
    {
        return FAILURE;
    }

    // Updating links
    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;

    // Calling function to update link table
    update_link_table(&new);

    // Checking if wlist is empty
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // creating temp node
    Wlist *temp = *head;

    // Traversing through wlist

    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

// Updating link table
int update_link_table(Wlist **head)
{
    // create new node
    Ltable *new = malloc(sizeof(Ltable));

    // Memory validation
    if (new == NULL)
    {
        return FAILURE;
    }

    // updating value and link
    new->word_count = 1;
    strcpy(new->file_name, fname);
    new->table_link = NULL;

    (*head)->Tlink = new;
    return SUCCESS;
}
