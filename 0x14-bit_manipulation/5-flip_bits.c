#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to be flipped to get from one
 * number to another.
 * Created TAHA ED
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to be flipped to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int diff = n ^ m;
unsigned int count = 0;

while (diff > 0)
{
if ((diff & 1) == 1)
count++;
diff >>= 1;
}
return (count);
}
