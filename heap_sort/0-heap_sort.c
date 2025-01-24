#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Ensures the max heap property for a subtree
 * @array: The array
 * @size: The size of the array
 * @n: The size of the heap
 * @i: The index of the root of the subtree
 */
void heapify(int *array, size_t size, size_t n, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, n, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, size, i - 1);

	for (i = size; i > 1; i--)
	{
		swap(&array[0], &array[i - 1]);
		print_array(array, size);
		heapify(array, size, i - 1, 0);
	}
}
