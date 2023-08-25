#include "shell.h"

/**
 * _mycd - change the current working directory.
 * @args: the input line containing the 'cd' command and arguments.
 * @input: Not used.
 *
 * Return: 0 if success;
 *         otherwise 1
 */
int _mycd(char **args, char *input __attribute__((unused)))
{
	char buff[1024];
	char *cwd = NULL;

	if (args[1] == NULL || _strcmp(args[1], "$HOME") == 0)
		cwd = _getenv("HOME");

	else if (args[1] != NULL && _strcmp(args[1], "-") == 0)
	{
		cwd = _getenv("OLDPWD");
		_puts(cwd, 1);
		_putchar('\n', 1);
	}
	else
		cwd = args[1];

	if (cwd != NULL && chdir(cwd) == 0)
	{
		if (getcwd(buff, sizeof(buff)) != NULL)
		{
			_setenv("OLDPWD", _getenv("PWD"), 1);
			_setenv("PWD", buff, 1);
		}
		else
		{
			perror("cd");
			return (1);
		}
	}
	else
	{
		perror("cd");
		return (1);
	}

	return (0);
}
