#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: Pointer to first node
 * @b: Pointer to second node
 * @list: Pointer to head of list
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (!a || !b || !list)
		return;

	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;

	while (curr)
	{
		tmp = curr;
		curr = curr->next;

		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}
	}
}
