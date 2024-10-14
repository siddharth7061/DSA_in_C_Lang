#include "tree.h"

/* Function to print the tree in pre order */
int preorder(Tree_t *root)
{
    // checking if root is NULL
    if (root != NULL)
    {
        // Printing root data
        printf("%d", root->data);
        // recursively calling preorder function and passing left node address
        preorder(root->left);
        // Recursively calling preorder function and passing right node address
        preorder(root->right);
    }
}