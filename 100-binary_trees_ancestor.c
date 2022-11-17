#include "binary_trees.h"

/**
 * binary_tree_depth - calls recursive_depth to return the depth
 * of a node in a binary tree
 * @tree: tree root
 * Return: depth of the tree or 0 if tree is NULL;
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree && (tree->parent))
		return (1 + binary_tree_depth(tree->parent));

	return (0);
}

/**
 * binary_tree_uncle - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return (first->parent);

	left = binary_trees_ancestor(first->parent, second);
	right = binary_trees_ancestor(second->parent, first);

	if (binary_tree_depth(first) > binary_tree_depth(second))
		return (left);
	else if (binary_tree_depth(second) > binary_tree_depth(first))
		return (right);
	return (binary_trees_ancestor(first->parent, second->parent));
}
