#include "shell.h"

/**
 * _memcpy - copy a block of memory.
 * @dest: a pointer to the destination memory area.
 * @src: a pointer to the source memory area.
 * @n: the number of bytes to copy.
 *
 * Return: a pointer to the destination memory area 'dest'
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *d = (char *)dest;
	const char *s = (const char *)src;

	while (n--)
		*d++ = *s++;

	return (dest);
}

/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: a pointer to the memory block to be reallocated.
 * @old_size:  size of the currently allocated memory block.
 * @new_size: new  size of the memory block to be reallocated.
 *
 * Return: a pointer to the reallocated memory block,
 *         or NULL on failure or when new_size is 0.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned char *char_ptr;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		p = malloc(new_size);
		return (p);
	}

	if (new_size > old_size)
	{
		p = malloc(new_size * sizeof(char));
		char_ptr = (unsigned char *)ptr;
		for (i = 0; i < old_size && i < new_size; i++)
			p[i] = char_ptr[i];
		free(ptr);
		return (p);
	}

	return (ptr);
}
