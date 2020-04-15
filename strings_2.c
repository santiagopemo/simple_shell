#include "shell.h"

/**
 * _strcmpr - compare 2 strings, lenght also
 * @s1: first string
 * @s2: second string
 * Return: 0 if match
 */
int _strcmpr(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
/**
 * str_concat - function that concatenates two strings
 * @s1: string1
 * @s2: string2
 * Return: pointer to string
 */
char *str_concat(char *s1, char *s2)
{
	char *a;
	unsigned int size1, size2, i;

	size1 = size2 = 0;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (*(s1 + size1))
		size1++;
	while (*(s2 + size2))
		size2++;
	size2++;
	a = malloc(sizeof(char) * (size1 + size2 + 1));
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size1; i++)
		*(a + i) = *(s1 + i);
	for (i = 0; i < size2; i++)
		*(a + (i + size1)) = *(s2 + i);
	*(a + (size1 + size2)) = '\0';
	return (a);
}

/**
 * _strstr - locates sub string
 * @haystack: input one
 * @needle: input two
 * Return: sub string
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *one = haystack;
		char *two = needle;

		while (*one == *two && *two != '\0')
		{
			one++;
			two++;
		}

		if (*two == '\0')
			return (haystack);
	}
	return (NULL);
}
