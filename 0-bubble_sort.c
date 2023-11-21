#include "sort.h"
/**
 * bubble_sort - arranges in ascending with bubble algorithm
 * @array: pointer to the array of numbers
 * @size: used to check whether we have atleast 2 num to compare
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t swapped;

	/*if we don't have atleast 2 members to compare do nothing*/
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/*sets up the swapped to 0 and begins by taking first member*/
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			/*here the second member is choosed and the cmp starts*/
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped++;
				print_array(array, size);
			}
		}
		/*if the swapped is 0 the cmp is done and so stop*/
		if (swapped == 0)
			break;
	}
}
