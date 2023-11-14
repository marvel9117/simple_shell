#include "shell.h"

/**
 * _itoaa - convert number into character string that represent thesame integer
 * (integer to ASCII)
 * @n: the number to convert
 * Return: character string converted from number
 */

char *_itoaa(int n)
{
	int j, k, len, digit, tmp1, i = 0;
	unsigned int numm;
	char *nums = malloc(num_len((n > 0) ? n : -1 * n) + 2);

	if (!nums)
		return (NULL);
	if (n < 0)
		n *= -1, *(nums + i) = '-', i++;
	numm = n, len = num_len(numm), j = len - 1;
	if (numm == 0)
		nums[i] = 48, i++;
	else
	{
		while (j >= 0)
		{
			if (numm % cal_expo(10, j) == 0 && j != 0)
			{
				nums[i] = (48 + numm / cal_expo(10, j)), i++;
				for (k = j; k > 0; k--)
					nums[i] = 48, i++;
				j = -1;
			}
			else
			{
				digit = numm / cal_expo(10, j);
				nums[i] = digit + 48, i++;

				tmp1 = numm;
				numm -= cal_expo(10, j) * digit;
				if (num_len(tmp1) - num_len(numm) == 2)
					nums[i] = 48, i++, j--;

				j--;
			}
		}
	}
	return (nums);
}
