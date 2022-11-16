#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: tree root
 * Return: number of leaves in a the tree or 0 if tree is NULL;
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t right;
	size_t leaves;
	size_t left;

	if (tree == NULL)
		return (0);

	if (!(tree->right) && !(tree->left))
		return (1);

	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	leaves = right + left;
	return (leaves);
}
