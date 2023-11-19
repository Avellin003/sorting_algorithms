#include "sort.h"

/**
 * selection_sort - sorts array in ascending order
 * @array: array of numbers
 * @size: checks the size of the number to compare
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			int temp = array[i];

			array[i] = array[min];
			array[min] = temp;
		}
		print_array(array, size);
	}
}
