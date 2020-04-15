#include "shell.h"

/**
 * _getline - function that reads an entire line from stream
 * @lineptr: buffer for storing the line
 * @n: n bytes in size
 * @stream: stream
 * Return: -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}
