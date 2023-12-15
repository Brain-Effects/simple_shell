#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * handle_commands - Handle the commands separator ;
 * @str: The input string
 * Return: An array of commands, or NULL on failure
 */
char **handle_commands(char *str)
{
	char **commands;
	char *token;
	int i, count;

	if (str == NULL)
	return (NULL);

	count = 1;
	for (i = 0; str[i]; i++)
	{
	if (str[i] == ';')
		count++;
	}

	commands = malloc(sizeof(char *) * (count + 1));
	if (commands == NULL)
	return (NULL);

	i = 0;
	token = strtok(str, ";");
	while (token)
	{
		commands[i] = token;
		i++;
		token = strtok(NULL, ";");
	}
	commands[i] = NULL;

	return (commands);
}
