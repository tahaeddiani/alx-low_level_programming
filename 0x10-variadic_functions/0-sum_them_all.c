#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - function that returns the sum of all its parameters.
 * @n: first counter unsigned int
 * Return: Sum
 */

int sum_them_all(const unsigned int n, ...)
{
va_list argscount;
int sum = 0;
unsigned int x;
if (n == 0)
{
	return (0);
}

	va_start(argscount, n);
	for (x = 0; x < n ; x++)
{
	sum += va_arg(argscount, int);
}
	va_end(argscount);

	return (sum);
}
