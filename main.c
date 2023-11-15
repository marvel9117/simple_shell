#include "shell.h"

/**
 * main - entry point of our program
 * @c: Argument count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int c, char **argv)
{
	(void)c;
	char  **command, *buff = NULL;
	size_t buffsize = 0;
	ssize_t numchar;
	int status = 1, loopcount = 0;

	while (1)
	{
		loopcount++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);


		numchar = getline(&buff, &buffsize, stdin);
		if (numchar == EOF)
		{
			free(buff);
			exit(0);
		}
		command = parse_input(buff);
		if (_strcmp(command[0], "exit") == 0)
		{
			exit(0);
		}
		else
		{
			exec_cmd(command, buff, loopcount, argv);
		}
	}

	free(buff);
	return (status);
}
