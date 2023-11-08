#include "shell.h"


int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printstring(char *str)
{
	int i = 0, count = 0;

	while(str[i])
	{
		count += _putchar(str[i]);
		i++;
	}
	return (count);
}


int main(int c, char **argv, char **env)
{
	(void)c; (void) argv;
	char *prompt = "(Shell)$ ";
	char *buffer = NULL;
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
		printf("arg[%d] is : %s\n",j , arg[j]);
		j++;
		arg[j] = strtok(NULL, delim);
	}



	child_ID = fork();
	if (child_ID < 0)
	{
		_printstring("Forking Failed");
		exit(0);
	}
	else if (child_ID == 0)
	{
		if (execve(arg[0], arg, env) == -1)
			_printstring("Command does not exit\n");
	}
	else
	{
		wait(&status);
	}

	/*_printstring(buffer);*/

	}


	free(buffer);
	
	return (0);
}
