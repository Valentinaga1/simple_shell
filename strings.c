#include "shell.h"
/**
 * _strdup - duplicates a array in a new allocated memory
 * @str: array
 *
 * Return: NULL or the array.
*/
char *_strdup(char *str)
{
	char *array = NULL;
	unsigned int i, c = 0;

	if (str == 0)
		return (0);
	while (str[c] != 0)
		c++;
	c++;
	array = (char *)malloc(sizeof(char) * c);
	if (array == 0)
		return (array);
	for (i = 0; i < c; i++)
		array[i] = str[i];
	array[i] = 0;
	return (array);
}
/**
 * str_cat - Function to concat 3 strings
 * @str1:
 * @slash:
 * @str1:
 *
 * Return: NULL or the array.
*/
char * str_cat(char *str1, char slash, char *str2)
{
	char *concat;
	int i,j;

	concat = malloc(sizeof(char) * strlen(str1) + strlen(str2) + 2);

	if(concat == NULL)
		return (NULL);
	
	i = 0;
	while (str1[i] != '\0')
	{
		concat[i] = str1[i];
		i++;
	}
	concat[i] = slash;
	i++;
	j = 0;
		while (str2[j] != '\0')
	{
		concat[i] = str2[j];
		j++;
		i++;
	}
	concat[i] = '\0';
	return (concat);
}
/**
 * _strcmp - compares two strings.
 * @s1: string 1
 * @s2: cstring 2
 * Return: a number positive, negative or zero.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
		if (*s1 > *s2)
		{
			return (*s1 - *s2);
		}
		if (*s1 < *s2)
		{
			return (*s1 - *s2);
		}
	}
	return (0);
}