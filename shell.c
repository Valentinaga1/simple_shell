#include "shell.h"
/**
 * handler- Function to handle signals.
 * @sign: ctrl + c signal.
 * Return: Void.
 */
void handler(int sign)
{
	(void) sign;
	write(STDOUT_FILENO, "\n$ ", 4);
}
/**
 * prompt - prompt function of shell.
 * @argc: number arguments of main.
 * @argv: Array of arguments of main.
 * @env: environment variables.
 * Return: Void.
 */
int main(int argc, char **argv, char **env)
{
	char  **tokens = NULL, *buffer = NULL;
	size_t size;
	int c, st_ex = 0;
	(void)argc;
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	signal(SIGINT, handler);
	while (1)
	{

		c = getline(&buffer, &size, stdin);
		if (c == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (c == 0)
		{
			free(buffer);
			exit(st_ex);
		}
		if (c)
		if (c == -1)

			if (buffer == NULL)
				exit(2);
			tokens = tokenize(buffer);
			if ((_strcmp(tokens[0], "exit\n") == 0))
		{
			exit_f(tokens);
		}
			execute(tokens, argv, env, &st_ex);
			free(tokens);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	return (0);
}
