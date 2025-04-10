#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 * Return: true or false
 */
int swap_ints(int *a, int *b)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		return (1); /* Swap occurred */
	}
	return (0); /* No swap */
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: Index of pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, swapped;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swapped = swap_ints(&array[i], &array[j]);
			if (swapped)
				print_array(array, size);
		}
	}
	swapped = swap_ints(&array[i + 1], &array[high]);
	if (swapped)
		print_array(array, size);

	return (i + 1);
}

/**
 * quicksort_rec - Recursive quicksort helper
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the array
 */
void quicksort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort_rec(array, low, pi - 1, size);
		quicksort_rec(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick Sort
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_rec(array, 0, size - 1, size);
}
