#include "shell.h"
/**
 * execute -
 * 
 * 
 */
void execute(char **tokens)
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
		if(tokens[0][0] != '/')
		{
			if((_strcmp(tokens[0],"env") == 0) || (_strcmp(tokens[0],"printenv") == 0))
				printenvironment();
			path = getenv("PATH");	
			tok = strtok(path, ":");
			while (tok != NULL)
			{
				concat = str_cat(tok, '/', tokens[0]);
				if(concat != NULL)
				{
					if (execve(concat, tokens, NULL) != -1)
						break;
					tok = strtok(NULL, ":");
				}
			}
		}
		else
		{
			if (execve(tokens[0], tokens, NULL) == -1)
				perror("Error:");
		}
	}
	else
		wait(&status);
}
