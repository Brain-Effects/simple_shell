#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NEWLINE '\n'

/**
 * prompt_user - displays the prompt to the user
 */
void prompt_user(void)
{
	size_t len = strlen(":) ") + 1;
	ssize_t ret = write(2, ":) ", len);

	if (ret == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
}
