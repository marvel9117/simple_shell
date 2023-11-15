#include "shell.h"
/**
 * free_both - Free two aprray of character pointer
 * @cmd array pointer
 * @buff: charcter pointer
 * Return: nothing
 */

void free_both(char **cmd, char *buff)
{
	free(cmd);
	free(buff);
	cmd = NULL;
	buff = NULL;
}
