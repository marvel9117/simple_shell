#include "shell.h"

/**
 * _strcmps - check if a given substring exactly matches
 * a portion of the input string
 *
 * @fstring: first string
 * @sub: substring to be compared
 *
 * Return: 1 if there is a match and
 * -1 if there is no match or if the inputs are invalid.
 */

int _strcmps(char *fstring, const char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (!*fstring)
		return (-1);
	if (_strlen(fstring) < _strlen(sub))
		return (-1);

	while (*sub && *fstring)
	{
		if (*sub != *fstring)
			return (-1);

		sub++, fstring++;
	}
	return (1);
}
