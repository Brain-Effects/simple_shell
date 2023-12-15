#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * write_error - Writes an error message to the standard error
 * @msg: The error message
 */
void write_error(const char *msg)
{
	size_t len = strlen(msg) + 1;
	ssize_t ret = write(STDERR_FILENO, msg, len);
	if (ret == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
}
