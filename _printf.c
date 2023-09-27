#include "main.h"

/**
 * _printf - form output conversion and print data.
 * @format: input string.
 * Return: number of char printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ind = 0;
	va_list arg;
	int (*func)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arg, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (!format[i + 1] && format[i] == '%'))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	buff_print(buffer, ind), free(buffer), va_end(arg);
				return (-1);
			}
			else
			{	func = get_func(format, i + 1);
				if (!func)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					buff_handler(buffer, format[i], ind), len++, i--;
				}
				else
				{
					len += func(arg, buffer, ind);
					i += num_id(format, i + 1);
				}
			} i++;
		}
		else
			buff_handler(buffer, format[i], ind), len++;
		for (ind = len; ind > 1024; ind -= 1024)
			;
	}
	buff_print(buffer, ind), free(buffer), va_end(arg);
	return (len);
}
