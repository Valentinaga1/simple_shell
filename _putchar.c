#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @str: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void _putchar(char *str)
{
	int len;

	len = _strlen(str);
	write(1, str, len);
}
