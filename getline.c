#include "shell.h"

static char buffer[BUFFER_SIZE];
static size_t buffer_index;
static size_t buffer_size;

/**
 * _read_input - reads input from standard input into the buffer.
 *
 * Return: the number of bytes read, or -1 if an error occurs.
 */
size_t _read_input(void)
{
	if (buffer_index >= buffer_size)
	{
		buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (buffer_size <= 0)
			return (buffer_size);
		buffer_index = 0;
	}

	return (buffer_size);
}

/**
 * _getline - reads a line from standard input and stores it in 'lineptr'.
 * @lineptr: a pointer to the buffer to store the line.
 * @n: a pointer to the size of the buffer.
 *
 * Return: the number of characters read, or -1 if an error occurs.
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	size_t pos = 0, bytes_read;

	if (lineptr == NULL || n == NULL)
		return (-1);
	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			bytes_read = _read_input();
			if (bytes_read <= 0)
			{
				if (pos == 0)
					return (-1);
				break;
			}
		}
		if (buffer[buffer_index] == '\n')
		{
			if (*lineptr == NULL || *n < pos + 2)
			{
				*n = pos + 2;
				*lineptr = _realloc(*lineptr, pos, *n);
				if (*lineptr == NULL)
					return (-1);
			}
			(*lineptr)[pos++] = '\n';
			(*lineptr)[pos] = '\0';
			buffer_index++;
			break;
		}
		if (*lineptr == NULL || *n < pos + 1)
		{
			*n = pos + 1;
			*lineptr = _realloc(*lineptr, pos, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		(*lineptr)[pos++] = buffer[buffer_index++];
	}
	return ((ssize_t)pos);
}
