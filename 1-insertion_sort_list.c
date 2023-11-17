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
		listint_t *temp = current->next;
		listint_t *prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;

			print_list(*list);

			prev = current->prev;
		}
		current = temp;
	}
}
