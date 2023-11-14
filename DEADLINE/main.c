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
	(void)argv;

	char **command, *buff = NULL;
	size_t buffsize = 0;
	ssize_t numchar;
	int status;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);


		numchar = getline(&buff, &buffsize, stdin);
		if (numchar == EOF)
		{
			free(buff);
			exit(0);
		}
		if (buff[numchar - 1] == '\n')
		{
			buff[numchar - 1] = '\0';
		}

		command = parse_input(buff);
		pid = fork();
		if (pid == -1)
		{
			perror("Error Forking");
			return (-1);
		}
		else if (pid == 0)
		{
			if (execve(command[0], command, environ) == -1)
				perror("Error");
		}
		wait(&status);
	}

	free(buff);
	return (0);
}
