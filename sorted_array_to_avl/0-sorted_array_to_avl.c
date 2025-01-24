#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl_node - Creates a new AVL tree node.
 * @parent: Pointer to the parent node.
 * @n: Value to store in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
binary_tree_t *create_avl_node(binary_tree_t *parent, int n)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);
	node->n = n;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * sorted_array_to_avl_helper - Recursively builds an AVL tree.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 * @parent: Pointer to the parent node.
 *
 * Return: Pointer to the root of the subtree, or NULL on failure.
 */
avl_t *sorted_array_to_avl_helper(
		int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_avl_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = sorted_array_to_avl_helper(array, start, mid - 1, root);
	root->right = sorted_array_to_avl_helper(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @size: Size of the array.
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}
