#include "sort.h"

/**
 * merge_subarr - Merge two subarrays into a single sorted subarray.
 * @subarr: The original array containing two sorted subarrays.
 * @buff: A buffer to store the sorted subarray.
 * @front: The starting index of the first subarray.
 * @mid: The ending index of the first subarray and the starting index of the second subarray.
 * @back: The ending index of the second subarray.
 *
 * Description:
 * This function takes two sorted subarrays within the 'subarr' array and merges them into
 * a single sorted subarray using the 'buff' buffer. It then copies the sorted subarray
 * back to the 'subarr' array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
    size_t m, n, k = 0;

    printf("Merging...\n[left]: ");
    print_array(subarr + front, mid - front);

    printf("[right]: ");
    print_array(subarr + mid, back - mid);

    for (m = front, n = mid; m < mid && n < back; k++)
        buff[k] = (subarr[m] < subarr[n]) ? subarr[m++] : subarr[n++];
    for (; m < mid; m++)
        buff[k++] = subarr[m];
    for (; n < back; n++)
        buff[k++] = subarr[n];
    for (m = front, k = 0; m < back; m++)
        subarr[m] = buff[k++];

    printf("[Done]: ");
    print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Recursively apply the merge sort algorithm to a subarray.
 * @subarr: The original array to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The starting index of the subarray.
 * @back: The ending index of the subarray.
 *
 * Description:
 * This function recursively applies the merge sort algorithm to sort a subarray
 * of the original 'subarr' array using the 'buff' buffer.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
    size_t mid;

    if (back - front > 1)
    {
        mid = front + (back - front) / 2;
        merge_sort_recursive(subarr, buff, front, mid);
        merge_sort_recursive(subarr, buff, mid, back);
        merge_subarr(subarr, buff, front, mid, back);
    }
}

/**
 * merge_sort - Sort an array of integers in ascending order using merge sort.
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * Description:
 * This function implements the top-down merge sort algorithm to sort an array of
 * integers in ascending order.
 */
void merge_sort(int *array, size_t size)
{
    int *buff;

    if (array == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    merge_sort_recursive(array, buff, 0, size);

    free(buff);
}

