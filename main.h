#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct print - struct for printer functions
 * @type: identifier
 * @f: pointer to a printer functions
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type;
	int (*f)(va_list, char *, unsigned int);
} S_print;

int _printf(const char *format, ...);
int prg_print(va_list __attribute__((unused)), char *, unsigned int);
int chr_print(va_list arg, char *buf, unsigned int ind);
int str_print(va_list arg, char *buf, unsigned int ind);
int int_print(va_list arg, char *buf, unsigned int ind);
int bnr_print(va_list arg, char *buf, unsigned int ind);
int uint_print(va_list arg, char *buf, unsigned int ind);
int oct_print(va_list arg, char *buf, unsigned int ind);
int hex_print(va_list arg, char *buf, unsigned int ind);
int upx_print(va_list arg, char *buf, unsigned int ind);
int usr_print(va_list arg, char *buf, unsigned int ind);
int add_print(va_list arg, char *buf, unsigned int ind);
int rev_print(va_list arg, char *buf, unsigned int ind);
int rot_print(va_list arg, char *buf, unsigned int ind);
int lint_print(va_list arg, char *buf, unsigned int ind);
int luint_print(va_list arg, char *buf, unsigned int ind);
int loct_print(va_list arg, char *buf, unsigned int ind);
int lhex_print(va_list arg, char *buf, unsigned int ind);
int lhex2_print(va_list arg, char *buf, unsigned int ind);
int sint_print(va_list arg, char *buf, unsigned int ind);
int suint_print(va_list arg, char *buf, unsigned int ind);
int loct2_print(va_list arg, char *buf, unsigned int ind);
int shex_print(va_list arg, char *buf, unsigned int ind);
int shex2_print(va_list arg, char *buf, unsigned int ind);
int pint_print(va_list arg, char *buf, unsigned int ind);
int zoct_print(va_list arg, char *buf, unsigned int ind);
int zhex_print(va_list arg, char *buf, unsigned int ind);
int uhex_print(va_list arg, char *buf, unsigned int ind);
int _int_print(va_list arg, char *buf, unsigned int ind);
int (*get_func(const char *s, int index))(va_list, char *, unsigned int);
int num_id(const char *s, int index);
unsigned int buff_handler(char *buf, char c, unsigned int ind);
int buff_print(char *buf, unsigned int nbuf);
char *dtob(char *binary, long int int_in, int isneg, int limit);
char *oct_array(char *bnr, char *oct);
char *l_oct(char *bnr, char *oct);
char *s_oct(char *bnr, char *oct);
char *hex_array(char *bnr, char *hex, int isupp, int limit);

#endif
