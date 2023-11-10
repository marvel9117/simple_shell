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

