#include "shell.h"

/**
 * execute_command - execute a command using fork and execve.
 * @command: the array of strings containing the command and its arguments.
 *
 */
void execute_command(char *command[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		execve(command[0], command, NULL);
		/* If execve fails */
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}
}

/**
 * main - simple shell.
 *
 * Return: 0 if success.
 */
int main(void)
{
	char *line = NULL, *token, *command[MAX], *expanded_cmd;
	size_t len = 0;
	ssize_t nread;
	int i;
	shell_data_t data = {0};

	while (1)
	{
		write(1, "$ ", 2);
		nread = _getline(&line, &len);
		if (nread == -1) /* Handle Ctrl+D (EOF) condition */
		{
			printf("\n");
			break;
		}

		if (line[0] == '\n')
			continue;
		if (line[nread - 1] == '\n' && nread > 0) /* Remove newline character */
			line[nread - 1] = '\0';
		if (builtint_command(line, &data) == 1) /* check for built-in commands */
			continue;
		i = 0;
		token = strtok(line, " \t\n"); /* Tokenize the input */
		while (token != NULL)
		{
			command[i++] = token;
			token = strtok(NULL, " \t");
		}
		command[i] = NULL;
		command[0] = replace_alias_with_command(command[0], &data);
		if (_strchr(command[0], ' ') != NULL)
		{ /* Re-tokenize if the alias has spaces */
			expanded_cmd = _strdup(command[0]);
			i = 0;
			token = strtok(expanded_cmd, " \t\n");
			while (token != NULL)
			{
				command[i++] = token;
				token = strtok(NULL, " \t");
			}
			free(expanded_cmd);
		}
		command[0] = found_command(command[0]);
		if (command[0] == NULL) /* Check if the command is found in PATH */
		{
			fprintf(stderr, "Command not found or not in PATH\n");
			continue;
		}
		execute_command(command); /* Execute command */
	}
	free(line);
	return (0);
}
