#include "shell.h"

/**
 * num_len -  calculates the number of digits in a non-negative integer.
 * it return length of strignized number
 * @num: number
 * Return: the number of digit in the integer
 */

int num_len(unsigned int num)
{
	int len = 0;

	if (!num)
		return (1);

	while (num)
	{
		num = num / 10;
		len++;
	}

	return (len);
}
