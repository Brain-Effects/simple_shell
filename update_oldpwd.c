#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * update_oldpwd - Updates the OLDPWD environment variable
 * @pwd: The new current directory
 * @temp: The new PWD variable
 * Return: 0 on success, -1 on failure
 */
int update_oldpwd(char *pwd, char *temp)
{
	char *oldpwd;
	int len;

	oldpwd = getenv("PWD");
	if (oldpwd != NULL)
	{
	len = strlen(oldpwd) + 8;
	temp = realloc(temp, len);
	if (temp == NULL)
	{
		perror("cd");
		free(pwd);
		return (-1);
	}

	strcpy(temp, "OLDPWD=");
	strcat(temp, oldpwd);
	if (putenv(temp) != 0)
		{
		perror("cd");
		free(pwd);
		free(temp);
		return (-1);
		}
	}

	free(pwd);
	return (0);
}
