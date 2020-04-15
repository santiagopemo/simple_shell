#include "shell.h"

/**
 * strtoken1 - extract tokens from strings
 * @tmp_s: string
 * @tmp_d: delimiter
 * Return: pointer to the next token
 */
int strtoken1(char *tmp_s, char *tmp_d)
{
	int i, j;

	for (i = 0; tmp_s[i] != 0; i++)
	{
		for (j = 0; tmp_d[j] != 0; j++)
		{
			if (tmp_s[i] == tmp_d[j])
				break;
		}
		if (tmp_d[j] == 0)
			break;
	}
	return (i);
}

/**
 * strtoken2 - extract tokens from strings
 * @tmp_s: string
 * @tmp_d: delimiter
 * Return: pointer to the next token
 */
int strtoken2(char *tmp_s, char *tmp_d)
{
	int i, j;

	for (i = 0;  tmp_s[i] != 0; i++)
	{
		for (j = 0; tmp_d[j] != 0; j++)
		{
			if (tmp_s[i] == tmp_d[j])
				break;
		}
		if (tmp_d[j] != 0)
			break;
	}
	return (i);
}
/**
 * _strtok - extract tokens from strings
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next token
 */
char *_strtok(char *str, char *delim)
{
	/*return(strtok(str, delim));*/
	static char *save;
	int i;
	char *tmp_s;
	char *tmp_d;

	/* si NULL pasado en str se convierte en donde dejó la cadena guardada */
	if (str == 0)
		str = save;
	if (str == 0)
		return (0);

	tmp_s = str;
	tmp_d = delim;
	/* omitir delimitadores iniciales */
	i = strtoken1(tmp_s, tmp_d);
	str = str + i;
	if (*str == 0)
	{
		save = str;
		return (0);
	}
	/* iniciar nuevo token */
	tmp_s = tmp_s + i;
	i = strtoken2(tmp_s, tmp_d);
	save = tmp_s;
	if (tmp_s[i] != 0)
	{
		/* guarda la cadena para la próxima llamada */
		save = (save + i + 1);
		tmp_s[i] = '\0';
	}
	else
	{
		save = '\0'; /* si finaliza la cadena de entrada. */
	}
	return (tmp_s);
}
