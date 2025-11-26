#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints a string exactly as given (no format handling)
 * @format: string to print
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;

	if (!format)
		return (-1);
	while (format[i])
	{
		_putchar(format[i]);
		count++;
		i++;
	}
	return (count);
}
