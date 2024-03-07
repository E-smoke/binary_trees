#include "binary_trees.h"
/**
 * binary_tree_is_complete - level traversal
 * @tree: ptr to root
 * Return: 1 if complete else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
queue *front, *end;
if (tree != NULL)
{
end = (queue *)malloc(sizeof(queue));
if (end == NULL)
{
return (0);
}
front = end;
end->prev = NULL;
end->node = (binary_tree_t *)tree;
end->next = NULL;
return (level1(front) == true ? 1 : 0);
}
return (0);
}
/**
 * level1 - recursive function
 * @front: ptr to front of queue
 * Return: bool
 */
bool level1(queue *front)
{
int count, child_no, i;
queue *front1, *end1, *temp, *child, *child_prev;
front1 = NULL;
end1 = NULL;
count = 0;
while (front != NULL)
{
++count;
left(&front, &front1, &end1, &temp);
right(&front, &front1, &end1, &temp);
temp = front->prev;
free(front);
front = temp; }
child_no = number(front1);
if (child_no == 0)
{
return (1); }
if (child_no != 2 * count)
{
child = front1;
child_prev = NULL;
count = 0;
for (i = 0; i < child_no; ++i)
{
if (child->node->left == NULL && child->node->right == NULL)
{
child_prev = child->prev == NULL ? NULL : child->prev;
if (child_prev == NULL || child->node->parent == child_prev->node->parent)
{
child = child_prev;
++count;
if (child_prev == NULL)
{
break; }}}}
return (count == child_no ? 1 : 0); }
return (1 && level1(front1)); }
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
(*front1) = (*end1); }}}}
/**
 * number - returns the length of the queue
 * @front1: front
 * Return: length of queue
 */
int number(queue *front1)
{
int count;
count = 0;
while (front1 != NULL)
{
++count;
front1 = front1->prev;
}
return (count);
}
