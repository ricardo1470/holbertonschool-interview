#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to head of list
 * @number: node to insert in list
 * Return: Always 0.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *node_tmp;

	new_node = malloc(sizeof(listint_t));

	if (new_node)
	{
		new_node->n = number;
		new_node->next = NULL;

		if (*head == NULL || (*head)->n >= new_node->n)
		{
			new_node->next = *head;
			*head = new_node;
		}
		else
		{
			node_tmp = *head;
			while (node_tmp->next && node_tmp->next->n < new_node->n)
			{
				node_tmp = node_tmp->next;
			}
			new_node->next = node_tmp->next;
			node_tmp->next = new_node;
		}
		return (new_node);
	}
	return (NULL);
}
