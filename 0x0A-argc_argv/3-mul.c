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
	int x, y;
	int mul;
if (argc != 3)
{
	x = atoi(argv[1];
	y = atoi(argv[2];
	mul = (x)*(y);
	printf("%d\n", mul);
	return (0);
}
	else
{
	printf("Error");
	return (1);
}
	
}
