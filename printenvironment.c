#include "shell.h"
/**
 * printenvironment - Function to prints the environment.
 * @void: No arguments need it.
 * Return: Void.
 */
void printenvironment(void)
{
	int i = 0;

	while (environ[i])
	{
		_putchar(environ[i]);
		_putchar("\n");
		i++;
	}
}
