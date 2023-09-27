#include "main.h"

/**
 * rot_print - writes the str in ROT13
 * @arg: input string
 * @buf: buffer pointer
 * @ind: index buffer pointer
 * Return: number of char printed.
 */
int rot_print(va_list arg, char *buf, unsigned int ind)
{
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	char nill[] = "(avyy)";
	unsigned int i, j, k;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ind = buff_handler(buf, nill[i], ind);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alf[j]; j++)
		{
			if (str[i] == alf[j])
			{
				k = 1;
				ind = buff_handler(buf, rot[j], ind);
				break;
			}
		}
		if (k == 0)
			ind = buff_handler(buf, str[i], ind);
	}
	return (i);
}
