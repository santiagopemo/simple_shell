#include "shell.h"

/**
 * _getenvlist - function to get a enviromental variable from a linked list
 * @name: name of variable
 * @head: head to linked list
 *
 * Return: pointer to enviromental variable value
 */
char *_getenvlist(char *name, env_t *head)
{
	if (name == NULL)
		return (NULL);
	while (head)
	{
		if (_strcmpr(head->name, name) == 0)
			return (head->value);
		head = head->next;
	}
	return (NULL);
}
/**
 * execute_command - function that execute a command
 * @command: string with the command
 * @vars: strcut with the program variables
 *
 * Return: 1 if the command was executed 0 if no
 *
 * NOTE: before using this function you must check if the string command
 * is a valid command with is_comand(char *cmd, vars_t *vars) function
 */
int execute_command(char *command, vars_t *vars)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		print_command_error(vars, NULL);
		/*return (0);*/
	}
	if (pid == 0)
	{
		if (execve(command, vars->commands, vars->env) == -1)
			print_command_error(vars, NULL);
		/*return (0);*/
	}
	else
	{
		wait(&(vars->status));
		if (WIFEXITED(vars->status))
			vars->status = WEXITSTATUS(vars->status);
		else if (WIFSIGNALED(vars->status) && WTERMSIG(vars->status) == SIGINT)
			vars->status = 130;
		return (1);
	}
	/*print_command_error(vars, ": not found\n");*/
	vars->status = 127;
	return (0);
}
/**
 * print_command_error - function that prints the error of th shell
 * @vars: struct with the program variables
 * @message: message to be printed with the error
 *
 * Return: nothing
 */
void print_command_error(vars_t *vars, char *message)
{
	_dprintf(STDERR_FILENO, "%s: %u: %s",
			vars->av[0], vars->num_ins, vars->commands[0]);
	if (message)
	{
		_dprintf(STDERR_FILENO, "%s", message);
	}
	else
		perror("");
}
