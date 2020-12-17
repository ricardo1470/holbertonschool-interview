#include "lists.h"

/**
 * insert_node - insert node
 * @head: pointer to head of list
 * @number: node to insert in list
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *node_tmp;

	node_tmp = malloc(sizeof(listint_t));

	if (node_tmp)
	{
		if (node_tmp == NULL)
		{
			return (NULL);
		}

		node_tmp->n = number;
		node_tmp->next = NULL;

		if (*head == NULL || (*head)->n >= node_tmp->n)
		{
			node_tmp->next = *head;
			*head = node_tmp;
		}
		else
		{
			new_node = *head;
			while (new_node->next && new_node->next->n < node_tmp->n)
			{
				new_node = new_node->next;
			}
			new_node->next = node_tmp->next;
			new_node->next = node_tmp;
		}
		return (node_tmp);
	}
	return (NULL);
}
