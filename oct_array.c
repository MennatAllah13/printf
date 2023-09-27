#include "main.h"

/**
 * oct_array - writes the character c to stdout.
 * @bnr: binary array.
 * @oct: octal array.
 * Return: binary array.
 */
char *oct_array(char *bnr, char *oct)
{
	int op, i, j, x, limit;

	oct[11] = '\0';
	for (i = 31, x = 10; i >= 0; i--, x--)
	{
		if (i > 1)
			limit = 4;
		else
			limit = 2;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		oct[x] = op + '0';
	}
	return (oct);
}
