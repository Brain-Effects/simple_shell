#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * print_prompt - Prints the shell prompt
 */
void print_prompt(void)
{
	ssize_t ret;

	ret = write(STDOUT_FILENO, "$ ", 2);
	if (ret == -1)
	{
		perror("write");
		exit(1);
	}
}
