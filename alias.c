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
	int i;
	char *name, *value, *equal;

	for (i = 0; args[i]; i++)
	{
		equal = strchr(args[i], '=');
		if (equal)
	{
		name = args[i];
		value = equal + 1;
		if (create_or_update_alias(name, value, head, args) == -1)
		return (-1);
	}
		else
	{
		if (print_alias(args[i], *head) == -1)
		return (-1);
		}
	}

	return (0);
}
