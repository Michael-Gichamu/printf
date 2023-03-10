#include "main.h"
#include <stdlib.h>
#include <stdio.h>

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
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}
	return (count);
}

