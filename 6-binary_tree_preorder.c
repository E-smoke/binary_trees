#include "binary_trees.h"
/**
 * binary_tree_preorder - implements preorder traversal
 * @tree: ptr to root
 * @func: ptr to function that is called for each traversal
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
if (func != NULL && tree != NULL)
{
func(tree->n);
binary_tree_preorder(tree->left, func);
binary_tree_preorder(tree->right, func);
}
}
