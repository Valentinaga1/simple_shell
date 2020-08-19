#include "shell.h"
/**
 * printenvironment - Function to prints the environment.
 * @void: No arguments need it.
 * Return: Void.
 */
void printenvironment(void)
{
	int i;
	for (i = 0; environ[i]; i++)
	{
		_putchar(environ[i]);
		_putchar("\n");
	}
}
