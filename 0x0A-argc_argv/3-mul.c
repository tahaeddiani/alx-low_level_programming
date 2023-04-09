#include <stdio.h>
#include <stdlib.h>
/**
 *
 * main - where the main code is.
 * @argc: vriable type intiger
 * @argv: variable type char.
 * Return: return 0 when success.
 */
int main(int argc, char *argv[])
{
	int i;
	int mul;
	if (argc > 1)
	for (i = 0; i < argc; i++)
{
		printf("%s\n",argv[i]);
		mul *= atoi(argv[i]);
	else
{
		printf("Error");
}
}
	return (0);
}
