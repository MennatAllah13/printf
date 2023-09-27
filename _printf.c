#include "main.h"

/**
 * print_f - form output conversion and print data.
 * @form: input string.
 * Return: number of char printed.
 */
int print_f(const char *form, ...)
{
	unsigned int i = 0, len = 0, ind = 0;
	va_list arg;
	int (*func)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arg, form), buffer = malloc(sizeof(char) * 1024);
	if (!form || !buffer || (!form[i + 1] && form[i] == '%'))
		return (-1);
	if (!form[i])
		return (0);
	for (i = 0; form && form[i]; i++)
	{
		if (form[i] == '%')
		{
			if (form[i + 1] == '\0')
			{	buff_print(buffer, ind), free(buffer), va_end(arg);
				return (-1);
			}
			else
			{	func = get_func(form, i + 1);
				if (!func)
				{
					if (form[i + 1] == ' ' && !form[i + 2])
						return (-1);
					buff_handler(buffer, form[i], ind), len++, i--;
				}
				else
				{
					len += func(arg, buffer, ind);
					i += num_id(form, i + 1);
				}
			} i++;
		}
		else
			buff_handler(buffer, form[i], ind), len++;
		for (ind = len; ind > 1024; ind -= 1024)
			;
	}
	buff_print(buffer, ind), free(buffer), va_end(arg);
	return (len);
}
