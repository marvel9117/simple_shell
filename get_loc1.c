#include "shell.h"

/**
 * getlocation -create a full path to a file from env variable
 * @path: directory path representation
 * @arg: file we are looking for
 *
 * Return: Created string patth
 */

char *getlocation(char *path,  char *arg)
{
	char *path_cpy, *pathtok, *filepath;
	char *delim = ":", *buff;
	

	path_cpy = strdup(path);
	pathtok = strtok(path_cpy, delim);

	filepath = malloc(sizeof(char *) * (strlen(pathtok) + strlen(arg) + 2));
	if (filepath == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	strcpy(filepath, pathtok);
	strcat(filepath, "/");
	strncat(filepath, arg, strlen(arg + 1));

	return (filepath);
}

/**
 * handleloc - check if the command to be executed can be found in path
 * @cmds: strings that containes the argument
 * Return: 0 if success and -1 on error
 */

int handleloc(char **cmds)
{
	char *path, *path_loc;
	char *token, *pointer_cpy;
	int flag =0;
	char *str_cpy;

	if (cmds == NULL || cmds[0] == NULL || cmds[0][0] == '\0' || 
			cmds[0][0] == '/'
	   )
		return (127);

	if (access(cmds[0], F_OK) == 0)
		return (0);

	path_loc == getenv("PATH");
	if (path_cpy == NULL)
		return(127);

	str_cpy = strdup(path_loc);
	pointer_cpy = str_cpy;
	while (1)
	{
		token = strtok(token, cmds[0]);
		if (access(path, F_OK)  != -1)
		{
			free(cmds[0]);
			cmds[0] = path;
			flag = 0;
			break;
		}
		free(path);
	}
	free(strcpy);
	return (flag);
}
