
#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

// MACROS
#define FAILURE -1
#define SUCCESS 0
#define FNAME_SIZE 20
#define WORD_SIZE 15
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4

//Structures for file list
typedef char data_t;
typedef struct file_node
{
    data_t file_name[FNAME_SIZE];
    struct file_node *link;
}Flist;

//Structure for link table
typedef struct linkTable_node
{
    int word_count;
    data_t file_name[FNAME_SIZE];
    struct linkTable_node *table_link;
}Ltable;

//Sructure to store word count
typedef struct word_node
{
    int file_count;
    data_t word[WORD_SIZE];
    Ltable *Tlink;
    struct word_node *link;
}Wlist;

//Create Flist files
int to_create_list_of_files(Flist **head, char *filename);
void create_database(Flist *f_head, Wlist *head[]);
//read contents of a file
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename);
// Create word_list
int insert_at_last(Wlist **head, data_t *data);
// Update linktable
int update_link_table(Wlist **head);
//Update
int update_word_count(Wlist **f_head, char *file_name);
//print word_count
int print_word_count(Wlist *head);
//Searching a word
void search_database(Wlist *head, char *word);
//display
void display_database( Wlist *head[] );

//Save_database
void save_database(Wlist *head[]);
//Write database
void write_databasefile(Wlist *head, FILE* databasefile);

int file_insert (Flist** head, char* filename);
//update
void update_database( Wlist *head[], Flist **f_head);
int isFileEmpty(char *filename);
void file_validation_n_file_list(Flist **f_head, char *argv[]);

#endif
