#include "shell.h"

/**
 * tokenize_input - aaa
 * @input: aaa
 *
 * Return: aaa
 */
char **tokenize_input(char *input)
{
	char **tokens;
	char *token;
	int token_count = 0;
	int i;

	tokens = malloc(20 * sizeof(char *));
	if (tokens == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(input, " \t");
	while (token != NULL)
	{
		tokens[token_count] = _strdup(token);
		if (tokens[token_count] == NULL)
		{
			perror("strdup");
			/* Free the previously allocated tokens and return NULL */
			for (i = 0; i < token_count; i++)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, " \t");
		token_count++;
	}
	tokens[token_count] = NULL;

	/* No command entered */
	if (token_count == 0)
	{
		free(tokens);
		return (NULL);
	}

	return (tokens);
}

/**
 * command_found - aaa
 * @command: aaa
 * @command_fullpath: aaa
 *
 * Return: aaa
 */
int command_found(const char *command, char **command_fullpath)
{
	char *path, *path_copy, *path_token, *full_path;
	int fullpath_len;

	path = _getenv("PATH");
	if (path == NULL)
	{ /* if path not set */
		perror("getenv");
		return (0);
	}
	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (0);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		fullpath_len = _strlen(path_token) + _strlen(command) + 2;
		full_path = malloc(fullpath_len);
		if (full_path == NULL)
		{
			perror("malloc");
			return (0);
		}
		_strcpy(full_path, path_token);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		/* Checks if command is found and executable */
		if (access(full_path, X_OK) == 0)
		{
			*command_fullpath = _strdup(full_path);
			free(full_path);
			free(path_copy);
			return (1); /* command found */
		}

		path_token = strtok(NULL, ":");
		free(full_path);
	}

	free(path_copy);
	return (0); /* command not found */
}

/**
 * free_tokens - aaa
 * @tokens: aaa
 *
 * Return: none;
 */
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);
	free(tokens);
}
