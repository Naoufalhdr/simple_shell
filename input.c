#include "shell.h"

/**
 * _putchar - Outputs a single character to the standard output.
 * @c: The character to be output.
 *
 * Return: None.
 */
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * _puts - Outputs a null-terminated string to the standard output.
 * @str: The pointer to the null-terminated string to be output.
 *
 * Return: None.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * sigint_handler - handle signal
 * @signum: signum int
 *
 */
void sigint_handler(int signum)
{
	(void) signum;
	_puts("\n$ ");
}
