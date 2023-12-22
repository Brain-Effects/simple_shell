#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * replace_var - Replace the variables $? and $$ in a string
 * @str: The input string
 * @status: The value of the $? variable
 * @pid: The value of the $$ variable
 * Return: A new string with the variables replaced, or NULL on failure
 */
char *replace_var(char *str, int status, int pid)
{
	char *new_str, *temp, *dollar;
	char *status_str, *pid_str;
	int len, i;
	char *buffer = malloc(sizeof(int) * 3 + 1);
	ssize_t ret;

	if (str == NULL)
	return (NULL);
	status_str = itoa_buffer(status, buffer, 10);
	pid_str = itoa_buffer(pid, buffer, 10);
	len = strlen(str) + 1;
	new_str = malloc(len);
	if (new_str == NULL)
	return (NULL);
	strcpy(new_str, str);
	dollar = strchr(new_str, '$');
	while (dollar)
	{
	if (dollar[1] == '?' || dollar[1] == '$')
	{
	temp = (dollar[1] == '?') ? status_str : pid_str;
	len = len + strlen(temp) - 2;
	new_str = realloc_str(new_str, len);
	if (new_str == NULL)
		return (NULL);
	i = dollar - new_str;
	shift_chars(new_str, i + 2, len);
	copy_value(new_str, temp, i);
	}
		dollar = strchr(dollar + 1, '$');
	}
	ret = write(STDOUT_FILENO, new_str, strlen(new_str));
	if (ret == -1 || (size_t) ret < strlen(new_str))
	{
		perror("replace_var");
	}
	free(new_str);
	free(status_str);
	free(pid_str);
	return (0);
}
