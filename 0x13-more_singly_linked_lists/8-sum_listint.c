#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n)
 * @head: pointer to head node
 * created by Taha Eddiani
 * Return: sum of all the data (n) or 0 if list is empty
 */
int sum_listint(listint_t *head)
{
int sum = 0;

while (head)
{
sum += head->n;
head = head->next;
}

return (sum);
}
