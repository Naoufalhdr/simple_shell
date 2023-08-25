#include "shell.h"

/**
 * _mycd - built-in cd
 * @args: tokens
 * @input: input
 * Return: int
 */
int _mycd(char **args, char *input __attribute__((unused)))
{
	int i = 0, check = 0;
	char buff[1024];

	while (args[i])
		i++;
	if (!_getenv("OLDPWD"))
		set_old_pwd(buff);

	if (i == 1)
	{
		cd_home(buff);
		_puts("/root\n", 1);
		return (0);
	}
	if (i == 2)
	{
		if (_strcmp(args[1], "-") == 0)
			check = chdir(_getenv("OLDPWD"));
		else
			check = chdir(args[1]);

		if (!check)
		{
			_setenv("OLDPWD", _getenv("PWD"), 1);
			if (getcwd(buff, sizeof(buff)) != NULL)
			{
				if (_strcmp(args[1], "-") == 0)
				{
					_puts(buff, 2);
					_puts("\n", 2);
				}
				_setenv("PWD", buff, 1);
				return (0);
			}
		}
	}
	_puts("hsh: 1: cd: can't cd to ", 2);
	_puts(args[1], 2);
	_puts("\n", 2);
	return (0);
}

/*
 * _mycd - change the current working directory.
 * @line: the input line containing the 'cd' command and arguments.
 *
 *
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
*/
