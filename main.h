#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>

/**
 * struct format_specifier - struct for printing various types
 * @id: format specified to print
 * @fprint: function to print
 */
typedef struct format_specifier
{
	char *id;
	int (*fprint)(va_list);
} printer;

int _putchar(char c);
int _printf(const char *format, ...);
int print_integer(va_list i);
int print_decimal(va_list d);
int print_char(va_list c);
int print_string(va_list s);

#endif

