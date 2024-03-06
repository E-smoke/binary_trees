#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if tree is perfect
 * @tree: ptr to node
 * Return: 1 if tree is node otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int h;
h = binary_tree_height(tree);
return (binary_tree_is_perfect1(tree, h));
}
/**
 * binary_tree_is_perfect1 - checks if tree is perfect
 * @tree: ptr to node
 * @h: height of tree
 * Return: 1 if tree is node otherwise 0
 */
int binary_tree_is_perfect1(const binary_tree_t *tree, int h)
{
int ls, rs, d;
bool null, not_null;
static int check = 1;
if (tree != NULL)
{
ls = binary_tree_is_perfect1(tree->left, h);
rs = binary_tree_is_perfect1(tree->right, h);
null = tree->left == NULL && tree->right == NULL;
not_null = tree->left != NULL && tree->right != NULL;
check = rs > ls ? ls : rs;
if (null)
{
d = binary_tree_depth(tree);
check = d != h ? 0 : 1;
}
if (check == 0 && !null)
{
return (check);
}
if (!(null || not_null))
{
check = 0;
}
return (check);
}
return (0);
}
/**
 * binary_tree_height - encapsulate
 * @tree: ptr to root
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
return (binary_tree_height1(tree, 0));
}
/**
 * binary_tree_height1 - finds height of a binary tree
 * @tree: ptr to root
 * @h: height
 * Return: the height
 */
size_t binary_tree_height1(const binary_tree_t *tree, size_t h)
{
size_t lh, rh;
if (tree == NULL && h == 0)
{
return (0);
}
if (tree != NULL)
{
lh = binary_tree_height1(tree->left, h + 1);
rh = binary_tree_height1(tree->right, h + 1);
if (lh > rh)
{
return (lh);
}
else
{
return (rh);
}
}
return (h - 1);
}
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
if (ptr == NULL)
{
return (depth);
}
while (ptr->parent != NULL)
{
++depth;
ptr = ptr->parent;
}
return (depth);
}
