#include "main.h"

/**
 * factorial - returns the factorial of the given number
 * @n: input a number
 * Return: factorial of a number
 */
int factorial(int n)
{
	if (n < 0)
	return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
