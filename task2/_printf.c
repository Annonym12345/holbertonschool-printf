#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing directives
 *
 * Return: total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				int n = va_arg(args, int);

				print_number(n);
				count += count_digits(n);
				i += 2;
				continue;
			}

			if (format[i + 1] == 'c')
			{
				count += _putchar(va_arg(args, int));
				i += 2;
				continue;
			}

			if (format[i + 1] == 's')
			{
				char *s = va_arg(args, char *);
				int j = 0;

				if (s == NULL)
					s = "(null)";

				while (s[j])
				{
					_putchar(s[j]);
					count++;
					j++;
				}
				i += 2;
				continue;
			}

			if (format[i + 1] == '%')
			{
				count += _putchar('%');
				i += 2;
				continue;
			}
		}

		count += _putchar(format[i]);
		i++;
	}

	va_end(args);
	return (count);
}
