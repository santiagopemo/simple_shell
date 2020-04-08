#include "shell.h"

/**
 * built_in - Checks for builtins
 * @args: Arguments passed from prompt
 * Return: 1 if builtins exist, 0 if they don't
 */
int built_in(char **args)
{
	int i;
	/*struct*/ list[] = {
			{"exit", exit},
			{"env", env},
			{NULL, NULL}
	};

	for (i = 0; list[i]./*argument for sruct */ != NULL; i++)
	{
		if (_strcmp(list[i]./*argument for struct */, args[0]) == 0)
			return (1);
	}
	return (0);
}
/**
 * check_for_builtins - Checks for builtins
 * @args: Arguments passed from prompt
 * @line: Buffer with line of input from user
 * @env: Environment
 * Return: 1 if builtins exist, 0 if they don't
 */
int check_for_builtins(char **args, char *line, char **env)
{
	builtins_t list[] = {
			{"exit", exit_shell},
			{"env", env_shell},
			{NULL, NULL}
	};
	int i;

	for (i = 0; list[i].arg != NULL; i++)
	{
		if (_strcmp(list[i].arg, args[0]) == 0)
		{
			list[i].builtin(args, line, env);
			return (1);
		}
	}
	return (0);
}
