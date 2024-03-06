#include "binary_trees.h"
/**
 * binary_tree_height - encapsulate
 * @tree: ptr to root
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
return (binary_tree_height1(tree, 0));
}
/**
 * binary_tree_height1 - finds height of a binary tree
 * @tree: ptr to root
 * @h: height
 * Return: the height
 */
size_t binary_tree_height1(const binary_tree_t *tree, size_t h)
{
size_t lh, rh;
if (tree == NULL && h == 0)
{
return (0);
}
if (tree != NULL)
{
lh = binary_tree_height1(tree->left, h + 1);
rh = binary_tree_height1(tree->right, h + 1);
if (lh > rh)
{
return (lh);
}
else
{
return (rh);
}
}
return (h - 1);
}
