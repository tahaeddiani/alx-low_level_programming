#include "main.h"
/**
* main
* print_alphabet - print all alphabet in lowercase
* description: It prints the alphabet in lowercase fallowed by a new line
* return 0: succes
* 
*/


	void print_alphabet(void)
	{
		char letter;


		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);


		_putchar('\n');
	}

