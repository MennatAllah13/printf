#include "main.h"

/**
 * usr_print - prints a string and values of
 * non-printed chars
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed
 */
int usr_print(va_list arg, char *buf, unsigned int ind)
{
	unsigned char *str;
	char *hexa, *bin;
	unsigned int i, sum, op;

	str = va_arg(arg, unsigned char *);
	bin = malloc((32 + 1) * sizeof(char));
	hexa = malloc((8 + 1) * sizeof(char));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ind = buff_handler(buf, '\\', ind);
			ind = buff_handler(buf, 'x', ind);
			op = str[i];
			bin = dtob(bin, op, 0, 32);
			hexa = hex_array(bin, hexa, 1, 8);
			ind = buff_handler(buf, hexa[6], ind);
			ind = buff_handler(buf, hexa[7], ind);
			sum += 3;
		}
		else
			ind = buff_handler(buf, str[i], ind);
	}
	free(bin);
	free(hexa);
	return (i + sum);
}
