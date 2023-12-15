#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * handle_comment - Handle a comment in C
 * @line: A pointer to a string containing a line of code
 * @index: A pointer to an integer indicating the current position in the line
 *
 * Description: This function checks if the line contains a comment, and if so,
 * skips the comment and updates the index accordingly. It returns 1 if a
 * comment is found, and 0 otherwise.
 * Return: 1 if a comment is found, 0 otherwise
 */

int handle_comment(char *line, int *index)
{
	if (line == NULL || line[*index] == '\0')
		return (0);

	if (line[*index] == '#' && line[*index + 1] == ' ')
	{
		while (line[*index] != '\0')
		(*index)++;
		return (1);
	}
	return (0);
}
