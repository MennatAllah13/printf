#include "main.h"

/**
 * add_print - prints the address of input variable
 * @arg: input address.
 * @buf: buffer pointer.
 * @ind: index for buffer pointer
 * Return: number of chars printed.
 */
int add_print(va_list arg, char *buf, unsigned int ind)
{
	void *add;
	long int input;
	int i, count, f_digit, neg;
	char *hexa, *bin;
	char nill[] = "(nil)";

	add = (va_arg(arg, void *));
	if (add == NULL)
	{
		for (i = 0; nill[i]; i++)
			ind = buff_handler(buf, nill[i], ind);
		return (5);
	}
	input = (intptr_t)add;
	neg = 0;
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}
	bin = malloc(sizeof(char) * (64 + 1));
	bin = dtob(bin, input, neg, 64);
	hexa = malloc(sizeof(char) * (16 + 1));
	hexa = hex_array(bin, hexa, 0, 16);
	ind = buff_handler(buf, '0', ind);
	ind = buff_handler(buf, 'x', ind);
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
	return (count + 2);
}
