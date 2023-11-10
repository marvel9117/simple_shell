#include "shell.h"

/**
 * cal_expo - calculates the power of a number (exponentiation).
 * exponent indicates how many times the base should be multiplied by itself.
 * @base: the base
 * @power: power(exponent).
 *
 * Return: Integer value.
 */

int cal_expo(unsigned int base, int power)
{
	int i, ret = 1;

	for (i = 0; i < power; i++)
	{
		ret = ret * base;
	}
	return (ret);
}
