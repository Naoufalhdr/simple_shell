#include "shell.h"

/**
 * cd_home - handle the cd wihout arguments case
 * @buff: buffer
 */

void cd_home(char *buff)
{
	int check = 0;

	check = chdir("/root");

	if (!check)
	{
		_setenv("OLDPWD", _getenv("PWD"), 0);
		if (getcwd(buff, sizeof(buff)) != NULL)
			_setenv("PWD", buff, 0);
	}
}
/**
 * set_old_pwd - set the OLDPWD variable if not exists
 * @buff: buffer
 */

void set_old_pwd(char *buff)
{
	char *temp;

	temp = _getenv("PWD");
	chdir("..");
	if (getcwd(buff, sizeof(buff)) != NULL)
		_setenv("OLDPWD", buff, 0);
	else
		perror("getcwd");
	chdir(temp);
}
