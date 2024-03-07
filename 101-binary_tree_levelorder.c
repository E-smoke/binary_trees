#include "binary_trees.h"
/**
 * binary_tree_levelorder - level traversal
 * @tree: ptr to root
 * @func: function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
queue *front, *end;
if (tree != NULL && func != NULL)
{
end = (queue *)malloc(sizeof(queue));
if (end == NULL)
{
return;
}
front = end;
end->prev = NULL;
end->node = (binary_tree_t *)tree;
end->next = NULL;
level(front, func);
}
}
/**
 * level - recursive function
 * @front: ptr to front of queue
 * @func: function
 */
void level(queue *front, void (*func)(int))
{
queue *front1, *end1, *temp;
front1 = NULL;
end1 = NULL;
if (front == NULL)
{
return;
}
while (front != NULL)
{
left(&front, &front1, &end1, &temp);
right(&front, &front1, &end1, &temp);
func(front->node->n);
temp = front->prev;
free(front);
front = temp;
}
level(front1, func);
}
/**
 * left - does something
 * @front: 1p
 * @front1: 2p
 * @end1: 3p
 * @temp: 4p
 */
void left(queue **front, queue **front1, queue **end1, queue **temp)
{
if ((*front)->node->left != NULL)
{
(*temp) = (*end1);
(*end1) = (queue *)malloc(sizeof(queue));
if ((*end1) != NULL)
{
if ((*temp) != NULL)
{
(*temp)->prev = (*end1);
}
(*end1)->prev = NULL;
(*end1)->node = (*front)->node->left;
(*end1)->next = (*temp);
if ((*front1) == NULL)
{
(*front1) = (*end1);
}
}
}
}
/**
 * right - does something
 * @front: 1p
 * @front1: 2p
 * @end1: 3p
 * @temp: 4p
 */
void right(queue **front, queue **front1, queue **end1, queue **temp)
{
if ((*front)->node->right != NULL)
{
(*temp) = (*end1);
(*end1) = (queue *)malloc(sizeof(queue));
if ((*end1) != NULL)
{
if ((*temp) != NULL)
{
(*temp)->prev = (*end1);
}
(*end1)->prev = NULL;
(*end1)->node = (*front)->node->right;
(*end1)->next = (*temp);
if ((*front1) == NULL)
{
(*front1) = (*end1);
}
}
}
}
