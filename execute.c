  #include "shell.h"
/**
 * execute - Function to execute a process.
 * @tokens: Tokenized string.
 * @argv: Array of arguments of main.
 * Return: void.
 */
void execute(char **tokens, char **argv)
{
	pid_t pid;
	int status;
	char *path, *tok, *concat;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(0);
	}
	else if (pid == 0)
	{
		if (tokens[0][0] != '/')
		{
			if ((_strcmp(tokens[0], "env") == 0) ||
			(_strcmp(tokens[0], "printenv") == 0))
				printenvironment();
			path = _getenv("PATH");
			tok = strtok(path, ":");
			while (tok != NULL)
			{
				concat = str_cat(tok, '/', tokens[0]);
				if (concat != NULL)
				{
					if (execve(concat, tokens, NULL) != -1)
						exit(EXIT_SUCCESS);
					tok = strtok(NULL, ":");
				}
			}
			if (execve(concat, tokens, NULL) == -1)
				print_interactive(tokens);
		}
		if (execve(tokens[0], tokens, NULL) != -1)
			exit(EXIT_SUCCESS);
		else if (execve(tokens[0], tokens, NULL) == -1)
			print_interactive2(tokens, argv);
	}
	else
		wait(&status);
}
