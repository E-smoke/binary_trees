#include "binary_trees.h"
/**
 * binary_tree_node - creates new binary tree
 * @parent: 1p
 * @value: 2p
 * Return: ptr to the node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node;
node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
if (node == NULL)
{
return (node);
}
node->n = value;
node->parent = parent;
node->left = NULL;
node->right = NULL;
return (node);
}
