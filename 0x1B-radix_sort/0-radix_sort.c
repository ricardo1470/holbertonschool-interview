#include "sort.h"
/**
 * current_digit_sort - function that sorts an array of integers
 * in ascending order using the Radix sort algorithm
 * @array: will contain only numbers >= 0
 * @size: array's size
 * @tmp: temporal array
 * @exp: actual exponent digit
 * Return: expected to print the array each time you increase
 */
int current_digit_sort(int *array, ssize_t size, int *tmp, long exp)
{
	ssize_t i;
	int aux[10] = {0};

	for (i = 0; i < size; i++)
	{
		aux[(array[i] / exp) % 10]++, tmp[i] = 0;
	}
	for (i = 1; i < 10; i++)
	{
		aux[i] += aux[i - 1];
	}
	for (i = size - 1; i >= 0; i--)
	{
		tmp[--aux[(array[i] / exp) % 10]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}
	return (0);
}
/**
 * radix_sort - function that sorts an array of integers
 * in ascending order using the Radix sort algorithm
 * @array: will contain only numbers >= 0
 * @size: size of array
 * Return: expected to print the array each time you increase
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	long exp = 1;
	int *tmp, max = INT_MIN;

	if (!array || size < 2)
	{
		return;
	}

	tmp = malloc(sizeof(int *) * size);
	if (!tmp)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		max = array[i] > max ? array[i] : max;
	}

	while (max / exp > 0)
	{
		current_digit_sort(array, size, tmp, exp);
		print_array(array, size);
		exp *= 10;
	}
	free(tmp);
}
