#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
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

	return (is_complete(tree, 0, binary_tree_size(tree)));
}

/**
 * check_parent - checks if parent has a greater value than its childs
 * @tree: pointer to the node
 * Return: 1 if parent has a greater value, 0 otherwise
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - checks if an input tree is a Max Binary Heap
 * @tree: pointer to the root of the tree
 * Return: 1 if tree is a Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
