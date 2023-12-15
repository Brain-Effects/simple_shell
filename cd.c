#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * cd - Changes the current directory of the process
 * @directory: The directory to change to
 * Return: 0 on success, -1 on failure
 */
int cd(char *directory)
{
	if (directory == NULL)
		return (cd_to_home());

	if (strcmp(directory, "-") == 0)
		return (cd_to_oldpwd());

	return (cd_to_directory(directory));
}
