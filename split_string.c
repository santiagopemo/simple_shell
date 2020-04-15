#include "shell.h"

/**
 * split_string - function that split a string according to a delimiter
 * @str: string to split
 * @delimiter: string with delimiters
 *
 * Return: double pointer to array of strings
 */
char **split_string(char *str, char *delimiter)
{
	char *token, **array, *temp;
	int i = 0, wc;

	wc = countWords(str, delimiter);
	if (str == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	if (wc == 0)
		return (NULL);
	array = malloc(sizeof(char *) * (wc + 1));
	if (array == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	temp = _strdup(str);
	token = _strtok(str, delimiter);
	while (token != NULL)
	{
		array[i] = token;
		token = _strtok(NULL, delimiter);
		i++;
	}
	array[i] = NULL;
	free(token);
	free(temp);
	return (array);
}
/**
 * countWords - function tha count the number of words in a string
 * @str: string
 * @delimiter: delimiter
 *
 * Return: number of words
 */
unsigned int countWords(char *str, char *delimiter)
{
	int state = 0, i;
	unsigned int wc = 0;

	while (*str)
	{
		for (i = 0; delimiter[i]; i++)
		{
			if (*str == delimiter[i])
				break;

		}
		if (*str == delimiter[i])
			state = 0;
		else if (state == 0)
		{
			state = 1;
			++wc;
		}
		++str;
	}

	return (wc);
}
