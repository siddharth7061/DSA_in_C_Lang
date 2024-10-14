#include "tree.h"

int findmin(Tree_t *root)
{
    // checking if tree is empty
    if (root == NULL)
    {
        return FAILURE;
    }

    // Declaring temp pointer
    Tree_t *temp = root;

    // Traversing through the tree until it reaches the left most element
    while (temp->left != NULL)
    {
        // Moving to the left node
        temp = temp->left;
    }
    // returning minimum data
    return temp->data;
}
