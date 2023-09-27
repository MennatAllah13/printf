#include "main.h"

/**
 * pint_print - print integer with plus symbol
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed
 */
int pint_print(va_list arg, char *buf, unsigned int ind)
{
	int input;
	unsigned int in, temp, i, div;

	input = va_arg(arg, int);
	if (input < 0)
	{
		in = input * -1;
		ind = buff_handler(buf, '-', ind);
	}
	else
	{
		in = input;
		ind = buff_handler(buf, '+', ind);
	}
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
	return (i + 1);
}

