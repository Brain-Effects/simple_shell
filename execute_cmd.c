#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

/**
 * execute_cmd - Executes a command
 * @args: The array of arguments
 */
void execute_cmd(char **args)
{
	int status;

	if (args[0][0] != '/')
	args[0] = search_path(args[0]);

	if (args[0] == NULL)
	{
		perror(args[0]);
		return;
	}

	if (fork() == 0)
	{
	if (execvp(args[0], args) == -1)
	{
		perror(args[0]);
		exit(1);
	}
	}
	else
	{
		wait(&status);
	}
}
