#include "shell.h"

/**
 * _strcmpd - function to serach for substring within fstring
 * @fstring: the first string
 * @sub: sub string
 *
 * Return: 1 on success and -1 on failure
 */

int _strcmpd(char *fstring, const char *sub)
{
	int f_len = _strlen(fstring);
	int sub_len = _strlen(sub);
	int i, j;


	if (!fstring || !sub)
		return (-1);

	if (sub_len == 0 || f_len < sub_len)
		return (-1);

	for (i = 0; i <= f_len - sub_len; i++)
	{
		j = 0;
		while (j < sub_len && fstring[i + j] == sub[j])
			j++;

		if (j == sub_len)
			return (i);
	}
	return (-1);
}


