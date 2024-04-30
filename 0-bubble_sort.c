#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: array to sort
 * @size: of the array
 * Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;
	int sorted;

	if (array && size > 1)
	{
		for (i = 0; i < size; i++)
		{
			sorted = 1;
			for (j = 0; j < size - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
					print_array(array, size);
					sorted = 0;
				}
			}
			if (sorted)
				break;
		}
	}
}
