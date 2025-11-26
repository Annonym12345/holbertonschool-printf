#include "main.h"
#include <unistd.h>

/**
 * _putchar - write one character to stdout
 * @c: character to print
 *
 * Return: number of chars written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - print a number using recursion
 * @n: integer to print
 */
void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
		num = n;
	if (num > 9)
		print_number(num / 10);

	_putchar((num % 10) + '0');
}
