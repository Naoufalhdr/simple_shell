#include "shell.h"

/**
 * free_tokens - function that free the tokenized string
 * @tokens: tokens
 */
void free_tokens(char **tokens)
{
	int j;

	for (j = 0; tokens[j] != NULL; j++)
		free(tokens[j]);
	free(tokens);
}

/**
 * check_blank - check if a string is made of only blank spaces
 * @input: the input
 * Return: return 0 if its blank or 1 if its not
*/
int check_blank(char *input)
{
	int i = 0;

	while (input[i] != '\n')
	{
		if (input[i] == ' ' || input[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}


/**
 * handler_function - handler function
 * @i: i
 */
void handler_function(int i __attribute__((unused)))
{
	_puts("\n$ ", 1);
}
