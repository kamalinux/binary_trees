#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: tree root
 * Return: pointer to the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	if (tree->right)
	{
		tree->parent = tree->right;
		tree->right = (tree->parent)->left;
		if (tree->right)
			(tree->right)->parent = tree;
		(tree->parent)->left = tree;
		(tree->parent)->parent = NULL;
		return (tree->parent);
	}

	return (tree);
}
