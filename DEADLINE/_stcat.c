#include "shell.h"

/**
 * _strcat - Function that concatiante two stings
 * @desti: the string destination
 * @src: string source
 *
 * Return: The concatinated string
 */

char *_strcat(char *desti, char *src)
{
	char *q = desti;

	while (*q)
		q++;

	while (*src)
		*q++ = *src++;

	*q = '\0';

	return (desti);
}
