#include "shell.h"
/**
 * tokenize - Extract tokens from strings
 * @str: String to be parser.
 * Return: Tokenized string.
 */
char **tokenize(char *str)
{
	char *token = NULL, **tok = NULL;
	int i;

	tok = malloc(sizeof(char *) * 1024);
	if (tok == NULL)
		exit(0);
	token = strtok(str, " \n");
	i = 0;
	while (token != NULL)
	{
		tok[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	tok[i] = NULL;
	return (tok);
}
