#include "shell.h"


int main(int c, char **argv, char **env)
{
	(void)c; (void) argv;
	char *prompt = "(feliamshell)$ ";
	char *buffer = NULL, *path;
	char *delim =  " \n";
	char *arg[1024];
	size_t buff_size = 0;
	ssize_t n_chars;
	pid_t child_ID;
	int status, i, j;
	

	while (1)
	{

	if(isatty(0))
	_printstring(prompt);

	n_chars = getline(&buffer, &buff_size, stdin);
	
	/*to check if it is EOF vaule*/
	if (n_chars == -1)
	{
	
		free(buffer);
		 exit(0);
	}
	i = 0;

	/*each single charcter in buffer and see if it a new line char*/
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			buffer[i] = 0;
	i++;
	}


	j = 0;
	arg[j] = strtok(buffer, delim);
	while (arg[j] != NULL)
	{
		j++;
		arg[j] = strtok(NULL, delim);
	}
	arg[j] = NULL;
	
	/*path handling*/
	path = get_locate(arg[0]);

	if (path == NULL)
	{
		/*check for built in*/
		if (_builtincmd(arg) != 0)
		{
			_printstring("command not founf\n");
			continue;
		}
		else
		/*_printstring("command not found\n");*/
		continue;
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

	/*_printstring(buffer);*/

	}


	free(buffer);
	free(path);
	
	return (0);
}
