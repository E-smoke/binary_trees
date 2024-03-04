#include "binary_trees.h"
/**
 * binary_tree_insert_left - insert to the left in binary tree
 * @parent: 1p
 * @value: 2p
 * Return: the node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *node;
node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
if (node == NULL || parent == NULL)
{
return (NULL);
}
node->n = value;
node->parent = parent;
node->right = NULL;
if (parent->left != NULL)
{
parent->left->parent = node;
node->left = parent->left;
parent->left = node;
}
else
{
parent->left = node;
node->left = NULL;
}
return (node);
}
