#include "sort.h"

/**
 * selection_sort - sorts an array ascendingly using Selection sort algorithm
 * @array: to be sorted
 * @size: of array
 * Return: non
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int sort, temp, lowest, swap_num;

	for (i = 0; i < size; i++)
	{
		sort = 0;
		lowest = array[i];
		for (j = i; j < size; j++)
		{
			if (lowest > array[j])
			{
				lowest = array[j];
				swap_num = j;
				sort = 1;
			}
		}
		if (sort)
		{
			temp = array[i];
			array[i] = lowest;
			array[swap_num] = temp;
			print_array(array, size);
		}
	}
}
