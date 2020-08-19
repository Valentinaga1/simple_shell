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
 * no_interactive - Not interactive mode.
 * @argv: Array of arguments of main
 * Return: Void.
 */
void no_interactive(char **argv)
{
	char *buffer = NULL;
	size_t size;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	else if (isatty(STDOUT_FILENO))
	{
		getline(&buffer, &size, stdin);
		print_no_interactive(buffer, argv[0]);
	}
	signal(SIGINT, handler);
}
/**
 * prompt - prompt function of shell.
 * @argv: Array of arguments of main.
 * @env: Environment variable.
 * Return: Void.
 */
void prompt(char **argv, char **env)
{
	char  **tokens = NULL, *buffer = NULL;
	size_t size;
	int c;

	no_interactive(argv);

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
		if ((_strcmp(buffer, "exit\n") == 0))
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (c == -1)
		{
			perror("Error");
			free(buffer);
			exit(2);
		}
			if (buffer == NULL)
				exit(2);
			tokens = tokenize(buffer);
			execute(tokens, argv, env);
			free(tokens);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2);
	}
	free(buffer);
	exit(EXIT_SUCCESS);
}
/**
 * main - Main function of shell.
 * @argc: Number of arguments passed.
 * @argv: Array of arguments of main.
 * @env: Environment variable.
 * Return: Zero.
 */
int main(int argc, char **argv, char **env)
{
	(void) argc;
	prompt(argv, env);
	return (0);
}
