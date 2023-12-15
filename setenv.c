#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * setenv - Initialize a new environment variable, or modify an existing one
 * @name: The name of the variable
 * @value: The value of the variable
 * @overwrite: A flag to indicate whether to overwrite an existing variable
 * Return: 0 on success, -1 on failure
 */
int setenv(const char *name, const char *value, int overwrite)
{
	char *var;

	if (is_invalid_argument(name))
		return (-1);

	var = getenv(name);
	if (var != NULL && overwrite == 0)
		return (0);

	var = format_variable(name, value);
	if (var == NULL)
		return (-1);

	if (putenv(var) != 0)
	{
		perror("setenv");
		free(var);
		return (-1);
	}

	return (0);
}
