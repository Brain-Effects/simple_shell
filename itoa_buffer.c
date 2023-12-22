#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * itoa_buffer - Convert an integer to a string
 * @num: The integer to convert
 * @buffer: The buffer to store the string
 * @base: The base to use for conversion
 * Return: A pointer to the string
 */
char *itoa_buffer(int num, char *buffer, int base)
{
	int i = 0;
	int is_negative = 0;
	int start = 0;
	int end;

	if (num == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return (buffer);
	}

	if (num < 0 && base == 10)
	{
		is_negative = 1;
		num = -num;
	}

	while (num != 0)
	{
		int rem = num % base;

		buffer[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	if (is_negative)
	buffer[i++] = '-';
	buffer[i] = '\0';
	end = i - 1;
	while (start < end)
	{
		char temp = buffer[start];

		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
	return (buffer);
}
