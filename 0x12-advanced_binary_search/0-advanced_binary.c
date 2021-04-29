#include "search_algos.h"

/**
 * advanced_binary - function that searches for a value in a sorted array of integers.
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * Return - Always 0
 **/
int advanced_binary(int *array, size_t size, int value)
{
	int left = 0;
	int i;
	int right = size - 1;
	int mid;

    if (!value || array == NULL)
    {
        return (-1);
    }

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left ; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
			{
				printf(", ");
			}
			else
			{
				printf("\n");
			}
		}
		mid = ((left + right) / 2);

		if (array[mid] == value)
		{
			return (mid);
		}
		else if (array[mid] < value)
		{
			left = mid + 1;
		}
		else if (array[mid] > value)
		{
			right = mid - 1;
		}
	}
	return (-1);
}