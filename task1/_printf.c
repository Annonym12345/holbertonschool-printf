#include "main.h"
#include <stdarg.h>

/**
 * count_digits - count digits of integer
 * @n: number
 *
 * Return: number of digits
 */
int count_digits(int n)
{
	int count = 0;

	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/**
 * _printf - prints text and handles %d / %i
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);
	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			int n = va_arg(args, int);

			print_number(n);
			count += count_digits(n);
			i += 2;
			continue;
		}

		_putchar(format[i]);
		count++;
		i++;
	}
	va_end(args);
	return (count);
}
