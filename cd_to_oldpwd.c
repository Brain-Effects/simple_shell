#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * cd_to_oldpwd - Changes the current directory to OLDPWD
 * Return: 0 on success, -1 on failure
 */
int cd_to_oldpwd(void)
{
	char *oldpwd;
	int ret;

	oldpwd = getenv("OLDPWD");
	if (oldpwd == NULL)
	{
	ret = write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
	if (ret == -1 || ret < 19)
	{
		perror("cd");
		return (-1);
	}

	ret = write(STDOUT_FILENO, oldpwd, strlen(oldpwd));
	if (ret == -1 || (size_t) ret < strlen(oldpwd))
		perror("cd");

	ret = write(STDOUT_FILENO, "\n", 1);
	if (ret == -1 || ret < 1)
		perror("cd");

	}
	return (cd_to_directory(oldpwd));
}
