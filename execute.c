#include "shell.h"
/**
 * pro_execute - Function to fork a process.
 * @tokens: Tokenized string.
 * @argv: Array of arguments of main.
 * @env: variables environ¿ments of main.
 * Return: void.
 */
void pro_execute(char **tokens, char **env, char **argv)
{
	char *path, *tok, *concat;

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
		{
			perror(argv[0]);
			exit(127);
		}
	}
	if (execve(tokens[0], tokens, NULL) != -1)
		exit(EXIT_SUCCESS);
	if (execve(tokens[0], tokens, NULL) == -1)
	{
		perror(argv[0]);
		exit(127);
	}
}
/**
 * execute - Function to fork a process.
 * @tokens: Tokenized string.
 * @argv: Array of arguments of main.
 * @env: variables environ¿ments of main.
 * @st_ex: exit status.
 * Return: void.
 */
void execute(char **tokens, char **argv, char **env, int *st_ex)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	else if (pid == 0)
	{
		pro_execute(tokens, env, argv);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			*st_ex = WEXITSTATUS(status);
	}
}
