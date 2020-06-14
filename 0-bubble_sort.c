#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers in ascending order
 * using Bubble Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp = 0;
	bool swp;

	do {
		swp = false;
		for (i = 0; i <= size - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				print_array(array, size);
				swp = true;
			}
		}

	} while (swp == true);
}
