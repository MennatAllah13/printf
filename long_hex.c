#include "main.h"

/**
 * lhex_print - prints a long decimal in hexadecimal
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed
 */
int lhex_print(va_list arg, char *buf, unsigned int ind)
{
	long int input, i, neg, count, f_digit;
	char *hexa, *bin;

	input = va_arg(arg, long int);
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

	bin = malloc((64 + 1) * sizeof(char));
	bin = dtob(bin, input, neg, 64);
	hexa = malloc((16 + 1) * sizeof(char));
	hexa = hex_array(bin, hexa, 0, 16);
	for (f_digit = i = count = 0; hexa[i]; i++)
	{
		if (f_digit == 0 && hexa[i] != '0')
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

/**
 * lhex2_print - prints a long decimal in hexadecimal.
 * @arg: The character to print
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed
 */
int lhex2_print(va_list arg, char *buf, unsigned int ind)
{
	long int input, i, neg, count, f_digit;
	char *hexa, *bin;

	input = va_arg(arg, long int);
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

	bin = malloc(sizeof(char) * (64 + 1));
	bin = dtob(bin, input, neg, 64);
	hexa = malloc(sizeof(char) * (16 + 1));
	hexa = hex_array(bin, hexa, 1, 16);
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
