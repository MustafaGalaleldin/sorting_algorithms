#include "sort.h"
/**
 * swap_nodes - swapping
 * @node1: 1st
 * @node2: 2nd
 * @head: h pt
*/

void swap_nodes(listint_t *node1, listint_t *node2, listint_t **head)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*head = node2;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linled list
 * Return: NON
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *mov;

	if (list && *list && (*list)->next)
	{
		mov = *list;
		for (; (mov && mov->next); mov = mov->next)
		{
			if (mov->n > mov->next->n)
			{
				swap_nodes(mov, mov->next, list);
				print_list(*list);
				temp = mov->prev;
			}
			else
				temp = mov;
			while (1)
			{
				if (temp && temp->prev)
				{
					if (temp->prev->n > temp->n)
					{
						swap_nodes(temp->prev, temp, list);
						print_list(*list);
						continue;
					}
					else
						break;
				}
				break;
			}
		}
	}
}
