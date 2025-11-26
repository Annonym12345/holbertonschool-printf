#include "main.h"

/**
* _printf - produces output according to a format
* @format: character string with zero or more directives
*
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			if (format[i] == 'c')
				count += print_char(va_arg(args, int));

			else if (format[i] == 's')
				count += print_string(va_arg(args, char *));

			else if (format[i] == '%')
				count += print_char('%');
			else
			{
				count += print_char('%');
				count += print_char(format[i]);
			}
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
