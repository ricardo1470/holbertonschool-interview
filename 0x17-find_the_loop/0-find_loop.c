#include "lists.h"
/**
 * find_listint_loop - function that finds the loop in a linked list.
 * @head: pointer to head link-list
 * Returns: The address of the node where the loop starts,
 * or NULL if there is no loop
 * Description: find the loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *i, *j;

	i = head;
	j = head;

	while (i != NULL && j != NULL && j->next != NULL && i->next != NULL)
	{
		i = i->next;
		j = j->next->next;
		if (i == j)
		{
			return (i);
		}
	}
	return (0);
}
