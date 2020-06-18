#include "sort.h"
/**
 * swap - Function that swaps two nodes in a doubly linked list
 * @head: address of pointer to head of doubly linked list
 * @a: address of 1st node to swap
 * @b: address of 2nd node to swap
 */
void swap(listint_t **head, listint_t *a, listint_t *b)
{
	listint_t *tmp = a->prev;

	if (a == *head)
	{
		a->next = b->next;
		a->prev = b;
		if (b->next)
			(b->next)->prev = a;
		b->next = a;
		b->prev = tmp;
		*head = b;
	}
	else
	{
		a->next = b->next;
		a->prev = b;
		if (b->next)
			b->next->prev = a;
		b->next = a;
		b->prev = tmp;
		tmp->next = b;
	}
}
/**
 * insertion_sort_list - sorts a linked list with insertion sort algorithm
 * @list: address of pointer to head of doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *start;

	if (list == NULL || (*list)->next)
		return;

	start = (*list)->next;
	while (start)
	{
		i = start;
		while (i && i->prev)
		{
			if (i->n < i->prev->n)
			{
				swap(list, i->prev, i);
				print_list(*list);
			}
			else
			{
				i = i->next;
			}
		}
		start = start->next;
	}
}
