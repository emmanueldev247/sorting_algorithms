#include "sort.h"

/**
 * selection_sort - selection sort algorithm in ascending order
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_ind;
	int temp, min;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		min_ind = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_ind = j;
			}
		}
		if (array[i] > min)
		{
			temp = array[min_ind];
			array[min_ind] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}

}
