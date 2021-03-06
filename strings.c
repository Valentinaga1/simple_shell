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
 * @str1: String 1 to concat
 * @slash: Character '/'.
 * @str2: String 2 to concat
 *
 * Return: NULL or the array.
*/
char *str_cat(char *str1, char slash, char *str2)
{
	char *concat;
	int i, j;

	concat = malloc(sizeof(char) * strlen(str1) + strlen(str2) + 2);

	if (concat == NULL)
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
/**
 * _strlen - returns the length of a string.
 * @s: string
 * Return: void
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != 0)
	i++;
	return (i);
}
/**
 * str_concat - concatenates two arrays in a new allocated memory
 * @s1: array #1
 * @s2: array #2
 *
 * Return: NULL or the array.
*/
char *str_concat(char *s1, char *s2)
{
	char *array;
	unsigned int i = 0, c, d, j = 0, n = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	n = i + j + 1;
	array = (char *)malloc(sizeof(char) * n);
	if (array == NULL)
		return (array);
	for (c = 0; c < i; c++)
		array[c] = s1[c];
	for (d = i, c = 0; d < n; d++, c++)
		array[d] = s2[c];
	array[n] = 0;
	return (array);
}
