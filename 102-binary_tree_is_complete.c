#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: tree root
 * Return: number of parent nodes in a the tree or 0 if tree is NULL;
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t nodes_right, nodes_left;

	if (tree == NULL)
		return (0);

	if (tree->right || tree->left)
	{
		nodes_left = binary_tree_nodes(tree->left) + 1;
		nodes_right = binary_tree_nodes(tree->right) + 1;
		return (nodes_right + nodes_left - 1);
	}
	return (0);
}

/**
 * is_complete - is binary tree complete using index & num nodes
 * @tree: root node
 * @index: index of node
 * @nodes: num of nodes
 * Return: 0 or 1
 */
int is_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
		is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - C function to check if binary tree is complete
 * @tree: pointer to node of tree to check
 * Return: 1 if complete or 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete(tree, 0, binary_tree_nodes(tree)));
}
