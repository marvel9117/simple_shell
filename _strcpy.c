#include "shell.h"

/**
 * _strcpy - Function that copies a string
 * @dest: the destination to be copied to
 * @src: the source string
 *
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == src || src == 0)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;

	return (dest);
}
