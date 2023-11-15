#include "shell.h"

/**
 * p_error - function to display error with first argument
 * @input: the input from user
 * @loopcount: the loop count
 * @argv: the first argument vector(program name)
 *
 * Return: void
 */

void p_error(char *input, int loopcount, char **argv)
{
	char *error = _itoaa(loopcount);

	PRINTM(argv[0]);
	PRINTM(": ");
	PRINTM(error);
	free(error);
	PRINTM(": ");
	PRINTM(input);
	PRINTM(": not found\n");

}
