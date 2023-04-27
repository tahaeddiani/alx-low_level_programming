#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "lists.h"

/**
 * list_len - function that returns the number of elements(list_t)
 * @h: A pointer to the head node //zakaria elaroussi
 *
 * Return: The number of elements in the linked list.
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;
	int x = 0;

	for (x = 0 ; h != NULL ; x++)
{
	count++;
	h = h->next;
}

	return (count);
}
