# Git Intro Project

Custom implementation of the C standard printf function.
This version handles only the following format specifiers:

- %c : prints a character
- %s : prints a string
- %% : prints a percent sign

It does not implement flags, field width, precision,
length modifiers or any additional specifiers.

Return: number of characters printed.


_print.c
// #include "main.h"

/**
** _printf - custom printf that handles %d and %i
** @format: format string
** Return: number of characters printed
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



_print_int.c
// #include "main.h"

/**
** print_int - prints an integer
** @n: integer to print
** Return: number of chars printed
*/
int print_int(int n)
{
        long num = n;
        int count = 0;
        char c;

        if (num < 0)
        {
                count += write(1, "-", 1);
                num = -num;
        }

        if (num / 10)
                count += print_int(num / 10);

        c = (num % 10) + '0';
        count += write(1, &c, 1);

        return (count);
}
