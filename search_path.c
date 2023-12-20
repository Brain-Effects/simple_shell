#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

/**
 * search_path - Searches for a command in the PATH
 * @cmd: The command to search for
 *
 * Return: The full path to the command, or NULL if not found
 */
char *search_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	char *full_path = malloc(MAX_CMD_LENGTH);

	while (dir != NULL)
	{
	strcpy(full_path, dir);
	strcat(full_path, "/");
	strcat(full_path, cmd);
	if (access(full_path, X_OK) == 0)
	{
		free(path_copy);
		return (full_path);
	}
		dir = strtok(NULL, ":");
	}
	
	free(path_copy);
	free(full_path);
	return (NULL);
}
