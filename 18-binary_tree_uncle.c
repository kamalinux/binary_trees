#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a node
 * @node: node
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);
	else
		return (NULL);
}

/**
 * binary_tree_uncle - find the uncle of a node
 * @node: node
 * Return: pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !((node->parent)->parent))
		return (NULL);

	return (binary_tree_sibling(node->parent));
}