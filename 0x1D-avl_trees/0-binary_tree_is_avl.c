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
		return true;
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return true;
	}
	else if (tree->left == NULL || tree->right == NULL)
	{
		return false;
	}
	else if (tree->left->n > tree->right->n)
	{
		return false;
	}
	else if (tree->left->n == tree->right->n)
	{
		return is_valid_avl(tree->left, min, tree->n, height) &&
		is_valid_avl(tree->right, tree->n, max, height);
	}
	else
	{
		int left_height = 0, right_height = 0;
	}
	return is_valid_avl(tree->left, min, tree->n, height) &&
	is_valid_avl(tree->right, tree->n, max, height);
}


/**
 * binary_tree_is_avl - Returns true if the binary tree is AVL
 * @tree: The root of the binary tree
 * Return: true if the binary tree is AVL, false otherwise
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
	{
		return true;
	}
	else if (tree->left == NULL && tree->right == NULL)
	{
		return true;
	}

	return is_valid_avl(tree, -1, tree->n, &height);
}
