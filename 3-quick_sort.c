#include "sort.h"

int partition(int array[], int lbindex, int ubindex)
{
	int pivot = array[lbindex];
	int start = lbindex;
	int end = ubindex;
	int temp;

	while (start < end)
	{
		while (array[start] <= pivot)
		{
			start++;
		}
		while (array[end] > pivot)
		{
			end--;
		}
		if (start < end)
		{
			/*swap(array[start], array[end])*/
			temp = array[end];
			array[end] = array[start];
			array[start] = temp;
		}
	}
	temp = array[end];
	array[end] = array[lbindex];
	array[lbindex] = temp;

	return end;
}
/**
 * quick_sort - sorting array in ascending order
 * @array: array of numbers
 * @size: size of numbers
 * Return: none
 */
void quick_sort(int *array, size_t size)
{
	size_t lbindex, ubindex;

	{
		if (lbindex < ubindex)
		{
			size  = partition(array, lbindex, ubindex);

			quick_sort(array, lbindex, size - 1);
			quick_sort(array, size + 1, ubindex);
		}
	}
}


