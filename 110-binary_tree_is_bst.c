#include "binary_trees.h"

/**
 * is_bst - recursively check subtrees (left data < right data)
 * @tree: root
 * @min: min value
 * @max: max value
 * Return: 1 if yes, 0 if not
 */
int is_bst(const binary_tree_t *tree,
	   const binary_tree_t *min,
	   const binary_tree_t *max)
{
	if (!tree)
		return (1);
	if (min && min->n >= tree->n)
		return (0);
	if (max && max->n <= tree->n)
		return (0);
	return (is_bst(tree->left, min, tree) &&
		is_bst(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - check if binary search tree (left data < right data)
 * @tree: tree root
 * Return: 1 if yes, 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, NULL, NULL));
}
