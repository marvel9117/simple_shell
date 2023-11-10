#include "shell.h"

char *location(char *path,  char *arg)
{
	char *path_cpy, *pathtok, *filepath;
	char *delim = ":", *buff;
	

	path_cpy = strdup(path);


	pathtok = strtok(path_cpy, delim);

	while(pathtok != NULL)
	{
		filepath = malloc(strlen(pathtok) + strlen(arg) + 2);
		if (filepath == NULL)
		{
			perror("Error alocating memory");
			exit(EXIT_FAILURE);
		}

		strcpy(filepath, pathtok);
		strcat(filepath, "/");
		strcat(filepath, arg);

	if (access(filepath, X_OK) == 0)
	{
		/*free(path_cpy);*/
		return (filepath);
	}
	free(filepath);
	pathtok = strtok(NULL, delim);

	}
	free(path_cpy);

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
