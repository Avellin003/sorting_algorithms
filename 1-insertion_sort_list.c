#include "sort.h"

/**
 * insertion_sort_list - sorts using the insertion algorithm
 * @list: Ptr to the head of the doubly linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL)
		return;

	while (current != NULL)
	{
		listint_t *temp = current; /*before current->next*/
		listint_t *c_prev = current->prev;

		while (c_prev != NULL && c_prev->n > current->n)
		{
			current->next = c_prev->next;

			if (c_prev->next != NULL)
				c_prev->next->prev = current;

			c_prev->next = current;
			c_prev->prev = current->prev;

			if (current->prev != NULL)
				current->prev->next = c_prev;
			else
				*list = c_prev;

			current->prev = c_prev;

			print_list(*list);

			c_prev = current->prev;
		}
		current = temp;
	}
}
