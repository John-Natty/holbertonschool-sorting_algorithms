#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			listint_t *prev_node = tmp->prev;

			/* reconnect left side */
			prev_node->next = tmp->next;

			if (tmp->next != NULL)
				tmp->next->prev = prev_node;

			/* move tmp before prev_node */
			tmp->prev = prev_node->prev;
			tmp->next = prev_node;

			prev_node->prev = tmp;

			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			print_list(*list);
		}
	}
}
