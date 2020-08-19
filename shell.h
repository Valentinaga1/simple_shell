#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
	extern char **environ;

void no_interactive(char **argv);
char **tokenize(char *str);
void execute(char **tokens, char **argv);
void printenvironment(void);
void _putchar(char *str);
char *_getenv(char *path);
void handler(int sign);
void prompt(char **argv);
void print_no_interactive(char *buffer, char *argv);
void print_interactive(char **tokens);
void print_interactive2(char **tokens, char **argv);

char *_strdup(char *str);
char *str_cat(char *str1, char slash, char *str2);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

#endif
