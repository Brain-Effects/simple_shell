#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * realloc_str - Reallocate memory for a string
 * @new_str: The original string
 * @len: The new length of the string
 * Return: A pointer to the reallocated string
 */
char *realloc_str(char *new_str, int len)
{
	new_str = realloc(new_str, len);
	return (new_str);
}
