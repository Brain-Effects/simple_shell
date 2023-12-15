#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * getline - Reads a line from a file descriptor into a buffer
 * @fd: The file descriptor to read from
 * @buffer: The buffer to store the line
 * @size: The size of the buffer
 * Return: The number of characters read, or -1 on error or end of file
 */
int my_getline(int fd, char *buffer, size_t size)
{
	static char buf[BUFFER_SIZE];
	static int pos = 0;
	static int len = 0;
	int count = 0;
	char c;

	while (count < (int) size - 1)
	{
	if (pos >= len)
	{
	len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
		perror("read");
		return (-1);
		}
	if (len == 0)
		{
		buffer[count] = '\0';
		return (count);
		}
		pos = 0;
	}	
		c = buf[pos++];
		buffer[count++] = c;
		if (c == '\n')
		break;
	}

	buffer[count] = '\0';
	return (count);
}
