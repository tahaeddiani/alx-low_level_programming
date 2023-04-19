#include <stdio.h>
#include "function_pointers.h"
#include <stddef.h>


/**
 * print_name -function prints a name as is
 * @name: name of the person
 * @f: printing function pointer
 * Return: Nothing.
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	{
	return;
	}
	f(name);
}
