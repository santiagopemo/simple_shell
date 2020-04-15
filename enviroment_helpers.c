#include "shell.h"

/**
 * free_env - function that frees a array of strings
 * @env: array of strings
 * Return: nothing
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		free(env[i]);
	free(env);
}
/**
 * argvdup - function that duplicates a array of strings
 * @argv: array of strings
 * Return: doble pointer to array of strings
 */
char **argvdup(char **argv)
{
	int i, l;
	char **dup, **res;

	for (i = 0; argv[i]; i++)
		continue;
	if (i == 0)
		return (NULL);
	dup = malloc(sizeof(char *) * (i + 1));
	if (dup == NULL)
	{
		perror("Fatal error");
		return (NULL);
	}
	for (l = 0; l < i; l++)
		dup[l] = argv[l];
	dup[l] = NULL;
	res = dup;
	return (res);
}
/**
 * free_argv - function that frees a array of strings
 * @argv: array of strings
 * Return: nothing
 */
void free_argv(char **argv)
{
	free(argv);
}
/**
 * _getenv - function to get a enviromental variable
 * @env: name of variable
 * @envi: array of enviromental variables
 * Return: pointer to enviromental variable
 */
char *_getenv(char *env, char **envi)
{
	int i = 0;
	int j = 0;
	char *temp = NULL;
	char *res = NULL;

	while (envi[i] != NULL)
	{
		if (_strcmp(envi[i], env) == 0)
			temp = envi[i];
		i++;
	}

	while (temp[j] != '\0')
	{
		if (_strcmp(temp, env) == 0)
			res = _strstr(temp, "=");
		j++;
	}
	return (res + 1);
}
/**
 * get_path - fucntion that returns the PATH variable
 * @env: array with enviromentals variables
 * Return: pointer to the PATH
 */
char *get_path(char **env)
{
	char *path = "PATH=";
	unsigned int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	return (env[i]);

}
