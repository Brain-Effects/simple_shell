#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * create_alias - Create a new alias
 * @name: The name of the alias
 * @value: The value of the alias
 * @head: A pointer to the head of the alias list
 * Return: 0 on success, -1 on failure
 */
int create_alias(char *name, char *value, alias_t **head)
{
	alias_t *node;

	node = malloc(sizeof(alias_t));
	if (node == NULL)
	{
		perror("alias");
		return (-1);
	}

	node->name = strdup(name);
	if (node->name == NULL)
	{
		free(node);
		perror("alias");
		return (-1);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->name);
		free(node);
		perror("alias");
		return (-1);
	}

	node->next = *head;
	*head = node;

	return (0);
}
