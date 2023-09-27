#include "main.h"

/**
 * zoct_print - print the number in octal begining with zero
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed
 */
int zoct_print(va_list arg, char *buf, unsigned int ind)
{
	int input, i, neg, count, f_digit;
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
	ind = buff_handler(buf, '0', ind);
	bin = malloc((32 + 1) * sizeof(char));
	bin = dtob(bin, input, neg, 32);
	oct = malloc((11 + 1) * sizeof(char));
	oct = oct_array(bin, oct);
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
	return (count + 1);
}

