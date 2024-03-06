#include "binary_trees.h"
/**
 * binary_tree_sibling - returns ptr to sibling
 * @node: ptr to node
 * Return: ptr to sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
binary_tree_t *sibling;
if (node != NULL && node->parent != NULL)
{
sibling = node->parent->left;
if (sibling == node)
{
return (node->parent->right);
}
else
{
return (sibling);
}
}
return (NULL);
}
