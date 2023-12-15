#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * cd_to_directory - Changes the current directory to the given directory
 * @directory: The directory to change to
 * Return: 0 on success, -1 on failure
 */
int cd_to_directory(char *directory)
{
	char *pwd, *temp;
	int len;

	if (chdir(directory) != 0)
	{
		perror("cd");
		return (-1);
	}

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("cd");
		return (-1);
	}

	len = strlen(pwd) + 5;
	temp = malloc(len);
	if (temp == NULL)
	{
		perror("cd");
		free(pwd);
		return (-1);
	}

	strcpy(temp, "PWD=");
	strcat(temp, pwd);
	if (putenv(temp) != 0)
	{
		perror("cd");
		free(pwd);
		free(temp);
		return (-1);
	}

	return (update_oldpwd(pwd, temp));
}
