#include "sort.h"

/**
 * swap_ints - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array of integers
 * @low: Start index
 * @high: End index
 * @size: Size of array (for print_array)
 * Return: Final pivot position
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}
	swap_ints(&array[i], &array[high]);
	print_array(array, size);
	return (i);
}

/**
 * quicksort_rec - Recursive quicksort
 * @array: Array of integers
 * @low: Start index
 * @high: End index
 * @size: Size of array (for print_array)
 */
void quicksort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quicksort_rec(array, low, pivot_index - 1, size);
		quicksort_rec(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Main quick sort function
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_rec(array, 0, size - 1, size);
}
