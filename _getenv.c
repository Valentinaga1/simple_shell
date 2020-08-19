#include "shell.h"
/**
 *_getenv - Function to get the environment variable.
 * @path: Environment variable to looking for.
 * Return: Null.
 */
char *_getenv(char *path)
{
	char *token = NULL, **tok = NULL;
	int i = 0, j = 0;

	tok = malloc(sizeof(char *) * 1024);
	if (tok == NULL)
		return (NULL);
	while (environ[j])
	{
		token = strtok(environ[j], "=");
		while (token != NULL)
		{
			tok[i] = token;
			token = strtok(NULL, "=");
			i++;
		}
		j++;
	}
	tok[i] = NULL;
	i = 0;
	while (tok[i])
	{
		if (_strcmp(tok[i], path) == 0)
			return (tok[i + 1]);
		i++;
	}
	return (NULL);
}
