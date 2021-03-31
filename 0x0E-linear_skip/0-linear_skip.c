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
	skiplist_t *temp = NULL;
	int skip = 1;
	char *text1 = "Value checked at index [%lu] = [%d]\n";
	char *text2 = "Value found between indexes [%lu] and [%lu]\n";

	while (head)
	{
		if (head->express && skip)
		{	printf(text1, head->express->index, head->express->n);
			if (head->express->n < value)
			{
				head = head->express;
				continue;
			}
			printf(text2, head->index, head->express->index);
			skip = 0;
		}
		else if (skip == 1)
		{	temp = head;
			while (temp->next)
				temp =	temp->next;
			printf(text2, head->index, temp->index);
			skip = 0;
		}
		printf(text1, head->index, head->n);
		if (head->n == value)
		{	return (head);
		}
		else if (head->next)
		{
			if (head->next->n <= value)
			{
				head = head->next;
				continue;
			}
		}
		head = head->express;
	}
	return (NULL);
}
