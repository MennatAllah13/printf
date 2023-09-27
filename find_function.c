#include "main.h"

/**
 * get_func - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*get_func(const char *s, int index))(va_list, char *, unsigned int)
{
	S_print p[] = {
		{"c", chr_print}, {"s", str_print},
		{"i", int_print}, {"d", int_print},
		{"b", bnr_print}, {"u", uint_print},
		{"o", oct_print}, {"x", hex_print},
		{"X", upx_print}, {"S", usr_print},
		{"p", add_print}, {"li", lint_print},
		{"ld", lint_print}, {"lu", luint_print},
		{"lo", loct_print}, {"lx", lhex_print},
		{"lX", lhex2_print}, {"hi", sint_print},
		{"hd", sint_print}, {"hu", suint_print},
		{"ho", loct2_print}, {"hx", shex_print},
		{"hX", shex2_print}, {"#o", zoct_print},
		{"#x", zhex_print}, {"#X", uhex_print},
		{"#i", int_print}, {"#d", int_print},
		{"#u", uint_print}, {"+i", pint_print},
		{"+d", pint_print}, {"+u", uint_print},
		{"+o", oct_print}, {"+x", hex_print},
		{"+X", upx_print}, {" i", _int_print},
		{" d", _int_print}, {" u", uint_print},
		{" o", oct_print}, {" x", hex_print},
		{" X", upx_print}, {"R", rot_print},
		{"r", rev_print}, {"%", prg_print},
		{"l", prg_print}, {"h", prg_print},
		{" +i", pint_print}, {" +d", pint_print},
		{"+ i", pint_print}, {"+ d", pint_print},
		{" %", prg_print}, {NULL, NULL},
	};
	int i = 0, j = 0, f_index;

	f_index = index;
	while (p[i].type)
	{
		if (s[index] == p[i].type[j])
		{
			if (p[i].type[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = f_index;
		}
	}
	return (p[i].f);
}
