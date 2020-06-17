#include "sort.h"
/**
 * swap - Function that swaps two values when a condition is validated.
 *
 * @a: First value to swap
 * @b: Second value to swap
 *
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Function that takes last element as pivot, places
 * the pivot element at its correct position in sorted array, and
 * places all smaller (smaller than pivot) to left of pivot and all
 * greater elements to right of pivot.
 *
 * @arr: The array to be sorted
 * @low: First position of the array
 * @high: Last position of the array
 *
 * Return: a int data that indicates the pivot position.
 */
 int partition(int *arr, int low, int high)
{
	int i;
	int j;
	int pivot; 
	pivot = arr[high];
	
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array(arr, (size_t)high);	
		}
	}
	swap(&arr[i + 1], &arr[high]);
	print_array(arr, (size_t)high);
	return (i + 1);
}

/**
 * quicksrt - Function that sorts an array of integers in ascending order
 * using Quick Sort algorithm
 *
 * @arr: The array to be sorted
 * @low: First position of the array
 * @high: Last position of the array
 */
void quicksrt(int *arr, int low, int high)
{
	int piv;
	
	if (low < high)
	{		
		piv = partition(arr, low, high);		
		quicksrt(arr, low, piv - 1);
		quicksrt(arr, piv + 1, high);
	}
}

/**
 * quick_sort - Function that sorts an array of integers in ascending order
 * using Quick Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = (int)size;	
	quicksrt(array, low, high);
}
