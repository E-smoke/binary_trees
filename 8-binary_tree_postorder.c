#include "binary_trees.h"
/**
 * binary_tree_postorder - implements postorder traversal
 * @tree: ptr to root
 * @func: ptr to function that is called for each traversal
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (func != NULL && tree != NULL)
{
binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);
func(tree->n);
}
}
