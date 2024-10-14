#include "tree.h"

/* Function to print the data in in order printing */
int inorder(Tree_t *root)
{
    // checking if root is NULL
    if (root != NULL)
    {
        // recursively calling inorder function and passing left node address
        inorder(root->left);
        // Printing root data
        printf("%d", root->data);
        // Recursively calling inorder function and passing right node address
        inorder(root->right);
    }
    
}