#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *
 * main - the main function
 * @c: type charater
 * @size: type int
 * Return: it return 0 if success
 */
char *create_array(unsigned int size, char c)
{

char *ptr = (char *) malloc(size * sizeof(char));
unsigned int i;
for (i = 0; i < size ; i++)
{
*(ptr + i) = c;
}

if (size == 0 || ptr == NULL)

{
return (NULL);
}

else
{
return (ptr);
}
}
