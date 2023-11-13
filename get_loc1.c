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
	char *filepath;
	int path_len = _strlen(path);
	int arg_len = _strlen(arg);

	filepath = malloc(sizeof(char) * (path_len + arg_len + 2));
	if (filepath == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	_strcpy(filepath, path);
	_strcat(filepath, "/");
	_strncat(filepath, arg, arg_len + 1);

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
	int flag = 127;
	char *str_cpy;

	if (cmds == NULL || cmds[0] == NULL || cmds[0][0] == '\0' || 
			cmds[0][0] == '/'
	   )
		return (127);

	if (access(cmds[0], F_OK) == 0)
		return (0);

	path_loc = _getenv("PATH");
	if (path_loc == NULL)
		return(127);

	str_cpy = _strdup(path_loc);
	pointer_cpy = str_cpy;
	while (1)
	{
		token = _strtok(pointer_cpy, ":");
		if (token == NULL)
			break;
		path = getlocation(token, cmds[0]);
		if (access(path, F_OK)  != -1)
		{
			free(cmds[0]);
			cmds[0] = path;
			flag = 0;
			break;
		}
		free(path);
	}
	free(str_cpy);
	return (flag);
}
