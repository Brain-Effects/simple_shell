#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NEWLINE '\n'

/**
 * handle_getline_error - handles errors or EOF from getline
 * @buf: the input buffer
 */
void handle_getline_error(char *buf)
{
	if (feof(stdin))
	{
		free(buf);
		buf = NULL;
		exit(EXIT_SUCCESS);
	}
		perror("Error occurred");
		free(buf);
		buf = NULL;
		exit(EXIT_FAILURE);
}
