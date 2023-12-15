#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
 * itoa - converts an integer to a string in a given base
 * @value: the integer to convert
 * @str: the buffer to store the converted string
 * @base: the base to use for the conversion, between 2 and 36
 * Return: a pointer to the converted string, or NULL if base is invalid
 */

char *itoa(int value, char *str, int base)
{
	char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char buffer[33];
	int i = 0;
	int j = 0;
	int sign = 0;

	if (base < 2 || base > 36)
	{
		return (NULL);
	}
	if (value == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (value < 0 && base == 10)
	{
		sign = 1;
		value = -value;
	}
	while (value > 0)
	{
		buffer[i++] = digits[value % base];
		value /= base;
	}
	if (sign)
	{
		buffer[i++] = '-';
	}
	buffer[i] = '\0';
	for (j = 0; j < i; j++)
	{
		str[j] = buffer[i - j - 1];
	}
	str[i] = '\0';
	return (str);
}
