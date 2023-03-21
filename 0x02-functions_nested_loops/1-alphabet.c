#include "main.h"
/**
 *main - Entry point
 *
 *Description: Using _putchar
 *
 *Return: Always 0 (Success)
 */
void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
		_putchar(i);
	_putchar('\n');
}
