#include "shell.h"

/**
 * _strcmp - compare two strings.
 * @str1: is the first string to be compared.
 * @str2: is the second string to be compared.
 *
 * Return: the number of bytes that differ.
 */
int _strcmp(const char *str1, const char *str2)
{
	int i, a;

	a = 0;
	for (i = 0; str1[i] || str2[i]; i++)
	{
		a = str1[i] - str2[i];
		if (a != 0)
			break;
	}

	return (a);
}

/**
 * _strncmp - compare two strings up to a specified length (n).
 * @str1: is the first string to compare
 * @str2: is the second string to compare
 * @n: the maximum number of characters to compare
 *
 * Return: the number of bytes that differ
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;
	int diff;

	if (str1 == NULL || str2 == NULL)
		return (-1);

	for (i = 0; (str1[i] || str2[i]) && i < n; i++)
	{
		diff = str1[i] - str2[i];
		if (diff != 0)
			return (diff);
	}

	return (0);
}

/**
 * _strcpy - copy a string from source to destination
 * @dest: the destination buffer
 * @src: the source string to be copied
 *
 * Return: a pointer to the destination buffer
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strncpy - copies up to 'n' characters from the source string
 *            to the destination string.
 * @dest: the destination buffer.
 * @src: the source string to copy from.
 * @n: the maximum number of characters to copy.
 *
 * Return: a pointer to the destination buffer 'dest'.
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	char *original_dest = dest;

	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}

	while (n--)
		*dest++ = '\0';

	return (original_dest);
}

/**
 * _strcat - concatenate two strings and add a nullb byte.
 * @dest: the destination string.
 * @src: the source string.
 *
 * Return: a pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int dest_len;

	if (dest == NULL || src == NULL)
		return (NULL);

	dest_len = _strlen(dest);

	for (i = 0; src[i]; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
