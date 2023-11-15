#include "shell.h"

/**
 * _atoi - convert a string containg an integer to an integer value
 * @str: the string to read
 * Return: the integer value converted
 */

int _atoi(char *str)
{
	int start = 0, sign = 1;
	unsigned int num = 0;

	while (*str)
	{
		if (start && (*str < '0' || *str > '9'))
			break;

		if (*str == '-')
			sign *= -1;

		if (*str >= '0' && *str <= '9')
		{
			start = 1;
			num = num * 10  + (*str - '0');
		}

		str++;
	}
	return (sign * num);
}


/**
 * _isalpha - check if chracter is alphabet
 * @c: integer to check
 * Return: 1 if its a char else 0.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
