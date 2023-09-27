#include "main.h"

/**
 * hex_print - prints a decimal in hexadecimal
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed
 */
int hex_print(va_list arg, char *buf, unsigned int ind)
{
	int input, i, neg, count, f_digit;
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
	bin = malloc((32 + 1) * sizeof(char));
	bin = dtob(bin, input, neg, 32);
	hexa = malloc((8 + 1) * sizeof(char));
	hexa = hex_array(bin, hexa, 0, 8);
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
 * upx_print - prints a decimal in hexadecimal
 * @arg: The character to print
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of char printed
 */
int upx_print(va_list arg, char *buf, unsigned int ind)
{
	int input, i, neg, count, f_digit;
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
	bin = malloc(sizeof(char) * (32 + 1));
	bin = dtob(bin, input, neg, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = hex_array(bin, hexa, 1, 8);
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
