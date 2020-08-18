#include "shell.h"
/**
 * _getenv - 
 * 
 * 
 */
char *_getenv(char *path)
{
    char *token = NULL, **tok = NULL;
	int i = 0, j = 0;
    (void)path;
    printf("antes");
    tok = malloc(sizeof(char *) * 1024);
    while (environ[j])
    {
        token = strtok(environ[j], "=");
        while (token != NULL)
        {
            tok[i] = token;
            token = strtok(NULL, "=");
            i++;
        }
        j++;
    }
    tok[i] = NULL;
    i = 0;
	while(tok[i])
    {
        if(_strcmp(tok[i],path) == 0)
            return(tok[i+1]);
        i++;
    }

    return(NULL);
}
