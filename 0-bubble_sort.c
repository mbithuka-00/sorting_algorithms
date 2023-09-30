#include "sort.h"

/**
 * swap_ints - Swap two int in an array.
 * @a: The 1st int to swap.
 * @b: The snd int to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an arrays in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of  array.
 *
 * Description: Prints the array after every swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t m, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (m = 0; m < len - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				swap_ints(array + m, array + m + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
