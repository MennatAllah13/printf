#include "main.h"

/**
 * loct_print - prints long decimal number in octal
 * @arg: input number
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed.
 */
int loct_print(va_list arg, char *buf, unsigned int ind)
{
	long int input, i, neg, count, f_digit;
	char *oct, *bin;

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
	oct = malloc(sizeof(char) * (22 + 1));
	oct = l_oct(bin, oct);
	for (f_digit = i = count = 0; oct[i]; i++)
	{
		if (oct[i] != '0' && f_digit == 0)
			f_digit = 1;
		if (f_digit)
		{
			ind = buff_handler(buf, oct[i], ind);
			count++;
		}
	}
	free(bin);
	free(oct);
	return (count);
}

/**
 * loct2_print - prints long decimal number in octal
 * @arg: input number
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of char printed.
 */
int loct2_print(va_list arg, char *buf, unsigned int ind)
{
	short int input, i, neg, count, f_digit;
	char *oct, *bin;

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

	bin = malloc((16 + 1) * sizeof(char));
	bin = dtob(bin, input, neg, 16);
	oct = malloc((6 + 1) * sizeof(char));
	oct = s_oct(bin, oct);
	for (f_digit = i = count = 0; oct[i]; i++)
	{
		if (f_digit == 0 && oct[i] != '0')
			f_digit = 1;
		if (f_digit)
		{
			ind = buff_handler(buf, oct[i], ind);
			count++;
		}
	}
	free(bin);
	free(oct);
	return (count);
}
