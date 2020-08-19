  #include "shell.h"
/**
 * execute - Function to execute a process.
 * @tokens: Tokenized string.
 * @argv: Array of arguments of main.
 * @env: Environment variable.
 * Return: void.
 */
void execute(char **tokens, char **argv, char **env)
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
			if (((_strcmp(tokens[0], "env") == 0) ||
			(_strcmp(tokens[0], "printenv") == 0)) && (tokens[1] == NULL))
				printenvironment(env);
			path = _getenv("PATH");
			if (path == NULL)
				exit(EXIT_FAILURE);
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
	} else
		wait(&status);
}
