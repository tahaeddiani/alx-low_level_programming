#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - function that executes a function given as a parameter
 * @array: array type int
 * @size: variable type int
 * @action: intiger element
 * Return: Nothing.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
size_t i;
if (array == 0 || action == 0)
return;

for (i = 0; i < size; i++)
{
action(array[i]);
}
}
