#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: tree root
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int right, left;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	right = binary_tree_is_full(tree->right);
	left = binary_tree_is_full(tree->left);

	if (right == 0 || left == 0)
		return (0);

	return (1);
}
