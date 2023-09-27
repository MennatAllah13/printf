#include "main.h"

/**
 * luint_print - prints a long unsigned integer
 * @arg: number to print
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed.
 */
int luint_print(va_list arg, char *buf, unsigned int ind)
{
	unsigned long int in, temp, i, div;

	in = va_arg(arg, unsigned long int);
	temp = in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ind = buff_handler(buf, ((in / div) % 10) + '0', ind);
	}
	return (i);
}
