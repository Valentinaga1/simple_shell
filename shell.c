#include "shell.h"
/**
 * handler- Function to handle signals.
 * @sign: Void.
 * Return: Void.
 */
void handler(int sign)
{
	(void) sign;
	write(STDOUT_FILENO, "\n$ ", 4);
}
/**
 * main - 
 * 
 */
int main(int argc, char **argv) 
{
	char  **tokens = NULL, *buffer = NULL;
	size_t size;
	int c;
	(void) argc;
	
	c = getline(&buffer, &size, stdin);

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	else if(isatty(STDOUT_FILENO))
		print_no_interactive(buffer, argv[0]);
	signal(SIGINT, handler);

	while(1)
	{
		c = getline(&buffer, &size, stdin);
		if (c == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if((_strcmp(buffer,"exit\n") == 0))
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (c == -1)
		{
			perror("Error");
			free(buffer);
			return(1);
		}
			if(buffer == NULL)
				return (1);
			tokens = tokenize(buffer);
			execute(tokens, argv);
			free(tokens);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2);
	}
	free(buffer);
	return 0;
}
