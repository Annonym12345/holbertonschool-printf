#include "main.h"

/**
* print_char - prints a character
* @c: char to print
*
* Return: number of characters printed
*/
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
* print_string - prints a string
* @s: string to print
*
* Return: number of characters printed
*/
int print_string(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}
