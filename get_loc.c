#include "shell.h"

char *location(char *path,  char *arg)
{
	char *path_cpy, *pathtok, *filepath;
	char *delim = ":", *buff;
	

	path_cpy = strdup(path);


	pathtok = strtok(path_cpy, delim);

	filepath = malloc(strlen(arg) * (strlen(pathtok) + 2));

	while(pathtok != NULL)
	{
		strcpy(filepath, pathtok);
		strcat(filepath, "/");
		strcat(filepath, arg);
		strcat(filepath, "\0");

	if (access(filepath, X_OK) == 0)
	{
		/*free(path_cpy);*/
		return (filepath);
	}
	pathtok = strtok(NULL, delim);

	}
	free(filepath);
	free(path_cpy);
	/*check the file if it exists(status) and return 0*/
	/*if (stat(arg, &buff) == 0)
		return (arg);*/

	return (NULL);
}

/*get location function*/
char *get_locate(char *arg)
{
	char *path;

		path = getenv("PATH");

	if (path)
	{
		path = location(path, arg);
		return (path);

	}
	return (NULL);
}
