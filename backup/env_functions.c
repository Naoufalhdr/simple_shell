#include "shell.h"

/**
 * _printenv - print all environment variables to standard output.
 *
 */
void _printenv(void)
{
	char **env;

	env = environ;
	while (*env != NULL)
	{
		write(1, *env, _strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}

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
 * _unsetenv - removes an environment variable.
 * @name: thhe name of  the environment variable to unset.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
	char **env;
	size_t name_len;
	int new_env_size;

	if (name == NULL)
		return (-1);

	new_env_size = 0;
	name_len = _strlen(name);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) != 0 || (*env)[name_len] != '=')
			environ[new_env_size++] = *env;
	}
	environ[new_env_size] = NULL;

	return (0);
}

/**
 * _setenv - adds or modifies an environment variable.
 * @name: is the name of the environment variable to set.
 * @value: is the value to assign to the environment variable.
 * @overwrite: flag indicating whether to overwrite if the variable
 *             already exists.
 *
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *existing_value;
	char *new_entry;
	int environ_size = 0;

	if (name == NULL || value == NULL)
		return (-1);

	/* Checks if the environment variable already exists */
	existing_value = _getenv(name);
	if (existing_value != NULL && !overwrite)
		return (0);

	/* Remove the existing variable */
	_unsetenv(name);

	/* Calculate the lenght of the new entry, and allocate memory for it */
	new_entry = malloc(_strlen(name) + _strlen(value) + 2);
	if (new_entry == NULL)
		return (-1);

	/* Construct the new entry */
	_strcpy(new_entry, name);
	_strcat(new_entry, "=");
	_strcat(new_entry, value);

	/* Calculate the number of environment variables presents*/
	while (environ[environ_size] != NULL)
		environ_size++;

	/* Add the new entry */
	environ[environ_size++] = new_entry;
	environ[environ_size] = NULL;

	return (0);
}
