#include "tree.h"

int find_height(Tree_t *root)
{
    int count = 0;
    if (root == NULL)
    {
        return 0;
    }

    int left = find_height(root->left);
    int right = find_height(root->right);
    if (left > right)
    {
        count = left + 1;
    }
    else
    {
        count = 1 + right;
    }
    return count;
}