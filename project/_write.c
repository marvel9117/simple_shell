#include "shell.h"

/**
 * _write - a function that write to field descriptor
 * @fd: field descriptor
 * @inps: input string to write
 * @len: size of input string (number of the character in a string)
 *
 * Return: -100 when no file descriptor, 100 when erite successful
 */


int _write(int fd, char *inps, int len)
{

	static char writeque[BUFFER_i];
	static int que;
	int j;

	if (fd < 0)
	{
		que = 0;
		return (-100);
	}
	if (inps)
	{
		if ((len + que) >= BUFFER_i)
		{
			if (write(fd, writeque, BUFFER_i) == -1)
			{
				print_error(NULL, NULL, "problem writing");
				exit(-1);
			}
			que = 0;
		}
		j = 0;
		while (j < len)
		{
			writeque[que + j] = inps[j];
			j++;
		}
		writeque[que + j] = '\0';
		que += len;
		return (100);
	}
	if (!inps)
		if (write(fd, writeque, que) == -1)
		{
			print_error(NULL, NULL, "problem writing");
			exit(-1);
		}
	return (0);
}
