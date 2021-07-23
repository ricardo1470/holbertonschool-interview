#include "binary_trees.h"

/**
 * is_valid_avl - checks if a binary tree is a valid AVL tree
 * @tree: The root of the binary tree
 * @min: The minimum node in the tree
 * @max: The maximum node in the tree
 * @height: The height of the tree
 * Return: true if the binary tree is AVL, false otherwise
 **/
int is_valid_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		if (min <= tree->n && tree->n <= max)
		{
			*height = 1;
		}
		else
		{
			return (0);
		}
	}
	else
	{
		int left_height, right_height;

		if (tree->left == NULL || tree->right == NULL)
		{
			return (0);
		}
		if (!is_valid_avl(tree->left, min, tree->n, &left_height) ||
		!is_valid_avl(tree->right, tree->n, max, &right_height))
		{
			return (0);
		}
		if (left_height != right_height)
		{
			return (0);
		}
		*height = left_height + 1;
	}
}

/**
 * binary_tree_is_avl - Returns true if the binary tree is AVL
 * @tree: The root of the binary tree
 * Return: true if the binary tree is AVL, false otherwise
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	return (is_valid_avl(tree, -1, INT_MAX, &height));
}
