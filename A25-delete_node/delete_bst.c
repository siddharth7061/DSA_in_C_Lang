#include "tree.h"

extern int status;
/* Function to delete the node  */
Tree_t *delete_BST(Tree_t *root, int data)
{
    if (root == NULL)
    {
        status = 1;
        return root;
    }
    if (data < root->data)
    {
        root->left = delete_BST(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete_BST(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        root->data = minvalue(root->right);
        root->right = delete_BST(root->right, root->data);
    }
    return root;
}

static int minvalue(Tree_t *root)
{
    int min = root->left->data;
    while (root->left != NULL)
    {
        min = root->left->data;
        root = root->left;
    }
    return min;
}