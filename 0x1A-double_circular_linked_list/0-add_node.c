#include "list.h"

/**
 * add_node_begin - Add a new node to the beginning of
 * a double circular linked list.
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);

	if ((*list) == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		(*list) = new_node;
		return (new_node);
	}
	new_node->prev = (*list);
	new_node->next = (*list)->next;
	(*list)->next = new_node;
	new_node->next->prev = new_node;
	return (new_node);
}

/**
 * add_node_end - Add a new node to the end of a double circular linked list.
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = add_node_begin(list, str);

	if (new_node == NULL)
		return (NULL);
	(*list) = new_node;
	return (new_node);
}
