#include "shell.h"


int main(int c, char **argv, char **env)
{
	(void)c; (void) argv;
	char *buffer = NULL, *path;
	char *delim =  " \n";
	char *arg[1024];
	size_t buff_size = 0;
	ssize_t num_chars;
	pid_t child_ID;
	int status, i, j, fd, err = 0;
	int file_exec = 0;
	char **commands;

	signal(SIGINT, signalhandler);
	fd = handle_args(c, argv, &file_exec);
	

	while (1)
	{

	if(isatty(STDIN_FILENO) == 1 & file_exec == 0)
		write(1, "$ ", 2);

	num_chars = getline(&buffer, &buff_size, stdin);
	
	/*to check if it is EOF vaule*/
	if (num_chars == EOF)
	{
	
		free(buffer);
		 exit(0);
	}

	//buffer = handle_comment(buffer);

	_strtok(buffer, "\n");

	commands = parse_input(buffer, " ");

	child_ID = fork();
	if (child_ID < 0)
	{
		_printstring("Forking Failed");
		exit(0);
	}
	else if (child_ID == 0)
	{
		err = handleloc(commands);
		if (execve(commands[0], commands, env) == -1)
			_printstring("Command does not exit\n");
	}
	else
	{
		wait(&status);
	}

	}


	free(buffer);
	free(path);
	
	return (0);
}
