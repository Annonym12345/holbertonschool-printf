#include "main.h"

/**
* _printf - custom printf that handles %d and %i
* @format: format string
* Return: number of characters printed
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
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'd' || format[i] == 'i')
				count += print_int(va_arg(args, int));
			else if (format[i] == '%')
				count += write(1, "%", 1);
			else
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return (count);
}
