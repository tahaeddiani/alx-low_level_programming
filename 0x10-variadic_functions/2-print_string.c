#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 *  print_strings - function that prints strings //zakaria
 * @separator: is the string to be printed between numbers
 * @n: n is the number of integers passed
 * Return: nthing
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list strarg;

	va_start(strarg, n);

	for (i = 0; i < n; i++)
{
	char *s = va_arg(strarg, char*);

	if (s == NULL)
{
	printf("(nil)");
}
	else
{
	printf("%s", s);
}
	if (i < n - 1 && separator != NULL)
{
	printf("%s", separator);
}
}
	printf("\n");
	va_end(strarg);
}
