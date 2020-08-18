#include "shell.h"
/**
 * print_no_interactive - Print error message in non interactive mode.
 * @buffer: Readed string.
 * @argv: Array of arguments of main.
 * Return: void.
 */
void print_no_interactive(char *buffer, char *argv)
{
	char *token;

	token = strtok(buffer, "\n");
	write(STDOUT_FILENO, argv, _strlen(argv));
	write(STDOUT_FILENO, ": 1: ", 5);
	write(STDOUT_FILENO, token, _strlen(token));
	write(STDOUT_FILENO, ": not found\n", 13);

	exit(EXIT_FAILURE);
}
/**
 * print_interactive - Print error message in non interactive mode.
 * @tokens: Tokenized string.
 * Return: void.
 */
void print_interactive(char **tokens)
{
	int lsn2;

	lsn2 = _strlen(tokens[0]);
	write(STDOUT_FILENO, tokens[0], lsn2);
	write(STDOUT_FILENO, ": command not found\n", 21);
	exit(EXIT_FAILURE);
}
/**
 * print_interactive2 - Print error message 2 in non interactive mode.
 * @tokens: Tokenized string.
 * @argv: Array of arguments of main.
 * Return: void.
 */
void print_interactive2(char **tokens, char **argv)
{
	int lsn, lsn2;

	lsn = _strlen(argv[0]);
	lsn2 = _strlen(tokens[0]);
	write(STDOUT_FILENO, argv[0], lsn);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, tokens[0], lsn2);
	write(STDOUT_FILENO, ": No such file or directory\n", 29);

	exit(EXIT_FAILURE);
}
