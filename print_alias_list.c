#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * print_alias_list - Print the list of aliases
 * @head: A pointer to the head of the alias list
 * Return: 0 on success, -1 on failure
 */
int print_alias_list(alias_t *head)
{
	alias_t *node = head;
	int ret;
	
	while (node)
	{
	ret = write(STDOUT_FILENO, node->name, strlen(node->name));
	if (ret == -1 || (size_t)ret < strlen(node->name))
		perror("alias");

	ret = write(STDOUT_FILENO, "='", 2);
	if (ret == -1 || ret < 2)
		perror("alias");

	ret = write(STDOUT_FILENO, node->value, strlen(node->value));
	if (ret == -1 || (size_t)ret < strlen(node->value))
		perror("alias");

	ret = write(STDOUT_FILENO, "'\n", 2);
		if (ret == -1 || ret < 2)
		perror("alias");

		node = node->next;
	}

	return (0);
}
