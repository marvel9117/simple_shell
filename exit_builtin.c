#include "shell.h"

/**
 * exit_builtin - checks if a command is "exit"
 * @comand: the tokenized commaned
 * @buff: line input
 * @argv: program name
 * @loopcount: loopcount
 * Return: exit status
 */

void exit_builtin(char **comand, char *buff, char **argv, int loopcount)
{
	int status, i = 0;

	if (comand[1] == NULL)
	{
		free(buff);
		free(comand);
		exit(EXIT_SUCCESS);
	}

	for (i = 0; comand[1][1]; i++)
	{
		if (_isalpha(comand[1][i]))
		{
			p_error(argv[0], loopcount, comand);
			return;
		}
	}
	status = _atoi(comand[1]);
	free(buff);
	free(comand);
	exit(status);
}
