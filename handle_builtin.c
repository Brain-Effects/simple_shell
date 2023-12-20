#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * handle_builtin - Handles built-in commands
 * @args: The array of arguments
 *
 * Return: 1 if a built-in command was handled, 0 otherwise
 */
int handle_builtin(char **args)
{
	int i;
	ssize_t ret;

	if (strcmp(args[0], "exit") == 0)
		exit(0);

	if (strcmp(args[0], "env") == 0)
	{
	for (i = 0; environ[i] != NULL; i++)
	{
	ret = write(STDOUT_FILENO, environ[i], strlen(environ[i]));
	if (ret == -1)
		{
		perror("write");
		exit(1);
		}
	ret = write(STDOUT_FILENO, "\n", 1);
	if (ret == -1)
		{
		perror("write");
		exit(1);
		}
	}
		return (1);
	}

	return (0);
}
