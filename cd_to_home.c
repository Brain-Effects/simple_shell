#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * cd_to_home - Changes the current directory to HOME
 * Return: 0 on success, -1 on failure
 */
int cd_to_home(void)
{
	char *home;
	int ret;

	home = getenv("HOME");
	if (home == NULL)
	{
	ret = write(STDERR_FILENO, "cd: HOME not set\n", 18);
	if (ret == -1 || ret < 18)
		{
		perror("cd");
		return (-1);
		}
	}

	return (cd_to_directory(home));
}
