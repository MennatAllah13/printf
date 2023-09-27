#include "main.h"

/**
 * suint_print - prints a short unsigned integer
 * @arg: number to print
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of char printed.
 */
int suint_print(va_list arg, char *buf, unsigned int ind)
{
	unsigned short int in, temp, i, div;

	in = va_arg(arg, unsigned int);

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
