#include "binary_trees.h"
/**
 * binary_tree_leaves - counts number of leaves in a trree
 * @tree: ptr to root
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t ls, rs;
if (tree != NULL)
{
ls = binary_tree_leaves(tree->left);
rs = binary_tree_leaves(tree->right);
if (tree->left == NULL && tree->right == NULL)
{
return (ls + rs + 1);
}
else
{
return (ls + rs);
}
}
return (0);
}
