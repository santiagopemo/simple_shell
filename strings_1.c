#include "shell.h"

/**
 * _strlen - return the length of string
 * @s: string pointer
 * Return: nothing
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcpy - copy the string
 * @dest: destination
 * @src: string
 * Return: char
 */
char *_strcpy(char *dest, char *src)
{
	int i, j;

	for (i = 0; *(src + i); i++)
		continue;
	for (j = 0; j <= i; j++)
	{
		*(dest + j) = *(src + j);
	}
	return (dest);
}

/**
 * _strdup - function that returns a pointer to a newly allocated space
 * @str: string
 * Return: pointer to string
 */
char *_strdup(char *str)
{
	char *a;
	unsigned int size;

	size = 0;
	if (str)
	{
		while (*(str + size))
			size++;
		size++;
		a = malloc(sizeof(char) * size);
		if (a)
		{
			while (size--)
			{
				*(a + size) = *(str + size);
			}
			return (a);
		}
	}
	return (NULL);
}
/**
 * _strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: nothing
 */
char *_strcat(char *dest, char *src)
{
	int l_dest, l_src;

	l_dest = 0;
	l_src = 0;
	while (*(dest + l_dest))
		l_dest++;
	while (*(src + l_src))
	{
		*(dest + (l_dest + l_src)) = (*(src + l_src));
		l_src++;
	}
	return (dest);
}

/**
 * _strcmp - compare 2 strings
 * @s1: first string
 * @s2: second string
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
