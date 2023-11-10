#include "shell.h"

/**
 * handle_args - To check the number of argument passed
 * @ac: argument count
 * @argv: argument vector
 * @file_exec: int value used to check if the program should read input
 * from the keyboard or from a file base depending on the number of ac provided
 *
 * Return: The new file descriptor to file
 */

int handle_args(int ac, char **argv, int *file_exec)
{
	int fd = STDIN_FILENO;
	char *error_msg = "Error: more than one argument\n";

	if (ac > 2)
	{
		write(2, error_msg, strlen(error_msg));
		exit(1);
	}
	if (ac == 2)
	{
		fd = open(argv[1], O_RDONLY);
		*file_exec = 1;
	}
	if (fd == -1)
	{
		perror(argv[0]);
		exit(1);
	}

	return (fd);
}

