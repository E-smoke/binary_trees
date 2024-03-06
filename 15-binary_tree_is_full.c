#include "binary_trees.h"
/**
 * binary_tree_is_full - check if binary tree is full
 * @tree: ptr to root
 * Return: 1 if full else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
int ls, rs;
bool null, not_null;
static int check = 1;
if (tree != NULL)
{
ls = binary_tree_is_full(tree->left);
rs = binary_tree_is_full(tree->right);
null = tree->left == NULL && tree->right == NULL;
not_null = tree->left != NULL && tree->right != NULL;
check = ls > rs ? rs : ls;
if (check == 0 && !(null))
{
return (check);
}
if (!(null || not_null))
{
check = 0;
}
else
{
check = 1;
}
return (check);
}
return (0);
}
