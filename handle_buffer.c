#include "main.h"

/**
 * buff_handler - concatenates the buffer characters
 * @buf: buffer pointer
 * @c: charcter to concatenate
 * @ind: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int buff_handler(char *buf, char c, unsigned int ind)
{
	if (ind == 1024)
	{
		buff_print(buf, ind);
		ind = 0;
	}
	buf[ind] = c;
	ind++;
	return (ind);
}
