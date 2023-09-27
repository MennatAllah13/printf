#include "main.h"

/**
 * l_oct - calculates long octal numbers.
 * @bnr: binary array.
 * @oct: octal array.
 * Return: binary array.
 */
char *l_oct(char *bnr, char *oct)
{
	int op, i, j, x, limit;

	oct[22] = '\0';
	for (i = 63, x = 21; i >= 0; i--, x--)
	{
		if (i > 0)
			limit = 4;
		else
			limit = 1;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		oct[x] = op + '0';
	}
	return (oct);
}
