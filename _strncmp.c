#include "shell.h"

/**
 * _strncmp - compare the first n chracters of two string
 * @str1: the first string
 * @str@: the second string
 *
 * @n: the number of chracter to compare
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (!str1[i] || !str2[i] || (unsigned char)str1[i] != (unsigned char)str2[i])
			return(str1[i] - str2[i]);
	}
	return 0;
}
