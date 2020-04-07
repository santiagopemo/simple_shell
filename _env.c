#include "shell.h"

/**
 * _env - gets env of input
 * @env: input
 * Return: env
 */
char *_env(char *env)
{
	int i = 0;
	int j = 0;
	char *temp;
	char *res;

	while(environ[i] != NULL)
	{
		if (_strcmp(environ[i], env) == 0)
			temp = environ[i];
		i++;
	}

	while (temp[j] != '\0')
	{
		if (_str(temp, env) == 0)
			res = _strstr(temp, "/");
		n++;
	}
	return (res);
}
