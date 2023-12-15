#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * execute_file - Execute the commands in a file
 * @filename: The name of the file
 *
 * Description: This function opens the file, reads each line, and executes it
 * as a command using the system function. It returns 0 on success, or -1 on
 * failure.
 * Return: 0 on success, -1 on failure
 */

int execute_file(char *filename)
{
	FILE *file;
	int fd;
	char buffer[1024];
	int ret;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror(filename);
		return (-1);
	}

	fd = fileno(file);

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
	ret = system(buffer);

	if (ret == -1)
		perror("system");
	}

	close(fd);

	return (0);
}

/* main - Test the execute_file function */
int main_execute(int argc, char *argv[])
{
	int fd_err;
	int ret;

	fd_err = fileno(stderr);

	if (argc < 2)
	{
	ret = write(fd_err, "Usage: ", 7);
	if (ret == -1)
	{
		perror("write");
	}

	ret = write(fd_err, argv[0], strlen(argv[0]));
	if (ret == -1)
	{
		perror("write");
	}
	ret = write(fd_err, " [filename]\n", 12);
	if (ret == -1)
	{
		perror("write");
	}
		exit(1);
	}

	execute_file(argv[1]);
	exit(0);
}
