#include "shell.h"

/**
 * _gertenv - Used to get the env var value
 * @varname: the enviromental var name 
 *
 * Return: The enviomental variable value
 */

char *_getenv(char *varname)
{
	int j;

	for (j = 0; __environ[j] != NULL; j++)
		if (_strncmp(__environ[j], varname, _strlen(varname)) == 0)
			return(&__environ[j][_strlen(varname) + 1]);

	return(NULL);
}

