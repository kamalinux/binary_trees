#include "binary_trees.h"

/**
 * binary_tree_height - calls recursive_height to return the height
 * of a binary tree
 * @tree: tree root
 * Return: height of the tree or 0 if tree is NULL;
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;


	if (tree == NULL)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (0);
	height_left = binary_tree_height(tree->left);
	height_left++;
	height_right = binary_tree_height(tree->right);
	height_right++;
	if (height_left > height_right)
		return (height_left);
	else
		return (height_right);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if leaf, 0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (!(node->left) && !(node->right))
		return (1);
	return (0);
}

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
 * binary_tree_is_avl - checks if tree is AVL
 * @tree: tree root
 * Return: 1 if tree is a AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree && is_bst(tree, NULL, NULL) &&
		(binary_tree_height(tree->left) - binary_tree_height(tree->right) == 0))
	{
		return (1);
	}

	return (0);
}
