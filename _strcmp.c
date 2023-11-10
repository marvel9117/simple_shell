#include "shell.h"

/**
 * _strcmp - Function that  performs lexicogarphic comparison of two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: Positive if str1 > str2, Negative if str1 < str2,
 * Zero if str1 == str2.
 */


int _strcmp(char *str1, char *str2)
{
	if (!str1 && str2)
		return (-1);
	if (!str2 && str1)
		return (-1);

	while (*str1)
	{
		if (*str1 != *str2)
			break;
		str1++, str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
