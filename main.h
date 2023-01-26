#ifndef _MAIN_H_
#define _MAIN_H_

int _printf(const char *format, ...);

/**
 * struct format_specifier - format specifiers
 * @id: symbol representing data types
 * @print: function pointer
 */

typedef struct format_specifier
{
	char *id;
	void (*print)(va_list args);
} printer;

#endif

