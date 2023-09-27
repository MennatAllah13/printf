#include "main.h"

/**
 * sint_print - prints a short integer
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of char printed.
 */
int sint_print(va_list arg, char *buf, unsigned int ind)
{
	short int input;
	unsigned short int in, temp, i, div, neg;

	input = va_arg(arg, int);
	neg = 0;
	if (input < 0)
	{
		in = input * -1;
		ind = buff_handler(buf, '-', ind);
		neg = 1;
	}
	else
	{
		in = input;
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
	return (i + neg);
}
