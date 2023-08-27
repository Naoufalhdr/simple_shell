#include "shell.h"

int main(void)
{
	char **tokens, *full_path, *input = NULL;
	size_t len = 0;
	ssize_t nread;
	int is_found, status;
	pid_t pid;

	/* Set up the signal handler to ignore SIGINT directly */
	signal(SIGINT, sigint_handler);
	while (1)
	{
	/*### READ INPUT ###*/
		_puts("$ ");
		nread = getline(&input, &len, stdin);
		if (nread == -1)
		{
			_puts("\n");
			break;
		}
		if (input[nread - 1] == '\n')
			input[nread - 1] = '\0';
	/*### HANDLE EXIT BUILT-IN ###*/
		if (_strncmp(input, "exit", 4) == 0)
			break;
	/*### HANDLE ENV BUILT-IN  ###*/
		if (_strncmp(input, "env", 4) == 0)
		{
			_printenv();
			continue;
		}
	/*### TOKENIZE INPUT ###*/
		tokens = tokenize_input(input);
		if (tokens == NULL)
			continue;
	/*### CHECK IF COMMAND FOUND IN PATH ###*/
		is_found = command_found(tokens[0], &full_path);
		if (is_found == 0)
		{
			_puts("command not found\n");
			free_tokens(tokens);
			continue;
		}
		free(tokens[0]);
		tokens[0] = _strdup(full_path);
		free(full_path);
	/*### EXECUTE COMMAND ###*/
		pid = fork();
		if (pid == -1)
			perror("fork");
		if (pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
				perror("execve");
		}
		else
			wait(&status);
		free_tokens(tokens);
	}
	free(input);
	return (0);
}
