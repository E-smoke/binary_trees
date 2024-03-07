#include "binary_trees.h"
#define binary binary_tree_t
/**
 * binary_trees_ancestor - returns lowest common ancestor
 * @first: 1p
 * @second: 2p
 * Return: ptr to lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary *first, const binary *second)
{
int fh, sh, d, i;
fh = binary_tree_depth(first);
sh = binary_tree_depth(second);
d = fh - sh;
if (d != 0)
{
if (d > 0)
{
for (i = 0; i < d; ++i)
{
first = first->parent;
}
}
else
{
for (i = 0; i < -d; ++i)
{
second = second->parent;
}
}
}
while (first != second && second != NULL && first != NULL)
{
first = first->parent;
second = second->parent;
}
if (first == NULL || second == NULL)
{
return (NULL);
}
return ((binary_tree_t *)first);
}
/**
 * binary_tree_depth - finds the depth of a node
 * @tree: ptr to node
 * Return: depth + 1
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth;
const binary_tree_t *ptr;
ptr = tree;
depth = 0;
if (ptr == NULL)
{
return (depth);
}
while (ptr->parent != NULL)
{
++depth;
ptr = ptr->parent;
}
return (depth + 1);
}
