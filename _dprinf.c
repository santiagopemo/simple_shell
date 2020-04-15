#include "shell.h"

/**
 * _dputchar - writes the character c to stdout
 * @fd: file descriptor
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _dputchar(int fd, char c)
{
	return (write(fd, &c, 1));
}
/**
 * get_func - selects the correct function to perform the operation asked
 * @s: format type
 * Return: function that recives a va_list and return and int
 */
int (*get_func(const char *s))(int, va_list)
{
	unsigned int j = 0;
	fmt tipos[] = {
		/*{"c", fun_char},*/
		{"s", fun_string},
		{"%", fun_per},
		{"d", fun_dec},
		{"u", fun_uns},
		{NULL, NULL}
	};
	while (tipos[j].z != NULL)
	{
		if (*s == *tipos[j].z)
		{
			return (tipos[j].fun);
		}
		j++;
	}
	return (NULL);
}
/**
 * _dprintf - funtion that prints formated output
 * @fd: file descriptor
 * @format: format to print
 * Return: number of printed chars
 */
int _dprintf(int fd, const char *format, ...)
{
	int i = 0, count = 0;
	va_list list;
	int (*f)(int, va_list);

	if (format == NULL)
		return (-1);
	va_start(list, format);
	if (list == NULL)
		return (-1);
	while (format && format[i])
	{
		if (format[i] && format[i] != '%')
		{
			_dputchar(fd, format[i]);
			count++;
		}
		if (format[i] == '%')
		{
			while (format[i + 1] == ' ')
				i++;
			if (format[i + 1] == '\0')
				return (-1);
			f = get_func(&format[i + 1]);
			if (f != NULL)
			{
				count += f(fd, list);
				i += 1;
			}
			else
				count += _dputchar(fd, '%');
		}
		i++;
	}
	va_end(list);
	return (count);
}
