#include "main.h"

/**
 * hex_array - writes the character c to stdout
 * @bnr: array where is stored the binary.
 * @hex: array where is stored the hexadecimal.
 * @isupp: integer that determines if the hexadecimal array is
 * in uppercase or lowercase letter.
 * @limit: size of hex
 * Return: binary array.
 */
char *hex_array(char *bnr, char *hex, int isupp, int limit)
{
	int op, i, j, c;

	hex[limit] = '\0';
	if (isupp)
		c = 55;
	else
		c = 87;
	for (i = (limit * 4) - 1; i >= 0; i--)
	{
		for (op = 0, j = 1; j <= 8; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		if (op < 10)
			hex[i / 4] = op + 48;
		else
			hex[i / 4] = op + c;
	}
	return (hex);
}
