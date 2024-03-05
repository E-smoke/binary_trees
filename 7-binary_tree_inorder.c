#include "binary_trees.h"
/**
 * binary_tree_inorder - implements inorder traversal
 * @tree: ptr to root
 * @func: ptr to function that is called for each traversal
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
if (func != NULL && tree != NULL)
{
binary_tree_inorder(tree->left, func);
func(tree->n);
binary_tree_inorder(tree->right, func);
}
}
