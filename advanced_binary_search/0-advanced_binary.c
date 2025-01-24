#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the current array or subarray being searched
 * @array: Pointer to the first element of the array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursively searches for a value in a sorted array
 * @array: Pointer to the first element of the array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;
	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return ((int)mid);

	if (array[mid] >= value)
		return (recursive_search(array, left, mid, value));
	else
		return (recursive_search(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches the first occurrence of a value in a sorted array
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
