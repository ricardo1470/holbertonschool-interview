#include "binary_trees.h"

/**
 * sorted_array_to_avl - binary tree AVL
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created AVL tree
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	tree = recursive_tree(array, 0, (int)size - 1);
	if (!tree)
	{
		return (NULL);
	}
	return (tree);
}

/**
 * create_node - Creates a binary tree node
 * @n: Value to put in the new node.
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_node(int n)
{
	avl_t *node = NULL;

	if (n == 0)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->n = n;
	return (node);
}

/**
 * recursive_tree - add node with recursive fuction
 * @array: array.
 * @ben: begin.
 * @end: end.
 * Return: tree
 */
avl_t *recursive_tree(int *array, int ben, int end)
{
	avl_t *left = NULL, *right = NULL, *parent = NULL;
	size_t n = 0;

	if (ben > end)
		return (NULL);
	n = (ben + end) / 2;
	left = recursive_tree(array, ben, n - 1);
	right = recursive_tree(array, n + 1, end);
	parent = create_node(array[n]);
	if (!parent)
		return (NULL);
	parent->left = left;
	parent->right = right;
	if (left)
		left->parent = parent;
	if (right)
		right->parent = parent;
	return (parent);
}
