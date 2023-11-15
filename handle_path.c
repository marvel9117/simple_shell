#include "shell.h"

/**
 * _memset - fill a block of memory with value
 * @ptr: pointer to the block of memory
 * @value: value to be set
 * @n: number of bytes to be filled
 *
 * Return: pointer.
 */

void *_memset(void *ptr, int value, size_t  n)
{
	unsigned char *byteptr = ptr;
	size_t i = 0;

	for (i = 0; i < n; ++i)
	{
		*byteptr++ = (unsigned char)value;
	}
	return (ptr);
}

/**
 * constructpath - Construct a path for command purpose
 * @exec: The comamnd which is executable
 * @dir: Directory of the command
 *
 * Return: Tokenized full path of command or NULL if failed
 */

char *constructpath(char *exec, char *dir)
{
	char *cmd;
	size_t length;

	length = _strlen(dir) + _strlen(exec) + 2;
	cmd = malloc(sizeof(char) * length);
	if (cmd == NULL)
	{
		return (NULL);
	}

	_memset(cmd, 0, length);

	_strcat(cmd, dir);
	_strcat(cmd, "/");
	_strcat(cmd, exec);

	return (cmd);
}

/**
 * handle_path - Search in $PATH for executable
 * @cmd: Tokenized input
 *
 * Return: 1 on failure and 0 on success.
 */

int handle_path(char **cmd)
{
	char *path, *dir, *commandpath;
	struct stat buffer;

	path = getenv("PATH");
	dir = _strtok(path, ":");

	while (dir != NULL)
	{
		commandpath = constructpath(*cmd, dir);
		if (stat(commandpath, &buffer) == 0)
		{
			free(*cmd);
			*cmd = _strdup(commandpath);
			free(commandpath);
			free(path);

			return (0);
		}
		free(commandpath);
		dir = _strtok(NULL, ":");
	}
	free(path);
	return (1);
}
