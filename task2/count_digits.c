#include "main.h"

/**
 * count_digits - counts the number of digits in an integer
 * @n: integer to evaluate
 *
 * Return: number of digits in n
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
