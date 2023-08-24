#include "shell.h"

/**
 * found_command - finds the full path of a command using the PATH
 *                 environment variable.
 * @command: The command to be located.
 *
 * Return: a pointer to a string containing the full path of the command;
 *         or the original command if not found.
 */

char *found_command(char *command)
{
	char *path = _getenv("PATH");
	char *token;
	char *path_copy;
	char *full_path;
	struct stat file_info;

	path_copy = _strdup(path);
	token = strtok(path_copy, ":");

	/* Check if the command is a relative or absolute path*/
	if (command[0] == '/' || command[0] == '.' || command[0] == '~')
	{
		if (stat(command, &file_info) == 0)
			/* Return the provided path if it exists */
			return (_strdup(command));
	}
	/* Check If the command is found in PATH directories */
	else
	{
		while (token != NULL)
		{
			full_path = malloc(_strlen(token) + _strlen(command) + 2);
			if (full_path == NULL)
				return (NULL);

			_strcpy(full_path, token);
			_strcat(full_path, "/");
			_strcat(full_path, command);

			if (stat(full_path, &file_info) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
			token = strtok(NULL, ":");
		}
	}
	free(path_copy);
	return (NULL);
}
