#include "sort.h"
/**
 * swap - swap
 * @a: a
 * @b: b
*/
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
/**
 * partition - This function takes last element as pivot, places
 * the pivot element at its correct position in sorted array,
 * and places all smaller (smaller than pivot) to left of pivot
 * and all greater elements to right of pivot
 * @arr: array
 * @low: idx
 * @high: idx
 * @size: size
 * Return: index
*/
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1);
	int j;
	/*Index of smaller element*/

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	print_array(arr, size);
	return (i + 1);
}

/**
 * quicksort - The main function that implements QuickSort
 * @arr: array
 * @low: idx
 * @high: idx
 * @size: size
*/
void quicksort(int arr[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		/**
		 * pi is partitioning index, arr[p] is now
		 * at right place
		*/
		pi = partition(arr, low, high, size);
		quicksort(arr, low, pi - 1, size);
		quicksort(arr, pi + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: arr
 * @size: size
*/
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quicksort(array, 0, size - 1, size);
}
