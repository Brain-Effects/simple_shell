#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * find_alias - Find an alias with the given name
 * @name: The name of the alias
 * @head: A pointer to the head of the alias list
 * Return: A pointer to the alias node, or NULL if not found
 */
alias_t *find_alias(char *name, alias_t *head)
{
	alias_t *node = head;

	while (node)
	{
	if (strcmp(node->name, name) == 0)
	break;
		node = node->next;
	}

	return (node);
}
