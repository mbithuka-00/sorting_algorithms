#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The 1st int to swap.
 * @b: The 2nd integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts arrays of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of int.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t m, j;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		min = array + m;
		for (j = m + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + m) != min)
		{
			swap_ints(array + m, min);
			print_array(array, size);
		}
	}
}
