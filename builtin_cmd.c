#include "shell.h"

/* a manual command we are implementing , we don't have to use execve*/

int _builtincmd(char **arg)
{
	if (strcmp(arg[0], "exit") == 0)
	{
		_printstring("Exiting shell... \n");
		exit(0);
	}
	else if (strcmp(arg[0], "cd") == 0)
	{
		if (arg[1] == NULL)
			chdir(getenv("HOME"));
		else
		{
			chdir(arg[1]);
		}
	}

	return (0);

}
