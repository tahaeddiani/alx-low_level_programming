#include <stdio.h>
/**
 * main - main function where the main code is
 *
 *@argc: an int variable
 *@argv: variable type char
 *Return: return when success
 */

int main(int argc, char **argv)
{
	int loop;

	for (loop = 0; loop < argc; loop++)
{
		printf("%s", argv[loop]);
}
	printf("\n");
	return (0);
}
