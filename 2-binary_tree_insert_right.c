#include "binary_trees.h"
/**
 * binary_tree_insert_right - insert to the right in binary tree
 * @parent: 1p
 * @value: 2p
 * Return: the node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *node;
if (parent == NULL)
{
return (NULL);
}
node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
if (node == NULL)
{
return (NULL);
}
node->n = value;
node->parent = parent;
node->left = NULL;
if (parent->right != NULL)
{
parent->right->parent = node;
node->right = parent->right;
parent->right = node;
}
else
{
parent->right = node;
node->right = NULL;
}
return (node);
}
