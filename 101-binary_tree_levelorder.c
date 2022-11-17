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
 * printLevel - C Function to print values at all levels of binary tree
 * @tree: pointer to tree/nodes whose values will be printed
 * @func: pointer to value to be printed
 * @level: level at which values will be printed
 * Return: printed values
 */
void printLevel(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printLevel(tree->left, func, level - 1);
		printLevel(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - prints data in level-order traversal
 * @tree: tree root
 * @func: pointer to a function
 * Return: no return
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, count;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree) + 1;
	for (count = 1; count <= height; count++)
		printLevel(tree, func, count);
}
