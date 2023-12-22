#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * copy_value - Copy a value to a string
 * @new_str: The string to copy the value to
 * @temp: The value to copy
 * @i: The index to start copying at
 */
void copy_value(char *new_str, char *temp, int i)
{
	int k = 0;

	while (temp[k])
	{
		new_str[i] = temp[k];
		i++;
		k++;
	}
}
