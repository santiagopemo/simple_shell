#include "shell.h"

/**
 * is_comand - function that checks if a string is a valid command
 * @cmd: the command
 * @vars: strcut with the program variables
 *
 * Return: 1 if it is a valid command 0 if not
 */
int is_comand(char *cmd, vars_t *vars)
{
	struct stat st;

	if (is_path(vars) == 1)
	{
		if (check_command(cmd, vars))
			return (1);
		my_exit(vars);
	}
	cmd = whit_path(vars);
	if (cmd != NULL)
	{
		if (stat(cmd, &st) == 0)
		{
			if (access(cmd, X_OK) == 0)
			{
				if (execute_command(cmd, vars))
				{
					free(cmd);
					return (1);
				}
				free(cmd);
				my_exit(vars);
			}
			else
			{
				print_command_error(vars, ": Permission denied\n");
				vars->status = 126;
				free(cmd);
				return (0);
			}
		}
	}
	print_command_error(vars, ": not found\n");
	vars->status = 127;
	free(cmd);
	return (0);
}
/**
 * check_command - check the commands that are already with the path
 * @cmd: the command
 * @vars:  strcut with the program variables
 *
 * Return: 1 if it is a valid command 0 if not
 */
int check_command(char *cmd, vars_t *vars)
{
	struct stat st;

	if (stat(cmd, &st) == 0)
	{
		if (access(cmd, X_OK) == 0)
		{
			if (execute_command(cmd, vars))
			{
				return (1);
			}
			return (0);
		}
		print_command_error(vars, ": Permission denied\n");
		vars->status = 126;
		return (1);
	}
	print_command_error(vars, ": not found\n");
	vars->status = 127;
	return (1);
}
/**
 * is_path - function that checks if a commands is with the path
 * @vars: strcut with the program variables
 *
 * Return: 1 if is whit the path 0 if not
 */
int is_path(vars_t *vars)
{
	int i;

	for (i = 0; vars->commands[0][i]; i++)
	{
		if (vars->commands[0][i] == '/')
			return (1);
	}
	return (0);
}
/**
 * check_current_dir - check if the path has the current directory
 * @path: the path
 *
 * Return: the number of the token where is the current directory
 */
int check_current_dir(char *path)
{
	int i, n_token = 0;

	if (path == NULL)
		return (-1);
	if (*path == ':')
		return (0);

	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			n_token++;
			if (path[i + 1] == ':')
				return (n_token);
		}
	}
	return (-1);
}
/**
 * whit_path - fucntion that checks if the command is in the path like
 * "which" function
 * @vars: strcut with the program variables
 *
 * Return: pointer to the command whith the path
 */
char *whit_path(vars_t *vars)
{
	char *path, *cmd1, *cmd2, **tokens;
	int i, k, cd;
	struct stat st;

	path = _getenvlist("PATH", vars->env_head);
	if (path == NULL || _strcmpr(path, "") == 0)
		return (NULL);
	path = _strdup(path);
	if (path == NULL)
		return (NULL);
	cd = check_current_dir(path);
	tokens = split_string(path, ":");
	if (tokens == NULL)
	{
		free(path);
		vars->status = 127;
		my_exit(vars);
	}
	for (i = 0, k = 0; tokens[k]; i++)
	{
		if (cd != i)
		{
			cmd1 = str_concat(tokens[k], "/");
			cmd2 = str_concat(cmd1, vars->commands[0]);
			free(cmd1);
			k++;
		}
		else
			cmd2 = _strdup(vars->commands[0]);
		if (stat(cmd2, &st) == 0)
		{
			free_argv(tokens), free(path);
			return (cmd2);
		}
		free(cmd2);
	}
	free(path), free_argv(tokens);
	return (NULL);
}
