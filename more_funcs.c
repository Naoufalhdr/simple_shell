#include "shell.h"

/**
 * print_int - function that print a number
 * @n: number to write
 * Return: number of bytes written
 */
void print_int(int n)
{
	if (n >= 0 && n <= 9)
		_putchar(n + '0', 2);
	else
	{
		print_int(n / 10);
		print_int(n % 10);
	}
}
