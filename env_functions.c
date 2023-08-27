#include "shell.h"

#define MAX_COUNT 100
#define MAX_SIZE 2000

/**
 * _setenv - establish or modify an environment variable.
 * @name: is the name of the environment variable.
 * @value: is the value to be assigned.
 * @overwrite: if set to 0, the existing value won't be replaced.
 * Return: 0 if successful, -1 if failed.
 */
int _setenv(char *name, char *value, int overwrite)
{
	int idx = 0, found = 0, j, env_len;
	char *env[MAX_COUNT];
	char env_v[MAX_SIZE], env_g[MAX_SIZE];
	char eng[MAX_COUNT][MAX_SIZE];
	int name_len = _strlen(name);

	/* Search the environment variable */
	while (environ[idx])
	{
		if (_strncmp(name, environ[idx], name_len) == 0
				&& environ[idx][name_len] == '=')
		{
			found = 1;
			break;
		}
		idx++;
	}
	if (found)
	{
		if (overwrite == 1)
		{
			env[idx] = _putenv(env_g, name, value);
		}
		else
			return (0);
		environ[idx] = env[idx];
		return (0);
	}
	else
	{
		env_len = 0;
		while (environ[env_len] != NULL)
			env_len++;
		for (j = 0; environ[j]; j++)
			env[j] = _strcpy(eng[j], environ[j]);
		env[j] = _putenv(env_v, name, value);
		environ = env;
		return (0);
	}
	return (-1);
}

/*
 * _unset - Remove a specified environment variable.
 * @name: The name of the environment variable to be removed.
 *
 * Return: Always returns 0.
 */
int _unset(char *name)
{
	int i = 0, tst = 0;
	int namelen = _strlen(name);

	while (environ[i])
	{
		if (_strncmp(name, environ[i], namelen) == 0 && environ[i][namelen] == '=')
		{
			tst = 1;
			break;
		}
		i++;
	}
	if (tst == 1)
	{
		for (; environ[i] != NULL; i++)
			environ[i] = environ[i + 1];
	}
	return (0);
}

#include <string.h>

/**
 * _putenv - Concatenates environment variable name and its value.
 * @env: Buffer to hold the resulting concatenated string.
 * @name: Environment variable key.
 * @value: Corresponding value for the environment variable.
 *
 * Return: Pointer to the concatenated string stored in buf.
 */
char *_putenv(char *env, char *name, char *value)
{
	if (!name || !env)
		return (NULL);

	/* Copy name to env */
	_strcpy(env, name);
	/* Append '=' to env */
	_strcat(env, "=");
	/* Append value to env */
	_strcat(env, value);

	return (env);
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

