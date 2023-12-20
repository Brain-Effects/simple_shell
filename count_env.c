#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * count_env - Counts the number of environment variables
 * @env: The environment variables
 * Return: The number of environment variables
 */
int count_env(char **env)
{
	int count = 0;

	while (env[count] != NULL)
		count++;
	return (count);
}
