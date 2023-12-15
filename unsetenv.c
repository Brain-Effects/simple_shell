#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * unsetenv - Remove an environment variable
 * @name: The name of the variable
 * Return: 0 on success, -1 on failure
 */
int unsetenv(const char *name)
{
	char **env, **newenv;
	int count, len;

	if (is_invalid_argument(name))
		return (-1);

	env = environ;
	count = count_env(env);

	newenv = malloc(sizeof(char *) * count);
	if (newenv == NULL)
	{
		write_error("Memory allocation error\n");
		return (-1);
	}

	len = strlen(name);
	copy_env_except(env, newenv, name, len);

	environ = newenv;
	return (0);
}
