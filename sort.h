#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
/*print_array.c*/
void print_array(const int *array, size_t size);
/*print_list.c*/
void print_list(const listint_t *list);
/*0-bubble_sort.c*/
void bubble_sort(int *array, size_t size);
/*1-insertion_sort_list.c*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
/*2-selection_sort.c*/
void selection_sort(int *array, size_t size);
/*3-quick_sort.c*/
void quick_sort(int *array, size_t size);
int partition(int array[], int lbindex, int ubindex, size_t size);
void lomuto_sort(int *array, int lbindex, int ubindex, size_t size);
#endif
