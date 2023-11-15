#include "shell.h"

/**
 * main - entry point of our program
 * @c: Argument count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int c, char **argv)
{
	char  **command, *buff = NULL;
	size_t buffsize = 0;
	ssize_t numchar;
	int status = 1, loopcount = 0, file_exec = 0;
	int fd;

	signal(SIGINT, signalhandler);
	fd = handle_args(c, argv, &file_exec);
	while (1)
	{
		loopcount++;
		if (isatty(STDIN_FILENO) == 1 && file_exec == 0)
			write(STDOUT_FILENO, "$ ", 2);


		numchar = getline(&buff, &buffsize, stdin);
		if (numchar == EOF)
		{
			free(buff);
			exit(0);
		}
		buff = handle_comment(buff);
		command = parse_input(buff);
		handle_dol_replacement(command);
		if (_strcmp(command[0], "exit") == 0)
		{
			exit_builtin(command, buff, argv, loopcount);
		}
		else
		{
			exec_cmd(command, buff, loopcount, argv);
		}
		free(command);
	}
	if (file_exec)
		close(fd);
	return (status);
}
