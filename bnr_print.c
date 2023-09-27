#include "main.h"

/**
 * bnr_print - prints decimal in binary.
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed.
 */
int bnr_print(va_list arg, char *buf, unsigned int ind)
{
	int input, count, i, first, neg;
	char *bin;

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
	first = 0;
	for (count = i = 0; bin[i]; i++)
	{
		if (first == 0 && bin[i] == '1')
			first = 1;
		if (first == 1)
		{
			ind = buff_handler(buf, bin[i], ind);
			count++;
		}
	}
	free(bin);
	return (count);
}
