#include "shell.h"

/**
 * _cd - builtin cd
 * @vars: struct with the program variables
 * Return: nothing
 */
void _cd(vars_t *vars)
{
	char cwd[1024], nextpwd[1024], *path;

	getcwd(cwd, 1024);
	if (vars->commands[1] == NULL)
	{
		path = _getenvlist("HOME", vars->env_head);
		if (path == NULL)
			path = _strdup(cwd);
		else
			path = _strdup(path);
	}
	else if (vars->commands[1][0] == 45 && vars->commands[1][1] != '\0')
	{
		_dprintf(STDERR_FILENO, "%s: %d: cd: Illegal option -", vars->av[0]
				, vars->num_ins);
		_dputchar(STDERR_FILENO, vars->commands[1][1]);
		_dputchar(STDERR_FILENO, '\n');
		vars->status = 2;
		return;
	}
	else
		path = cd_check(cwd, vars);

	if (path == NULL || chdir(path) == -1)
	{
		vars->status = 2;
		_dprintf(STDERR_FILENO, "%s: %d: cd: can't cd to %s\n", vars->av[0]
				, vars->num_ins, vars->commands[1]);
	}
	else
	{
		getcwd(nextpwd, 1024);
		cd_setenv("PWD", nextpwd, vars);
		cd_setenv("OLDPWD", cwd, vars);
	}
	free(path);
}
/**
 * cd_setenv - builtin cd
 * @name: name or the variables
 * @value: value of the variable
 * @vars: struct with the program variables
 * Return: nothing
 */
void cd_setenv(char *name, char *value, vars_t *vars)
{
	env_t *temp;

	temp = vars->env_head;
	while (temp)
	{
		if (_strcmpr(temp->name, name) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			return;
		}
		temp = temp->next;
	}
	if (add_node_end(&(vars->env_head), name, value) != NULL)
	{
		return;
	}
	perror("Fatal error creating the list");
}
/**
 * cd_check - check cd opotion
 * @cwd: current working dirctory
 * @vars: struct with the program variables
 * Return: pointer to path
 */
char *cd_check(char *cwd, vars_t *vars)
{
	char *path, *temp;


	if (_strcmpr(vars->commands[1], "-") == 0)
	{
		path = _getenvlist("OLDPWD", vars->env_head);

		if (path != NULL)
			path = _strdup(path);
		else
		{
			cd_setenv("OLDPWD", cwd, vars);
			path = _strdup(_getenvlist("OLDPWD", vars->env_head));
		}
		_dprintf(STDOUT_FILENO, "%s\n", path);
	}
	else if (vars->commands[1][0] == '/')
		path = _strdup(vars->commands[1]);
	else
	{
		temp = str_concat(cwd, "/");
		path = str_concat(temp, vars->commands[1]);
		free(temp);
	}
	return (path);
}
