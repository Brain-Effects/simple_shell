#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NEWLINE '\n'

/**
 * my_exit - exits the shell with a given status or an error message
 * Return: nothing, exits the program
 */
int my_exit(char **env)
{
	char *buf = NULL;
	size_t buflen = 0;

	do
	{
	prompt_user();

	if (getline(&buf, &buflen, stdin) == -1)
		handle_getline_error(buf);

	if (buf[0] == '\0' || strcmp(buf, "\n") == 0)
	{
		free(buf);
		buf = NULL;
	continue;
		}

	if (strncmp(buf, "exit", 4) == 0)
		exit_shell(buf);

	if (strcmp(buf, "env\n") == 0)
	{
		print_env(env);
		free(buf);
		buf = NULL;
	continue;
	}
		tok_str(buf, cmd);
		add_path(cmd);
		execute_command(cmd, env);
		free(buf);
		buf = NULL;
	}
			
	while (1);
	exit(EXIT_SUCCESS);
}
