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

char *itoa(int value, char *str, int base);

char *replace_var(char *str, int status, int pid)
{
	char *new_str, *temp, *dollar;
	char *status_str, *pid_str;
	int len, i, j, k, ret;
	char *buffer = malloc(sizeof(int) * 3 + 1);

	if (str == NULL)
		return (NULL);

	status_str = itoa(status, buffer, 10 );
	pid_str = itoa(pid, buffer, 10);

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
	new_str = realloc(new_str, len);
	if (new_str == NULL)
		return (NULL);

	i = dollar - new_str;
	j = i + 2;
	k = len - 1;
	while (k >= j)
	{
		new_str[k] = new_str[k - strlen(temp) + 2];
		k--;
	}

	j = i;
	k = 0;
	while (temp[k])
		{
		new_str[j] = temp[k];
		j++;
		k++;
		}
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

	return (NULL);
}
