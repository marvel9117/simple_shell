#include "shell.h"

/**
 * handle_dol_replacement - handle variable replacement within a list
 * of command arguments
 * @cmds: the array of the commands
 */

void handle_dol_replacement(char **cmds)
{
	int i;
	char *env_value;

	if(cmds[0] == NULL)
		return;

	for (i = 1; cmds[i] != NULL; i++)
	{
		if(cmds[i][0] != '$')
			continue;

		if(_strcmp(&cmds[i][1], "?") == 0)
		{
			free(cmds[i]);
			cmds[i] = _itoaa(getpid());
			return;
		}
		env_value = _getenv(&cmds[i][1]);
		if (env_value != NULL)
		{
			free(cmds[i]);
			cmds[i] = _strdup(env_value);
		}
	}
}


