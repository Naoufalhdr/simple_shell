#ifndef SHELL_H
#define SHELL_H

#define MAX_LENGHT 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define MAX 100
#define BUFFER_SIZE 8192
#define MAX_ALIASES 50
#define MAX_ALIAS_LENGTH 256

/**
 * struct Alias - represents an alias in the shell.
 * @name: the name of the alias.
 * @value: the value associated with the alias.
 *
 */
typedef struct
{
	char name[MAX_ALIAS_LENGTH];
	char value[MAX_ALIAS_LENGTH];
} Alias;

/**
 * struct shell_data - holds data related to the shell.
 * @aliases: an array of Alias structures representing user-defined aliases.
 * @num_aliases: the number of currently stored aliases in the 'aliases' array.
 *
 */
typedef struct shell_data
{
	Alias aliases[MAX_ALIASES];
	int num_aliases;
} shell_data_t;

extern char **environ;
Alias aliases[MAX_ALIASES];

/* funtions prototypes */
char *found_command(char *command);
size_t _read_input(void);
ssize_t _getline(char **lineptr, size_t *n);


/* string functions prototypes */
char *_strdup(const char *src);
char *_strchr(const char *s, int c);
size_t _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strcat(char *dest, const char *src);
int _atoi(char *s);
int is_all_digits(char *s);

/* memory functions protoypes */
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* environment functions prototypes */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void _printenv(void);

/* built-in functions */
void _myexit(char *input);
void _mycd(char *line);
void _mysetenv(char *line);
void _myunsetenv(char *line);
int builtint_command(char *line, shell_data_t *data);

/* alias functions */
char *extract_alias(char *current, char *name, char *value);
void display_all_aliases(shell_data_t *data);
void set_alias(char *name, char *value, shell_data_t *data);
void _myalias(char *line, shell_data_t *data);
char *replace_alias_with_command(char *cmd, shell_data_t *data);



#endif /* SHELL_H  */

