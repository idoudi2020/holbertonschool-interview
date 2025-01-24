#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * last_node - Finds the last node of a binary tree
 * @root: Pointer to the root node of the tree
 * @height: Current height to traverse to the last node
 *
 * Return: Pointer to the last node
 */
heap_t *last_node(heap_t *root, size_t height)
{
	if (height == 1)
		return (root);

	if (tree_height(root->right) == height - 1)
		return (last_node(root->right, height - 1));
	return (last_node(root->left, height - 1));
}

/**
 * swap_and_heapify - Heapifies down a binary heap
 * @node: Pointer to the root node
 */
void swap_and_heapify(heap_t *node)
{
	heap_t *largest;
	int temp;

	if (!node)
		return;

	largest = node;

	if (node->left && node->left->n > largest->n)
		largest = node->left;
	if (node->right && node->right->n > largest->n)
		largest = node->right;

	if (largest != node)
	{
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;
		swap_and_heapify(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = last_node(*root, tree_height(*root));

	(*root)->n = last->n;

	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;

	free(last);

	swap_and_heapify(*root);

	return (value);
}
