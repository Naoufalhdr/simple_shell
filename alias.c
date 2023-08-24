#include "shell.h"

/**
 * extract_alias - extracts alias name and value from current position.
 * @current: a pointer to the current position in the input line.
 * @name: is the  buffer to store the extracted alias name.
 * @value: buffer to store the extracted alias value.
 * @data: Pointer to the aliases info data structure.
 *
 * Return: a pointer to the next position after the extracted alias.
 */
char *extract_alias(char *current, char *name, char *value)
{
	char *name_start, *value_start;

	/* Extract name & skip spaces */
	while (*current == ' ')
		current++; /* Skip spaces */
	name_start = current;
	while (*current != '=' && *current)
		current++;
	_strncpy(name, name_start, current - name_start);
	name[current - name_start] = '\0';

	/* Extract value */
	current++; /* skip '=' */
	if (*current == '\'')
	{
		current++;
		value_start = current;
		while (*current != '\'' && *current)
			current++;
		_strncpy(value, value_start, current - value_start);
		value[current - value_start] = '\0';
		current++; /* skip closing quote */
	}
	else
	{
		value_start = current;
		while (*current != ' ' && *current)
			current++;
		_strncpy(value, value_start, current - value_start);
		value[current - value_start] = '\0';
	}

	return (current);
}

/**
 * display_all_aliases - displays all defined aliases.
 * @data: Pointer to the aliases info data structure.
 *
 */
void display_all_aliases(shell_data_t *data)
{
	int i;

	for (i = 0; i < data->num_aliases; i++)
		printf("%s='%s'\n", data->aliases[i].name, data->aliases[i].value);
}

/**
 * set_alias - sets or updates an alias with the given name and value.
 * @name: is the alias name.
 * @value: is the alias value.
 * @data: Pointer to the aliases info data structure.
 *
 */
void set_alias(char *name, char *value, shell_data_t *data)
{
	int i, found = 0;

	for (i = 0; i < data->num_aliases; i++)
	{
		if (_strcmp(data->aliases[i].name, name) == 0)
		{
			_strncpy(data->aliases[i].value, value, MAX_ALIAS_LENGTH);
			found = 1;
			break;
		}
	}

	if (!found)
	{
		if (data->num_aliases < MAX_ALIASES)
		{
			_strncpy(data->aliases[data->num_aliases].name, name, MAX_ALIAS_LENGTH);
			_strncpy(data->aliases[data->num_aliases].value, value, MAX_ALIAS_LENGTH);
			data->num_aliases++;
		}
		else
			fprintf(stderr, "alias: maximum number of aliases reached\n");
	}
}

/**
 * _myalias - handles the 'alias' command by extracting and setting aliases
 * @line: the input line containing the 'alias' command and aliases to define
 * @data: Pointer to the aliases info data structure.
 *
 */
void _myalias(char *line, shell_data_t *data)
{
	char *current = line + 6;
	char name[MAX_ALIAS_LENGTH];
	char value[MAX_ALIAS_LENGTH];

	/* If only 'alias' command is issued, display existing aliases */
	if (_strlen(line) == 5)
	{
		display_all_aliases(data);
		return;
	}

	while (*current)
	{
		current = extract_alias(current, name, value);
		set_alias(name, value, data);
	}
}

/**
 * replace_alias_with_command - replaces an alias with its corresponding value
 * @cmd: the command to potentially replace with an alias value
 * @data: Pointer to the aliases info data structure.
 *
 * Return: the command with aliases replaced;
 *         or the original command if no alias found.
 */
char *replace_alias_with_command(char *cmd, shell_data_t *data)
{
	int i;

	for (i = 0; i < data->num_aliases; i++)
	{
		if (_strcmp(data->aliases[i].name, cmd) == 0)
			return (data->aliases[i].value);
	}
	return (cmd);
}
