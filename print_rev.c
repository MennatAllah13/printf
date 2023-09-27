#include "main.h"

/**
 * rev_print - writes the str in reverse
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: number of chars printed.
 */
int rev_print(va_list arg, char *buf, unsigned int ind)
{
	char nill[] = "(llun)";
	char *str;
	int j = 0;
	unsigned int i;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ind = buff_handler(buf, nill[i], ind);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		ind = buff_handler(buf, str[j], ind);
	}
	return (i);
}
