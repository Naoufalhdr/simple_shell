#include "shell.h"

/**
 * _printenv - display all environment variables.
 * @args: parsed parameters.
 * @input: raw input command.
 *
 * Return: always 0.
 */
int _printenv(char **args, char *input)
{
	char **env;

	(void)input;
	(void)args;

	env = environ;

	if (!env)
		return (0);

	while (*env != NULL)
	{
		_puts(*env, 1);
		_putchar('\n', 1);
		env++;
	}

	return (0);
}

/**
 * _mysetenv - modify or add an environment variable.
 * @args: split input tokens.
 * @input: original command line.
 *
 * Return: always 0.
 */
int _mysetenv(char **args, char *input)
{
	int args_count = 0;

	(void)input;

	/* Count the number of args */
	while (args[args_count])
		args_count++;

	if (args_count == 3)
		_setenv(args[1], args[2], 1);
	_printenv(args, input);

	return (0);
}

/**
 * _myunset - remove an environment variable.
 * @args: split input tokens.
 * @input: original command line.
 *
 * Return: always 0.
 */
int _myunset(char **args, char *input)
{
	int args_count = 0;

	(void)input;

	/* Count the number of args */
	while (args[args_count])
		args_count++;

	if (args_count == 2)
		_unset(args[1]);

	return (0);
}

/**
 * _myexit - exit the shell with a specified status.
 * @args: an array of arguments.
 * @input: the original user input string.
 * Return: an int.
 */
int _myexit(char **args, char *input)
{
	int arg_count = 0;
	int exit_status;

	while (args[arg_count])
		arg_count++;

	if (arg_count == 1)
	{
		free_tokens(args);
		free(input);
		exit(0);
	}

	if (!is_all_digits(args[1]))
	{
		_puts(SHELL_NAME, 2);
		_puts(": 1: exit: Illegal number: ", 2);
		_puts(args[1], 2);
		_puts("\n", 2);
		return (2);
	}

	exit_status = _atoi(args[1]);
	free(input);
	free_tokens(args);
	exit(exit_status);
	/*return (0);*/
}

