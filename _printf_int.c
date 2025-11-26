#include "main.h"

/**
* print_int - prints an integer
* @n: integer to print
* Return: number of chars printed
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
