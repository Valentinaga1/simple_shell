#include "shell.h"
/**
 * envprint - Function to prints the environment.
 * @void: No arguments need it.
 * Return: Void.
 */
void printenvironment(void)
{
	char *jump = "\n";
	int i = 0;
	while (environ[i] != NULL)
	{
		_putchar(environ[i]);
		_putchar(jump);
		i++;
	}
	exit(EXIT_SUCCESS);
}