#include "main.h"

/**
 * s_oct - calculates a short octal number
 * @bnr: binary array.
 * @oct: octal array.
 * Return: binary array.
 */
char *s_oct(char *bnr, char *oct)
{
	int op, i, j, x, limit;

	oct[6] = '\0';
	for (i = 15, x = 5; i >= 0; i--, x--)
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
