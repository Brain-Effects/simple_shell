#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * alias - Implement the alias builtin command
 * @args: The arguments to the command
 * @head: A pointer to the head of the alias list
 * Return: 0 on success, -1 on failure
 */

int alias(char **args, alias_t **head)
{
	if (args == NULL || head == NULL)
	return (-1);

	if (args[0] == NULL)
	return (print_alias_list(*head));

	return (process_alias_args(args, head));
}
