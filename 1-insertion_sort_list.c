#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm in ascending order
 * @list: list to sort
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *key;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	key = (*list)->next;

	while (key)
	{
		while (key->prev && key->n < key->prev->n)
		{
			temp = key->prev;
			temp->next = key->next;
			if (temp->next)
				temp->next->prev = temp;
			key->prev = temp->prev;
			if (key->prev)
				key->prev->next = key;
			key->next = temp;
			temp->prev = key;
			if (temp == *list)
				*list = key;
			else if (!key->prev)
				*list = temp;
			temp = key->prev;
			print_list(*list);
		}
		key = key->next;
	}
}
