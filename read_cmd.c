#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

/**
 * read_cmd - Reads a command from standard input
 * @cmd: Pointer to the command buffer
 * @cmd_len: Pointer to the command buffer length
 *
 * Return: 0 on success, -1 on error or EOF
 */
int read_cmd(char **cmd, size_t *cmd_len)
{
	ssize_t ret;

	if (getline(cmd, cmd_len, stdin) == -1)
	{
	ret = write(STDOUT_FILENO, "\n", 1);
	if (ret == -1)
	{
		perror("write");
		exit(1);
	}
		return (-1);
	}

	(*cmd)[strcspn(*cmd, "\n")] = '\0';

	return (0);
}
