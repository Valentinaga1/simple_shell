#include "shell.h"
/**
 * main - 
 * 
 */
int main() 
{
	char  **tokens = NULL, *buffer = NULL;
	size_t size;
	int c;

	while(1)
	{
		if((write(1, "$ ", 2)) == -1)
		{
			perror("Error");
			return (1);
		}
		c = getline(&buffer, &size, stdin);
		if (c == EOF)
		{
			_putchar("\n");
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
	}
	free(buffer);
	return 0;
}