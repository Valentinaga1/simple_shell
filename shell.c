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
int main() 
{
	char  **tokens = NULL, *buffer = NULL;
	size_t size;
	int c;
			
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
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
			execute(tokens);
			free(tokens);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2);
	}
	free(buffer);
	return 0;
}