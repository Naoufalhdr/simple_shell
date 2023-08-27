#include "shell.h"

/**
 * _getenv - gets the value of an environment variable.
 * @name: the name of  the environment variable to retrieve.
 *
 * Return: the value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len;

	if (name == NULL)
		return (NULL);

	name_len = _strlen(name);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
			return (*env + name_len + 1);
	}

	return (NULL);
}

/**
 * _printenv - display all environment variables.
 *
 * Return: none.
 */
void _printenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}
