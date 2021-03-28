#include "search.h"

/**
 * linear_skip- searches for a value in a sorted skip list of integers.
 * @list: pointer to the head of the skip list
 * @value: is the value to search for
 * Return: If value is not present in list or if head is NULL,
 * your function must return NULL
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{

	skiplist_t *head = list;
	skiplist_t *temp;

	if (!value || head == NULL)
	{
		return (NULL);
	}
}