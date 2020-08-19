#include "shell.h"
/**
 * printenvironment - Function to prints the environment.
 * @env: Env variable.
 * Return: Void.
 */
void printenvironment(char **env)
{
	int i = 0;

	while (env[i])
	{
		_putchar(env[i]);
		_putchar("\n");
		i++;
	}
}
