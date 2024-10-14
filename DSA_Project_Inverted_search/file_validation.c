#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    // Reading file and checking if it is empty
    int i = 1, ret_val, empty;
    while (argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if (empty == FILE_NOTAVAILABLE)
        {
            printf("The file %s is not available\n", argv[i]);
            printf("Hence we are not adding this into File Linked List\n");
            i++;
            continue;
        }
        else if (empty == FILE_EMPTY)
        {
            printf("The file %s is Empty\n", argv[i]);
            printf("Hence we are not adding %s into File Linked List\n", argv[i]);
            i++;
            continue;
        }
        else
        {
            // Adding file to linked list
            ret_val = to_create_list_of_files(f_head, argv[i]);
            if (ret_val == SUCCESS)
            {
                printf("Successful in Inserting file %s into the File Linked List\n", argv[i]);
            }
            else if (ret_val == REPEATATION)
            {
                printf("This file %s is Repeated\n", argv[i]);
                printf("Hence we are not adding %s into file Linked List\n", argv[i]);
            }
            else
            {
                // Error message
                printf("Failed to add the file into the File Linked List");
            }
            i++;
        }
    }
}

// Checking availability of content

int isFileEmpty(char *filename)
{
    // Opening the file read only mode
    FILE *fptr = fopen(filename, "r");

    // Memory validation
    if (fptr == NULL)
    {
        return FILE_NOTAVAILABLE;
    }

    // Checking if file is empty
    fseek(fptr, 0L, SEEK_END);
    if (ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
    return SUCCESS;
}

// Adding file to flist
int to_create_list_of_files(Flist **head, char *filename)
{
    Flist *temp = *head;
    while (temp != NULL)
    {
        if (strcmp(temp->file_name, filename) == 0)
        {
            return REPEATATION;
        }
        temp = temp->link;
    }

    // Creating new node
    Flist *new_file = malloc(sizeof(Flist));

    // Memory validation
    if (new_file == NULL)
    {
        return FAILURE;
    }

    // Updating filename and links
    strcpy(new_file->file_name, filename);
    new_file->link = NULL;
    if (*head == NULL)
    {
        *head = new_file;
        return SUCCESS;
    }

    temp = *head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new_file;
    return SUCCESS;
}
