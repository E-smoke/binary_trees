#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the number of nodes with at least a child
 * @tree: ptr to root
 * Return: the number
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t ls, rs;
if (tree != NULL)
{
ls = binary_tree_nodes(tree->left);
rs = binary_tree_nodes(tree->right);
if (tree->left != NULL || tree->right != NULL)
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
