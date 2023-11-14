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
	char *error;

	PRINTM(argv[0]);
	PRINTM(": ");
	error = _itoaa(loopcount);
	PRINTM(error);
	free(error);
	PRINTM(": ");
	PRINTM(input);
	PRINTM(": not found\n");

}
