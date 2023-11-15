#include "shell.h"

/**
 * _strdup - Function that duplicate a string
 * @str: string to be dublicated
 * Return: the duplicated string
 */

char *_strdup(const char *str)
{
	int length = 0;
	char *copy;

	if (!str)
		return (NULL);
	while (*str++)
		length++;

	copy = malloc(sizeof(char) * (length + 1));

	if (!copy)
		return (NULL);

	for (length++; length--;)
		copy[length] = *--str;


	return (copy);
}

