#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * create_or_update_alias - Create or update an alias
 * @name: The name of the alias
 * @value: The value of the alias
 * @head: A pointer to the head of the alias list
 * @arg: The arguments to the command
 * Return: 0 on success, -1 on failure
 */
int create_or_update_alias(char *name, char *value, alias_t **head, char **arg)
{
	char *equal;
	int i, ret;

	for (i = 0; arg[i]; i++)
	{
	equal = strchr(arg[i], '=');
	if (equal)
	{
		name = arg[i];
		value = equal + 1;
		ret = create_alias(name, value, head);
	}
	else
	{
		ret = print_alias(arg[i], *head);
	}

	if (ret == -1)
		return (-1);
	}

	return (0);
}
