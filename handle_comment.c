#include "shell.h"


/**
 * handle_comment - handle comment by deleting the cooment from buffer
 * @buffer:pointer to the string input
 *
 * Return: the buffer without comment
 */

char *handle_comment(char *buffer)
{
	char *original = buffer;

	while (*buffer != '\0')
	{
		if (*buffer == '#' && (buffer == original || *(buffer - 1) == ' '))
		{
			while (*buffer != '\0' && *buffer != '\n')
			{
				*buffer = '\0';
				buffer++;
			}
		}
		else
		{
			buffer++;
		}
	}

	return (original);
}
