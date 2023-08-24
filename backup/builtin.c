#include "shell.h"

/**
 * _myexit - exits the shell with a specified status.
 * @input: the input line containing the 'exit' command and status value.
 *
 */
void _myexit(char *input)
{
	char *token;
	char buffer[100];
	int status;

	_strncpy(buffer, input, sizeof(buffer) - 1);
	buffer[sizeof(buffer) - 1] = '\0';

	token = strtok(buffer, " ");
	token = strtok(NULL, " ");
	if (token == NULL)
		exit(0);

	if (!is_all_digits(token))
	{
		printf("exit: Illegal number: %s\n", token);
		return;
	}

	status = _atoi(token);
	exit(status);
}

/**
 * _mycd - change the current working directory.
 * @line: the input line containing the 'cd' command and arguments.
 *
 */
void _mycd(char *line)
{
	char cwd[BUFFER_SIZE];
	char *arg = strtok(line + 2, " \t");

	if (arg == NULL || _strcmp(arg, "$HOME") == 0)
		arg = _getenv("HOME");

	if (arg != NULL && _strcmp(arg, "-") == 0)
		arg = _getenv("OLDPWD");

	if (arg != NULL && chdir(arg) == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			_setenv("OLDPWD", _getenv("PWD"), 1);
			_setenv("PWD", cwd, 1);
		}
		else
			perror("cd");
	}
	else
		perror("cd");
}

/**
 * _mysetenv - set an environment variable.
 * @line: the input line containing the 'setenv' command and arguments.
 *
 */
void _mysetenv(char *line)
{
	char *var_name, *var_value;

	var_name = strtok(line + 6, " \t");
	if (var_name != NULL)
	{
		var_value = strtok(NULL, " \t\n");
		if (var_value != NULL)
		{
			if (_setenv(var_name, var_value, 1) != 0)
				fprintf(stderr, "Failed to set environment variable.\n");
		}
		else
			fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	}
	else
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
}

/**
 * _myunsetenv - unset an environment variable.
 * @line: the input line containing the 'unsetenv' command and arguments.
 *
 */
void _myunsetenv(char *line)
{
	char *var_name;

	var_name = strtok(line + 8, " \t");
	if (var_name != NULL)
	{
		if (_unsetenv(var_name) != 0)
			fprintf(stderr, "Failed to unset environment variable.\n");
	}
	else
		fprintf(stderr, "Usage: unsetenv VARIABLE_NAME\n");
}

/**
 * builtint_command - execute built-in shell commands.
 * @line: is the  input line containing the shell command.
 * @data: a pointer to shell data.
 *
 * Return: 1 if the command is a built-in command and executed;
 *          or 0 if not a built-in command.
 */
int builtint_command(char *line, shell_data_t *data)
{
		/* Handle 'cd' command */
		if (_strncmp(line, "cd", 2) == 0)
		{
			_mycd(line);
			return (1);
		}

		/* Handle the setenv built-in command */
		if (_strncmp(line, "setenv", 6) == 0)
		{
			_mysetenv(line);
			return (1);
		}

		/* Handle the unsetenv built-in command */
		if (_strncmp(line, "unsetenv", 8) == 0)
		{
			_myunsetenv(line);
			return (1);
		}

		/* Handle the alias built in command */
		if (_strncmp(line, "alias", 5) == 0)
		{
			_myalias(line, data);
			return (1);
		}
		/* Print the current environment variables */
		if (_strcmp(line, "env") == 0)
		{
			_printenv();
			return (1);
		}
		/* Exit the shell if the user enter 'exit' */
		if (_strncmp(line, "exit", 4) == 0)
		{
			_myexit(line);
			return (1);
		}
		return (0);
}
