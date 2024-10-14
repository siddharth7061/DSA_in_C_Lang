#include "tree.h"

/* Function to print the tree in post order */
int postorder(Tree_t *root)
{
    if (root != NULL)
    {
        // recursively calling postorder function and passing left node address
        postorder(root->left);
        // recursively calling postorder function and passing right node address
        postorder(root->right);
        // Printing root data
        printf("%d ", root->data);
    }
}