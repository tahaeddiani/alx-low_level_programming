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
	int mul = 1;
if (argc > 1)
{
	for (i = 1; i < argc; i++)
{
		printf("%s\n", argv[i]);
	
mul *= atoi(argv[i]);
}
	printf("%d\n", mul);
}
	else
{
	printf("Error");
	return (1);
}
	return (0);
}
