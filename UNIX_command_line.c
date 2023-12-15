#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64
#define NEWLINE '\n'

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	char *cmd = NULL;
	size_t cmd_len = 0;
	char *args[MAX_ARGS];

	while (1)
{
	print_prompt();
	if(read_cmd(&cmd,&cmd_len) == -1)
	exit(0);

	if(strlen(cmd) == 0)
	continue;

	tokenize_cmd(cmd,args);

	if(handle_builtin(args) == 0)
	execute_cmd(args);
}
	free(cmd);
	return(0);
}
void print_env(char *env[])
{
	int i;
	char newline = NEWLINE;

	for (i = 0; env[i] != NULL; i++)
	{
	size_t len = strlen(env[i]) + 1;
	ssize_t ret = write(1, env[i], len);

	ret = write(1, &newline, 1);
	if (ret == -1)
		{
		perror("write");
		return;
		}
	}
}

void tok_str(char *str, char *tokens[])
{
	char *token;
	const char delims[] = " \t\n,.:;!?\"'()[]{}";
	int i = 0;

	token = strtok(str, delims);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delims);
	}
	tokens[i] = NULL;
}

void add_path(char *cmd[])
{
	char *path;
	const char path_var[] = "PATH";

	path = getenv(path_var);
	if (path != NULL)
	{
	size_t len = strlen(path);

	if (strncmp(path, cmd[0], len) != 0)
		{
		strcat(cmd[0], path);
		}
	}
}
