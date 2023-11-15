#include "shell.h"

/**
 * exec_cmd - function that execute command (execve,for,wait)
 * @cmd: tokenized command
 * @input: the input on buffer
 * @count: loop counter (exec time case of command not found)
 * @argv: argument vector
 * Return: 1 case command, -1 is wrong commant and 0 exec command
 */

int exec_cmd(char **cmd, char *input, int count, char **argv)
{
	int status;
	pid_t child_ID;
	(void)input;

	if (*cmd == NULL)
	{
		return (-1);
	}

	child_ID = fork();
	if (child_ID == -1)
	{
		perror("Error");
		return (-1);
	}

	if (child_ID == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			handle_path(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			p_error(cmd[0], count, argv);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
