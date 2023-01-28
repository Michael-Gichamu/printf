#include "main.h"
#include <stdlib.h>
#include <unistd.h>

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

/**
 * print_char - prints a char
 * @c: char to print
 *
 * Return: always 1
 */
int print_char(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}

/**
 * print_string - prints a string
 * @s: string to print
 *
 * Return: number of chars printed
 */
int print_string(va_list s)
{
	int count;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(nill)";
	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}
	return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));

}

