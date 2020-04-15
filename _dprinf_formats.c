#include "shell.h"

/**
 * fun_string- function that prints strings
 * @fd: file descriptor
 * @s: va_list with the string
 * Return: number of printed chars
 */
int fun_string(int fd, va_list s)
{
	int count = 0, i;
	char *string = va_arg(s, char *);

	if (string == NULL)
		return (write(1, "(null)", 6));
	for (i = 0;  string[i]; i++)
		count += _dputchar(fd, string[i]);
	return (count);
}
/**
 * fun_per - function that prints percentage sign
 * @fd: file descriptor
 * @c: va_list with the sign
 * Return: number of printed chars
 */
int fun_per(int fd, va_list c)
{
	UNUSED(c);
	return (_dputchar(fd, '%'));
}
/**
 * fun_dec - function that prints a decimal number
 * @fd: file descriptor
 * @d: va_list with number
 * Return: number of printed chars
 */
int fun_dec(int fd, va_list d)
{
	int digits[10];
	int j, teens, num, sum, count;

	num = va_arg(d, int);
	count = 0;
	teens = 1000000000;
	digits[0] = num / teens;
	for (j = 1; j < 10; j++)
	{
		teens /= 10;
		digits[j] = (num / teens) % 10;
	}
	if (num < 0)
	{
		_dputchar(fd, '-');
		count++;
		for (j = 0; j < 10; j++)
			digits[j] *= -1;
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += digits[j];
		if (sum != 0 || j == 9)
		{
			_dputchar(fd, digits[j] + '0');
			count++;
		}

	}
	return (count);
}
/**
 * fun_uns - function that prints unsigned int
 * @fd: file descriptor
 * @u: va_list u
 * Return: number of chars
 */
int fun_uns(int fd, va_list u)
{
	unsigned int digits[10];
	unsigned int j, teens, num, sum, count = 0;

	num = va_arg(u, unsigned int);
	teens = 1000000000;
	for (j = 0; j < 10; j++)
	{
		digits[j] = (num / teens) % 10;
		teens /= 10;
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += digits[j];
		if (sum != 0 || j == 9)
			count += _dputchar(fd, digits[j] + '0');
	}
	return (count);
}
