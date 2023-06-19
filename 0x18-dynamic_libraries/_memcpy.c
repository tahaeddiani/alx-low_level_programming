#include "main.h"
/**
 * _memcpy - function copies the memory area
 *
 * @dest: buffer where we will copy
 * @src: what we are to copy.
 * @n: n bytes of @src.
 *
 * Return: Always 0.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
