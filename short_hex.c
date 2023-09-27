#include "main.h"

/**
 * shex_print - prints a short decimal in hexadecimal
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of char printed
 */
int shex_print(va_list arg, char *buf, unsigned int ind)
{
	short int input, i, neg, count, f_digit;
	char *hexa, *bin;

	input = va_arg(arg, int);
	neg = 0;
	if (input == 0)
	{
		ind = buff_handler(buf, '0', ind);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}

	bin = malloc(sizeof(char) * (16 + 1));
	bin = dtob(bin, input, neg, 16);
	hexa = malloc(sizeof(char) * (4 + 1));
	hexa = hex_array(bin, hexa, 0, 4);
	for (f_digit = i = count = 0; hexa[i]; i++)
	{
		if (hexa[i] != '0' && f_digit == 0)
			f_digit = 1;
		if (f_digit)
		{
			ind = buff_handler(buf, hexa[i], ind);
			count++;
		}
	}
	free(bin);
	free(hexa);
	return (count);
}
