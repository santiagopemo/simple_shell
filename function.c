#include "shell.h"

/**
 * prompt - Prints $ for prompt
 * Return: void
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2);
	}
}
