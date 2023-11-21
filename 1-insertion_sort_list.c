#include "sort.h"
/**
 * insertion_sort_list - sorts using the insertion algorithm
 * @list: Ptr to the head of the doubly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *now;
	listint_t *previous;
	listint_t *inlocation;

	/*check wether the list exists and have a location*/
	if (list == NULL || *list == NULL)
		return;
	now = (*list)->next;
	/*lets set the now pointer to second member in the list*/

	while (now != NULL)
	{
		inlocation = now;
		previous = now->prev;

		while (previous != NULL && previous->n > now->n)
		{
			/*interchange basing on the greatest*/
			if (now->next != NULL)
				now->next->prev = previous;

			previous->next = now->next;
			now->prev = previous->prev;
			now->prev = now;

			if (now->prev != NULL)
				now->prev->next = now;
			else
				*list = now;

			now->next = previous;

			print_list(*list);

			previous = now->prev;
		}
		now = inlocation->next;
	}
}
