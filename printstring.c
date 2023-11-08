#include "shell.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printstring(char *str)
{
	int i = 0, string = 0;

	while(str[i])
	{
		string += _putchar(str[i]);
		i++;
	}
	return (string);
}

