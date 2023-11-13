#include "shell.h"

/**
 * _strncat - concatenate the first n characters of src to dest
 * @dest: destination string
 * @src: source string
 * @n: number of characters of resulting string dest
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t i, j = 0;

	i = _strlen(dest);

	while (src[j] && j < n)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return(dest);
}
