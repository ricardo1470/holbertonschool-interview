#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to a root node of the tree to traverse
 * @node: Pointer to a function to call for each node
 * @h: height of tree
 * @level: level
 */
void binary_tree_preorder(heap_t *tree, heap_t **node, size_t h, size_t level)
{
	if (tree == NULL)
	{
		return;
	}

	if (h == level)
	{
		*node = tree;
	}
	level++;

	if (tree->left)
	{
		binary_tree_preorder(tree->left, node, h, level);
	}
	if (tree->right)
	{
		binary_tree_preorder(tree->right, node, h, level);
	}
}

/**
 * binary_tree_height - height tree
 * @tree: Pointer to the root node of the tree to measure the leaves.
 * Return: Leaves.
 **/
size_t binary_tree_height(const heap_t *tree)
{
	size_t var_left = 0;
	size_t var_right = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
	{
		return (0);
	}
	if (tree->left)
	{
		var_left = 1 + binary_tree_height(tree->left);
	}
	else
	{
		var_left = 0;
	}
	if (tree->right)
	{
		var_right = 1 + binary_tree_height(tree->right);
	}
	else
	{
		var_right = 0;
	}
	if (var_left >= var_right)
	{
		return (var_left);
	}
	else
	{
		return (var_right);
	}
}

/**
 * heap_extract - function that extracts the root node
 * @root: is a double pointer to the root node of the heap
 * Return: the value stored in the root node
 * Desc: Entry
 **/
int heap_extract(heap_t **root)
{
	int deleted, n;
	size_t level = 0;
	heap_t *aux, *del;

	if (root == NULL || *root == NULL)
		return (0);
	aux = *root, deleted = aux->n;

	if (aux->left == NULL && aux->right == NULL)
	{
		*root = NULL;
		free(aux);
		return (deleted);
	}
	binary_tree_preorder(aux, &del, binary_tree_height(aux), level);

	while (aux->left || aux->right)
	{
		if (aux->right == NULL || aux->left->n > aux->right->n)
		{
			n = aux->n, aux->n = aux->left->n;
			aux->left->n = n;
			aux = aux->left;
		}
		else if (aux->left == NULL || aux->right->n > aux->left->n)
		{
			n = aux->n, aux->n = aux->right->n;
			aux->right->n = n;
			aux = aux->right;
		}
	}
	aux->n = del->n;
	if (del->parent->right)
		del->parent->right = NULL;

	else
		del->parent->left = NULL;

	free(del);
	return (deleted);
}
