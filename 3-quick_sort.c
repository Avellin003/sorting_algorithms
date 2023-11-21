#include "sort.h"

void sorter(int *array, int start_memeber, int end_member, int size);
int dissol(int *array, int start_member, int end_member, int size);
void swapper(int *array, int *ptr_1, int *ptr_2, int size);
/**
 * quick_sort - performs sorting algorithm
 * @array: pointer to the members to sort
 * @size: number of the memebers to sort
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sorter(array, 0, size - 1, size);
}
/**
 * sorter - the sorter function
 * @array: pointer to the members to sort
 * @start_member: the first member
 * @end_member: the last member
 * @size: number of members
 * Return void
 */
void sorter(int *array, int start_member, int end_member, int size)
{
	int p;

	if (start_member < end_member)
	{
		p = dissol(array, start_member, end_member, size);
		sorter(array, start_member, p - 1, size);
		sorter(array, p + 1, end_member, size);
	}
}
/**
 * dissol - dissolutes the members
 * @array: pointer to the list of members
 * @start_member: start member of the list
 * @size: number of members
 * @end_member: end member of the list
 * Return: p which is the dissolution index
 */
int dissol(int *array, int start_member, int end_member, int size)
{
	int p, i, turning_pt;

	turning_pt = array[end_member];
	p = start_member;
	for (i = start_member; i < end_member; i++)
	{
		if (array[i] <= turning_pt)
		{
			swapper(array, &array[i], &array[p], size);
			p++;
		}
	}
	swapper(array, &array[p], &array[end_member], size);
	return (p);
}
/**
 * swapper - interchanges two members
 * @ptr_1: pointer to first member
 * @size: numbers of members
 * @array: pointer to the array of pointer
 * @ptr_2: pointer to second member
 * Return: void
 */
void swapper(int *array, int *ptr_1, int *ptr_2, int size)
{
	int tmp;

	tmp = (*ptr_1);
	*ptr_1 = *ptr_2;
	*ptr_2 = tmp;
	if (*ptr_2 != *ptr_1)
		print_array(array, size);
}
