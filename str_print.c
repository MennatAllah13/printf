#include "main.h"

/**
 * str_print - writes the string to stdout
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: On success 1.
 */
int str_print(va_list arg, char *buf, unsigned int ind)
{
	char *str;
	char nill[] = "(null)";
	unsigned int i;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ind = buff_handler(buf, nill[i], ind);
		return (6);
	}
	for (i = 0; str[i]; i++)
		ind = buff_handler(buf, str[i], ind);
	return (i);
}
