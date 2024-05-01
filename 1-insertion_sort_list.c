#include "sort.h"
/**
 * swap_nodes - swapping
 *
*/
void swap_nodes(listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
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
	listint_t *h, *mov;

	if (list && *list && (*list)->next)
	{
		h = *list;
		mov = h;
		for (; mov->next; mov = mov->next)
		{
			if (mov->prev)
			{
				if (mov->prev->n > mov->n)
					swap_nodes(mov->prev, mov);
			}
			if (mov->n > mov->next->n)
				swap_nodes(mov, mov->next);

			print_list(h);
		}
	}

}