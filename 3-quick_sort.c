#include "sort.h"

int partition(int array[], int lbindex, int ubindex, size_t size)
{
	int pivot = array[ubindex];
	int start = lbindex - 1, n;
	int temp;

	for (n = lbindex; n <= ubindex; n++)
	{
		if (array[n] <= pivot)
		{
			start++;
			if (start != n)
			{
				temp = array[n];
				array[n] = array[start];
				array[start] = temp;
				print_array(array, size);
			}
		}
	}

	return (start);

}
/**
 * lomuto_sort - sorting array in ascending order
 * @array: array of numbers
 * @lbindex: lower bound index
 * @ubindex: upper bound index
 * @size: size of numbers
 * Return: none
 */
void lomuto_sort(int *array, int lbindex, int ubindex, size_t size)
{
	int p;

	{
		if (lbindex < ubindex)
		{
			p  = partition(array, lbindex, ubindex, size);

			lomuto_sort(array, lbindex, p - 1, size);
			lomuto_sort(array, p + 1, ubindex, size);
		}
	}
}
/**
 * quick_sort - quick sort algorithm
 * @array: array of numbers
 * @size: size of numbers
 * Return: none
 */
void quick_sort(int *array, size_t size)
{
	lomuto_sort(array, 0, size - 1, size);
}

