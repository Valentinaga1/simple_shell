#include "shell.h"
/**
 * exit_f - function to exit of the program.
 * @tokens: Array of arguments.
 * Return: Void.
 */
void exit_f(char **tokens)
{
	if (tokens[1] == NULL)
	{
		free(tokens);
		exit(0);
	}
	else
	{
		free(tokens);
		exit(0);
	}
}
