#include "shell.h"

/**
 * _strccat - concatenate two strings and a character in between.
 * @dest: the destination string.
 * @src: the source string.
 * @c: character to be inserted between the two strings.
 *
 * Return: a pointer to the destination string.
 */
char *_strccat(char *dest, const char *src, char c)
{
	int dest_len, src_len;
	int i, j;
	char *new_str;

	if (dest == NULL || src == NULL)
		return (NULL);

	dest_len = _strlen(dest);
	src_len = _strlen(src);
	new_str = malloc(dest_len + src_len + 2);
	if (new_str == NULL)
		return (NULL);

	for (i = 0; dest[i]; i++)
		new_str[i] = dest[i];
	new_str[i++] = c;

	for (j = 0; src[j]; i++, j++)
		new_str[i] = src[j];
	new_str[i] = '\0';

	return (new_str);
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
