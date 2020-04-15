#include "shell.h"

/**
 * env_to_list - function that transforms a array of strings to a linked list
 * @argv: array of strings
 *
 * Return: pointer to a head of linked list
 */
env_t *env_to_list(char **argv)
{
	int i, p_value;
	char *name, *value, *tmp;
	env_t *head = NULL;

	for (i = 0; argv[i]; i++)
	{
		tmp = _strdup(argv[i]);
		name = _strtok(tmp, "=");
		p_value = _strlen(name) + 1;
		value = _strdup(argv[i] + p_value);
		add_node_end(&head, name, value);
		free(value);
		free(tmp);
	}
	return (head);
}
/**
 * add_node_end - function that adds a node at the end of a linked list
 * @head: pointer to the head of the list
 * @name: name of the variable
 * @value: value of the variables
 *
 * Return: pointer to the new node
 */
env_t *add_node_end(env_t **head,  char *name,  char *value)
{
	env_t *new;
	env_t *tmp;

	if (name == NULL || value == NULL)
		return (NULL);
	new = malloc(sizeof(env_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->name = _strdup(name);
	if (new->name == NULL)
	{
		free(new);
		return (NULL);
	}
	new->value = _strdup(value);
	if (new->value == NULL)
	{
		free(new->name);
		free(new);
		return (NULL);
	}
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	tmp = *head;
	for (; tmp->next;)
		tmp = tmp->next;
	tmp->next = new;
	return (tmp);
}
/**
 * list_to_env - function that converts a linked list with the enviro
 * mental variables o an array of string
 * @head: head of linked list
 *
 * Return: double pointer to array with enviromental variables
 */
char **list_to_env(env_t *head)
{
	int i, j;
	char **new_env, *name;
	env_t *tmp = head;

	for (i = 0; tmp; tmp = tmp->next)
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (new_env == NULL)
	{
		perror("Fatal error");
		return (NULL);
	}
	for (j = 0; j < i; j++, head = head->next)
	{
		name = str_concat(head->name, "=");
		if (name == NULL)
		{
			return (NULL);
		}
		new_env[j] = str_concat(name, head->value);
		if (new_env[j] == NULL)
		{
			for (; j >= 0; j--)
				free(new_env[j]);
			free(new_env);
			free(name);
			return (NULL);
		}
		free(name);
	}
	new_env[j] = NULL;
	return (new_env);
}
/**
 * free_list - function that frees a linked list with enviromental variables
 * @head: pointer to list's head
 *
 * Return: nothing
 */
void free_list(env_t *head)
{
	env_t *tmp = head;
	env_t *next;

	while (tmp)
	{
		next = tmp->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		tmp = next;
	}
}
/**
 * print_list - function that prints a linked list
 * @h: pointer to list's head
 *
 * Return: linked list lenght
 */
size_t print_list(env_t *h)
{
	size_t i;
	char *n = "(nil)";
	char *v = "(nil)";

	for (i = 0; h; i++)
	{
		if (h->name != NULL && h->value != NULL)
		{
			n = h->name;
			v = h->value;
		}
		_dprintf(STDOUT_FILENO, "%s=%s\n", n, v);
		h = h->next;
	}
	return (i);
}
