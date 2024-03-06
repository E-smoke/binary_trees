#include "binary_trees.h"
/**
 * binary_tree_uncle - returns ptr to sibling
 * @node: ptr to node
 * Return: ptr to uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (node != NULL && node->parent != NULL)
{
return (binary_tree_uncle1(node->parent));
}
return (NULL);
}
/**
 * binary_tree_uncle1 - returns ptr to sibling
 * @node: ptr to node
 * Return: ptr to uncle
 */
binary_tree_t *binary_tree_uncle1(binary_tree_t *node)
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
