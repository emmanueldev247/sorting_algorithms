#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm in ascending order
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, no_sort;

	for (i = 0; i < size - 1; i++)
	{
		no_sort = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				no_sort = 1;
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
		if (!no_sort)
			return;
	}
}
