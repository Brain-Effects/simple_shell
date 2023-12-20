#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NEWLINE '\n'

/**
 * exit_shell - exits the shell with a given status or an error message
 * @buf: the input buffer
 */
void exit_shell(char *buf)
{
	int status = 0;
	char *endptr = NULL;

	status = strtol(buf + 4, &endptr, 10);

	if (endptr == buf + 4 || *endptr != '\n')
	{
	size_t len = strlen("Invalid argument for exit\n") + 1;
	ssize_t ret = write(2, "Invalid argument for exit\n", len);

	if (ret == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
		free(buf);
		buf = NULL;
		return;
	}

	free(buf);
	buf = NULL;
	exit(status);
}
