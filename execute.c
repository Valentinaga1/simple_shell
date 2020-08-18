#include "shell.h"
/**
 * execute -
 * 
 * 
 */
void execute(char **tokens, char **argv)
{
	pid_t pid;
	int status, lsn, lsn2;
	char *path, *tok, *concat;
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(0);
	}
	else if (pid == 0)
	{
		if(tokens[0][0] != '/')
		{
			if((_strcmp(tokens[0],"env") == 0) || (_strcmp(tokens[0],"printenv") == 0))
				printenvironment();
			path = _getenv("PATH");	
			tok = strtok(path, ":");
			while (tok != NULL)
			{
				concat = str_cat(tok, '/', tokens[0]);
				if(concat != NULL)
				{
					if (execve(concat, tokens, NULL) != -1)
						exit(EXIT_SUCCESS);
					tok = strtok(NULL, ":");	
				}
			}
			if (execve(concat, tokens, NULL) == -1)
					{
						lsn2 = strlen(tokens[0]);
						write(STDOUT_FILENO, tokens[0], lsn2);
						write(STDOUT_FILENO, ": command not found\n", 21);
						exit(EXIT_FAILURE);
					}
		}
		if (execve(tokens[0], tokens, NULL) != -1)
			exit(EXIT_SUCCESS);
		else if (execve(tokens[0], tokens, NULL) == -1)
		{
			lsn = strlen(argv[0]);
			lsn2 = strlen(tokens[0]);
			write(STDOUT_FILENO, argv[0], lsn);
			write(STDOUT_FILENO,": ", 2);
			write(STDOUT_FILENO, tokens[0], lsn2);
			write(STDOUT_FILENO, ": No such file or directory\n", 29);
			
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
