#include "shell.h"

/**
 * init_vars - initialize a structure of type vars_t
 *
 * Return: a vars_t structure
 */
vars_t init_vars(void)
{
	vars_t vars;

	vars.av = NULL;
	vars.l_buffer = NULL;
	vars.len_buffer = 0;
	vars.status = 0;
	vars.commands = NULL;
	vars.num_ins = 0;
	vars.env = NULL;
	vars.commands_tok = NULL;
	vars.env_head = NULL;
	return (vars);
}
/**
 * main - entry point for simple shell
 * @argc: number of arguments
 * @argv: array with strings of arguments
 * @env: array with enviromental variables
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *env[])
{
	vars_t vars;
	void (*builtin)(vars_t *);
	int i;

	UNUSED(argc);
	vars = init_vars();
	vars.av = argv, vars.env = argvdup(env);
	vars.env_head = env_to_list(vars.env);
	signal(SIGINT, myhandle);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_dprintf(STDOUT_FILENO, "$ ");
		if (_getline(&(vars.l_buffer), &(vars.len_buffer), stdin) == -1)
			break;
		vars.num_ins++;
		vars.commands_tok = split_string(vars.l_buffer, ";");
		if (vars.commands_tok != NULL)
		{
			for (i = 0; vars.commands_tok[i]; i++)
			{
				vars.commands = split_string(vars.commands_tok[i], " \n\t\r");
				if (vars.commands != NULL)
				{
					builtin = get_builtin(&vars);
					if (builtin != NULL)
						builtin(&vars);
					else
						is_comand(vars.commands[0], &vars);
					free_argv(vars.commands);
				}
			}
			free_argv(vars.commands_tok);
		}
		free(vars.l_buffer), vars.l_buffer = NULL;
	}
	if (isatty(STDIN_FILENO))
		_dprintf(STDOUT_FILENO, "\n");
	free_list(vars.env_head), free(vars.l_buffer), free_argv(vars.env);
	return (vars.status);
}
/**
 * myhandle - fucntion that handles the signal Ctr+Ctr
 * @mysignal: signal
 *
 * Return: nothing
 */
void myhandle(int mysignal)
{
	UNUSED(mysignal);

	_dprintf(STDOUT_FILENO, "\n$ ");
}
