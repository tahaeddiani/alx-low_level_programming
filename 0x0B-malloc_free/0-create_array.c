#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *create_array - function that creates an array of chars.
 * @size: the size of the memory to print
 * @c:  initializes  char
 *
 * Return: 0 or ptr.
 */

char *create_array(unsigned int size, char c)
	{

	char *ptr = (char *) malloc(size * sizeof(char));

	if (size == 0 || ptr == NULL)

	{
	return (NULL);
	}

	else

	{
	unsigned int i;
	for (i = 0; i < size ; i++)
	{
	*(ptr + i) = c;
	}
	return (ptr);
	}
	}
