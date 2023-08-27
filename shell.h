#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* write to output functions */
void _putchar(char c);
void _puts(char *s);
void sigint_handler(int signum);

/* string functions */
int _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *src);
int _strncmp(const char *str1, const char *str2, size_t n);

/* parser functions */
char **tokenize_input(char *input);
void  free_tokens(char **tokens);
int command_found(const char *command, char **command_fullpath);


/* env functions */
char *_getenv(const char *name);
void _printenv(void);

#endif /* SHELL_ H */
