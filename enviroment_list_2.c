#include "shell.h"

/**
 * get_env_index - get the index of a enviromental variable fora linked list
 * @head: pointer to the head of a linked list
 * @name: name of enviromental variable
 *
 * Return: node index
 */
int get_env_index(env_t *head, char *name)
{
	int i = 0;

	while (head)
	{
		if (_strcmpr(head->name, name) == 0)
			return (i);
		head = head->next;
		i++;

	}
	return (-1);
}
/**
 * delete_nodeint_at_index - function that delete a node of a linked
 * list in a given position
 * @head: double pointer to the head linked list
 * @index: node index
 *
 * Return: 1 if success, -1 if fails
 */
int delete_nodeint_at_index(env_t **head, unsigned int index)
{
	unsigned int i;
	env_t *t, *next;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		next = (*head)->next;
		free((*head)->name);
		free((*head)->value);
		free(*head);
		*head = next;
		return (1);
	}
	t = *head;
	for (i = 0; t && i < index - 1 ; i++, t = t->next)
		continue;
	if (t || i == index - 1)
	{
		next = t->next;
		t->next = next->next;
		free(next->name);
		free(next->value);
		free(next);
		return (1);
	}
	return (-1);
}
