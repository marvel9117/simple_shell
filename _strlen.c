#include "shell.h"

/**
 * _strlen - function that returns the length of a string
 * @str: string to check the length
 * Return: the length of the string
 */

int _strlen(const char *str)
{
	int count = 0;

	if (!str)
		return (0);

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}
