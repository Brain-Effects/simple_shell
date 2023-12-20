#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * copy_env_except - Copies the environment variables
 * except the one to be removed
 * @env: The original environment variables
 * @newenv: The new environment variables
 * @name: The name of the variable to be removed
 * @len: The length of the name
 */
void copy_env_except(char **env, char **newenv, const char *name, int len)
{
	int i = 0;
	int j = 0;

	while (env[i] != NULL)
	{
	if (strncmp(env[i], name, len) != 0 || env[i][len] != '=')
	{
		newenv[j] = env[i];
		j++;
	}
		i++;
	}
	newenv[j] = NULL;
}
