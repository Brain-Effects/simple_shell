#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_ARGS 64

/**
 * tokenize_cmd - Tokenizes a command into arguments
 * @cmd: The command to tokenize
 * @args: The array of arguments
 */
void tokenize_cmd(char *cmd, char **args)
{
	int i;

	args[0] = strtok(cmd, " ");
	for (i = 1; i < MAX_ARGS - 1; i++)
	{
	args[i] = strtok(NULL, " ");
	if (args[i] == NULL)
		break;
	}
	args[i] = NULL;
}
