#include "binary_trees.h"
/**
 * binary_tree_size - return size of tree
 * @tree: ptr to root
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t ls, rs;
if (tree != NULL)
{
ls = binary_tree_size(tree->left);
rs = binary_tree_size(tree->right);
return (ls + rs + 1);
}
return (0);
}
