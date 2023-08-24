#include "shell.h"

/**
 * _strdup - duplicates a string.
 * @src: the source string to duplicate.
 *
 * Return: a pointer to the duplicated string;
 *         or NULL if memory allocation fails or if the source string is NULL
 */
char *_strdup(const char *src)
{
	char *duplicate;
	int src_len = _strlen(src);

	if (src == NULL)
		return (NULL);

	duplicate = malloc(src_len + 1);

	if (duplicate == NULL)
		return (NULL);

	_strcpy(duplicate, src);

	return (duplicate);
}

/**
 * _strchr - locates the first occurrence of a character in a string.
 * @s: the string to search in.
 * @c: the character to search for.
 *
 * Return: a pointer to the first occurrence of the character 'c';
 *         or NULL if 'c' is not found in 's'.
 */
char *_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}

	if (*s == c)
		return ((char *)s);

	return (NULL);
}

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
size_t _strlen(const char *str)
{
	size_t lenght = 0;

	while (str[lenght] != '\0')
		lenght++;

	return (lenght);
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
