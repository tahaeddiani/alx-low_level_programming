#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 *  print_numbers - function that prints numbers
 * @separator: is the string to be printed between numbers
 * @n: n is the number of integers passed
 * Return: nthing
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
unsigned int x = 0;
va_list  argsc;

va_start(argsc, n);

for (x = 0; x < n ; x++)
{
printf("%d", va_arg(argsc, int));
if (separator == NULL)
{

}
else if (x < n - 1)
{
printf("%s", separator);
}
}
printf("\n");
va_end(argsc);
}
