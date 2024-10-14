#include "tree.h"

/* Iteratively */
int search_BST(Tree_t * root, int data)
{
    // checking if tree is empty
    if (root == NULL)
    {
        return FAILURE;
    }

    // Declaring temp pointer
    Tree_t *temp = root;

    // Traversing through the tree
    while (temp != NULL)
    {
        // If key is less than the root element
        if (data < temp->data)
        {
            temp = temp->left;
        }
        // If key is greater than the root element
        else if (data > temp->data)
        {
            temp = temp->right;
        }
        // When the key is found below statement will be executed
        else
        {
            return SUCCESS;
        }
        
    }
    // returning noelement macro when key is not forund in the given tree
    return NOELEMENT;
}