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
	int status, i, j, fd;
	int file_exec = 0;

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

	buffer = handle_comment(buffer);
	i = 0;
	/*each single charcter in buffer and see if it a new line char*/
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			buffer[i] = '\0';
	i++;
	}


	j = 0;
	arg[j] = strtok(buffer, delim);
	while (arg[j] != NULL)
	{
		j++;
		arg[j] = strtok(NULL, delim);
	}
	
	/*path handling*/
	path = handleloc(arg[0]);

	if (path == NULL)
	{
		/*check for built in*/
		if (_builtincmd(arg) != 0)
		{
			_printstring("command not found\n");
			continue;
		}
		
	}

	child_ID = fork();
	if (child_ID < 0)
	{
		_printstring("Forking Failed");
		exit(0);
	}
	else if (child_ID == 0)
	{
		if (execve(path, arg, env) == -1)
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
