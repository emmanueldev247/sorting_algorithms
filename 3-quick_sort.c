#include "sort.h"

/**
 * quick_sort - quick sort algorithm in ascending order
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);

}

/**
 * quick_sort_helper - recursively sort the array
 * @array: array to sort
 * @low: lower index of the partition
 * @high: higher index of the partition
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}


/**
 * partition - Lomuto partition scheme
 * @array: array to partition
 * @low: lower index of the partition
 * @high: higher index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j  = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

				print_array(array, size);
			}
		}
	}

	if (array[i + 1] > pivot)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;

		print_array(array, size);
	}
	return (i + 1);
}
