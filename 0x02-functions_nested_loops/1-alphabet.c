#include "main.h"
/**
 *main - Entry point
 *
 *print_alphabet - prints the lowercase alphabet followed by a newline character
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
