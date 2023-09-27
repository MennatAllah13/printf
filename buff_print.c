#include "main.h"

/**
 * buff_print - prints buffer
 * @buf: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int buff_print(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}
