#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *
 * main - the main function
 *
 * Return: it return 0 if success
 */

char *create_array(unsigned int size, char c)
{

char *ptr;
*ptr = (char *) malloc (size * sizeof(char) + 1);
*ptr = c;

if (size == 0 || ptr == NULL)

{
return NULL;
}

else
{
return (ptr);
}

}
