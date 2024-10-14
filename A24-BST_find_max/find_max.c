#include "tree.h"

int findmax(Tree_t * root)
{
    // checking if tree is empty
    if (root == NULL)
    {
        return FAILURE;
    }

    // Declaring temp pointer
    Tree_t *temp = root;

    // Traversing through the tree until it reaches the right most element
    while (temp->right != NULL)
    {
        // Moving to the right node
        temp = temp->right;
    }
    
    // returning the maximum data
    return temp->data;
}
