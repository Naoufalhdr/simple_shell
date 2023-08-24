#include "shell.h"

/**
 * _atoi - convert a string to an integer.
 * @s: the string to convert.
 * Return: the converted string.
 */

int _atoi(char *s)
{
	int i, j, sign;
	unsigned int result;

	sign = 0;
	result = 0;
	j = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-')
			sign++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			j = 1;
		}
		else if (j == 1)
			break;
	}
	if (sign % 2 != 0)
		sign = -1;
	else
		sign = 1;
	return (result * sign);
}


/**
 * _strlen - calculate the length of a string.
 * @str: the input string to be measured.
 *
 * Return: the length of the string.
 */
int _strlen(const char *str)
{
	size_t lenght = 0;

	while (str[lenght] != '\0')
		lenght++;

	return (lenght);
}

/**
 * _putchar - writes a single character to the provided buffer.
 * @c: the character to be written.
 * @buffer: the file descriptor to which the character will be written
 *
 * Return: 1 if the character was successfully written;
 *         or -1 in case of a write error.
 */
int _putchar(char c, int buffer)
{
	return (write(buffer, &c, 1));
}

/**
 * _puts - writes a string to the provided buffer.
 * @s: the string to be written.
 * @buffer: the file descriptor or buffer to which the string will be written.
 *
 */
void _puts(char *s, int buffer)
{
	write(buffer, s, _strlen(s));
}

/**
 * is_all_digits - checks if a string consists of only digits.
 * @s: is the  string to check.
 *
 * Return: 1 if the string contains only digits, otherwise 0.
 */
int is_all_digits(char *s)
{
	for (; *s; s++)
	{
		if (*s < '0' || *s > '9')
			return (0);
	}
	return (1);
}
