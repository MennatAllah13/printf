#include "main.h"

/**
 * chr_print - writes the character c to stdout
 * @arg: input char
 * @buf: buffer pointer
 * @ind: index for buffer pointer
 * Return: On success 1.
 */
int chr_print(va_list arg, char *buf, unsigned int ind)
{
	char c;

	c = va_arg(arg, int);
	buff_handler(buf, c, ind);
	return (1);
}
