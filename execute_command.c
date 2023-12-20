#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NEWLINE '\n'

/**
 * execute_command - executes the command in a child process
 * @cmd: the command and its arguments
 * @env: the environment variables
 */
void execute_command(char **cmd, char **env)
{
	char *msg;
	size_t len;
	ssize_t ret;

	if (fork() == 0)
	{
	execve(cmd[0], cmd, env);
	msg = strcat(cmd[0], ": No such file or directory\n");
	len = strlen(msg);
	ret = write(1, msg, len);
	if (ret == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
	}
}
