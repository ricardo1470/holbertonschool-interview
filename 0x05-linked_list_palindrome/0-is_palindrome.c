#include "lists.h"

/**
 * list_length - Get the length of a linked list
 * @head: pointer to head linkedlist
 * Return: lenght
 */

int list_length(listint_t **head)
{
	int i;
	listint_t *current = *head;

	for (i = 0; current != NULL; i++)
		current = current->next;
	return (i);
}

/**
 * reversed - Function to reverse the linked list Note that this
 * function may change the head
 * @head: pointer to head linkedlist
 * Return: Address of the new element
 */

listint_t *reversed(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return (*head);
}

/**
 * is_palindrome - Function to check if given linked list is
 * palindrome or not
 * @head: pointer to head linkedlist
 * Description: function that checks if a singly linked list is a palindrome.
 * Return - 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int length = list_length(head);
	int half_length = length / 2;
	int i, if_palindrome = 1;
	listint_t *reversed_head;
	listint_t *current = *head;
	listint_t *current_reversed;

	reversed_head = *head;
	for (i = 0; i < half_length; i++)
		reversed_head = reversed_head->next;
	if (length % 2 != 0)
		reversed_head = reversed_head->next;
	reversed_head = reversed(&reversed_head);
	current_reversed = reversed_head;
	current = *head;
	while (current_reversed != NULL)
	{
		if (current_reversed->n != current->n)
			if_palindrome = 0;
		current_reversed = current_reversed->next;
		current = current->next;
	}
	return (if_palindrome);
}
