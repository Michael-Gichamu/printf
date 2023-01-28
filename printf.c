#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * check_specifier - checks if there is a valid format specifier
 * @format: format specifier
 *
 * Return: Pointer to Valid function or NULL
 */
int (*check_specifier(const char *format))(va_list)
{
	unsigned int i;
	printer fs[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};

	for (i = 0; fs[i].id != NULL; i++)
	{
		if (*(fs[i].id) == *format)
		{
			break;
		}
	}
	return (fs[i].fprint);
}

/**
 * _printf - print
 * @format: List of argument types passed to the function
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list valist;
	int (*fprint)(va_list);

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		fprint = check_specifier(&format[i + 1]);
		if (fprint != NULL)
		{
			count += fprint(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(valist);
	return (count);
}

