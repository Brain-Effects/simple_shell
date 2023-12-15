#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * update_alias_value - Update the value of an alias
 * @node: A pointer to the alias node
 * @value: The new value of the alias
 * Return: 0 on success, -1 on failure
 */
int update_alias_value(alias_t *node, char *value)
{
	free(node->value);
	node->value = strdup(value);
	if (node->value == NULL)
	{
		perror("alias");
		return (-1);
	}

	return (0);
}
