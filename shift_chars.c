#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * shift_chars - Shift characters in a string to the right
 * @new_str: The string to shift characters in
 * @j: The starting index for shifting
 * @len: The length of the string
 */
void shift_chars(char *new_str, int j, int len)
{
	int k = len - 1;

	while (k >= j)
	{
		new_str[k] = new_str[k - 2];
		k--;
	}
}
