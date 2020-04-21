#include "shell.h"

/**
 * get_builtin - function that returns a function pointer to buildin function
 * @vars: struct with the program variables
 *
 * Return: fucntion pointer to function
 */
void (*get_builtin(vars_t *vars))(vars_t *vars)
{
	unsigned int i = 0;
	builtins_t builtins[] = {
		{"exit", my_exit},
		{"env", printenv},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", _cd},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmpr(vars->commands[0], builtins[i].name) == 0)
			break;
	}
	return (builtins[i].f);
}
/**
 * my_exit - function that exits the program
 * @vars: struct with the program variables
 *
 * Return: nothing
 */
void my_exit(vars_t *vars)
{
	int status;

	if (_strcmpr(vars->commands[0], "exit") == 0)
	{
		if (vars->commands[1] != NULL)
		{
			status = _atoi(vars->commands[1]);
			if (status == -1)
			{
				vars->status = 2;
				print_command_error(vars, ": Illegal number: ");
				_dprintf(STDERR_FILENO, "%s\n", vars->commands[1]);
				return;
			}
			else
				vars->status = status;
		}
	}
	free(vars->l_buffer);
	free_argv(vars->commands_tok);
	free_argv(vars->commands);
	free_list(vars->env_head);
	free_argv(vars->env);
	exit(vars->status);
}
/**
 * printenv - function that prints the enviromental variables
 * @vars: struct with the program variables
 *
 * Return: nothing
 */
void printenv(vars_t *vars)
{
	print_list(vars->env_head);
	vars->status = 0;
}
/**
 * _setenv - function that sets a enviromental variables
 * @vars: struct with the program variables
 *
 * Return: nothing
 */
void _setenv(vars_t *vars)
{
	env_t *temp;

	if (vars->commands[1] != NULL && vars->commands[2] != NULL)
	{
		temp = vars->env_head;
		while (temp)
		{
			if (_strcmpr(temp->name, vars->commands[1]) == 0)
			{
				free(temp->value);
				temp->value = _strdup(vars->commands[2]);
				return;
			}
			temp = temp->next;
		}
		if (add_node_end(&(vars->env_head),
					vars->commands[1], vars->commands[2]) != NULL)
		{
			vars->status = 0;
			return;
		}
		vars->status = 127;
		perror("Fatal error creating the list");
		return;
	}
	print_command_error(vars, ": Incorrect number of arguments\n");
	vars->status = 2;
}
/**
 * _unsetenv - function that unsets a enviromental variables
 * @vars: struct with the program variables
 *
 * Return: nothing
 */
void _unsetenv(vars_t *vars)
{
	if (vars->commands[1] != NULL)
	{
		int index;

		index = get_env_index(vars->env_head, vars->commands[1]);

		if (index != -1)
		{
			if (delete_nodeint_at_index(&(vars->env_head), (unsigned int)index))
			{
				vars->status = 0;
				return;
			}
			print_command_error(vars, NULL);
			vars->status = 127;
			return;
		}
		print_command_error(vars, ": No variable to unset\n");
		vars->status = 2;
		return;
	}
	print_command_error(vars, ": Incorrect number of arguments\n");
	vars->status = 2;
}
