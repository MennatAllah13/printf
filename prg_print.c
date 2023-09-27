#include "main.h"

/**
 * prg_print - writes the character c to stdout
 * @a: input char
 * @buf: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */
int prg_print(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
	buff_handler(buf, '%', i);
	return (1);
}
