#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * is_invalid_argument - Checks if the argument is invalid
 * @name: The name of the variable
 * Return: 1 if invalid, 0 if valid
 */
int is_invalid_argument(const char *name)
{
	if (name[0] == '\0' || strchr(name, '=') != NULL)
	{
	write_error("Invalid arguments\n");
		return (1);
	}
	return (0);
}
