#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 *
 * @head: A pointer to the head node of the list.
 *
 * Description: The function frees each node in the list and sets
 * the head to NULL.
 * created by Taha Eddiani
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

if (head == NULL)
return;

while (*head != NULL)
{
current = *head;
*head = (*head)->next;
free(current);
}
*head = NULL;
}
