#include "shell.h"

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
 * _strcpy - copy a string from source to destination
 * @dest: the destination buffer
 * @src: the source string to be copied
 *
 * Return: a pointer to the destination buffer
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
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
