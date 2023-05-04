#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 *
 * @n: The number to get the bit from.
 * @index: The index of the bit to get, starting from 0.
 *
 * Return: The value of the bit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
/* Check if index is out of bounds */
if (index >= sizeof(unsigned long int) * 8)
return (-1);

return ((n >> index) & 1);
}
