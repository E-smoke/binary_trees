#include "binary_trees.h"
/**
 * binary_tree_depth - finds the depth of a node
 * @tree: ptr to node
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth;
const binary_tree_t *ptr;
ptr = tree;
depth = 0;
while (ptr->parent != NULL)
{
++depth;
ptr = ptr->parent;
}
return (depth);
}
