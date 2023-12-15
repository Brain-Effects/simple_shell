#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * create_or_update_alias - Create or update an alias
 * @arg: The argument to the command
 * @head: A pointer to the head of the alias list
 * Return: 0 on success, -1 on failure
 */

int create_or_update_alias(char *arg, alias_t **head)
{
	alias_t *node;
	char *name, *value;
	int ret;

	name = strtok(arg, "=");
	value = strtok(NULL, "=");
	if (name == NULL || value == NULL)
	{
	ret = write(STDERR_FILENO, "alias: invalid syntax\n", 22);
	if (ret == -1 || ret < 22)
	perror("alias");
		return (-1);
	}

	node = find_alias(name, *head);
	if (node)
	return (update_alias_value(node, value));
	else
	return (create_alias(name, value, head));
}
