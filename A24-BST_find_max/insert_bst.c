#include "tree.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root, int data)
{
    // Memory allocation
    Tree_t *new = malloc(sizeof(Tree_t));
    
    // memory validation
    if (new == NULL)
    {
        return FAILURE;
    }
    
    // updating data
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    // checking if tree is empty
    if (*root == NULL)
    {
        *root = new;
        return SUCCESS;
    }
    
    // creating temp pointer to traverse through the tree
    Tree_t *temp = *root;
    Tree_t *parent;
    int flag;

    // Traversing through the tree to add node
    while (temp != NULL)
    {
        // Assigning tempa ddress to parent pointer
        parent = temp;
        if (data < temp->data)
        {
            temp = temp->left;
            flag = 1;
        }
        else if (data > temp->data)
        {
            temp = temp->right;
            flag = 0;
        }
        else
        {
            return DUPLICATE;
        }
    }
    
    // checking if new node is to be placed in left side or right side
    if (flag)
    {
        parent->left = new;
    }
    else
    {
        parent->right = new;
    }
    return SUCCESS;
}