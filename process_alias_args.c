#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * process_alias_args - Loop through the arguments and process them
 * @args: The arguments to the command
 * @head: A pointer to the head of the alias list
 * Return: 0 on success, -1 on failure
 */

int process_alias_args(char **args, alias_t **head)
{
	char *name, *value, *equal;
	int i, ret;

  for (i = 0; args[i]; i++)
	{
	equal = strchr(args[i], '=');
	if (equal)
	ret = create_or_update_alias(args[i], head);
	else
	ret = print_alias(args[i], *head);

		if (ret == -1)
		return (-1);
	}

	return (0);
}
