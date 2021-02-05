#include "lists.h"

/**
 * check_cycle - check the code for Holberton School students.
 *@list: list.
 * Return: Always 0.
 */
int check_cycle(listint_t *list)
{
	listint_t *i, *j;

	i = list;
	j = list;

	while (i != NULL && j != NULL && j->next != NULL && i->next != NULL)
	{
		i = i->next;
		j = j->next->next;
		if (i == j)
		{
			return (1);
		}
	}
	return (0);
}
