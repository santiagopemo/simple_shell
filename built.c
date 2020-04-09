#include "shell.h"
/**
 * env_shell - Prints shell environment
 * @args: Arguments split from cmdline
 * @line: User input buffer
 * @env: Environment
 */
void env_shell(char **args, char *line, char **env) /*Acomodar de acuerdo a la struct de Santiago */
{
	int size, i = 0;

	while (env[i] != NULL)
	{
		size = _strlen(env[i]);
		write(1, env[i], size);
		write(1, "\n", 1);
		i++;
	}
	(void)args;
	(void)line;
}
/**
 * exit_shell - This will run the builtin exit
 * @line: Line buffer of user input
 * @args: Arguments from user
 * @env: Environment
 * Return: Void
 */
void exit_shell(char **args, char *line, char **env) /*Acomodar de acuerdo a la struct de Santiago */
{
	free(args);
	free(line);
	(void)env;
	exit(0);
}
