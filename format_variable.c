#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * format_variable - Formats the variable as name=value
 * @name: The name of the variable
 * @value: The value of the variable
 * Return: A pointer to the formatted variable, or NULL on failure
 */
char *format_variable(const char *name, const char *value)
{
	char *var;
	int len;

	len = strlen(name) + strlen(value) + 2;
	var = malloc(len);
	if (var == NULL)
	{
		write_error("Memory allocation error\n");
		return (NULL);
	}

	strcpy(var, name);
	strcat(var, "=");
	strcat(var, value);

	return (var);
}
