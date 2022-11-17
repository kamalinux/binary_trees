#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * Return: pointer to the root node of the BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t idx;
	bst_t *root = NULL;

	if (!array)
		return (NULL);

	for (idx = 0; idx < size; idx++)
		bst_insert(&root, array[idx]);

	return (root);
}
