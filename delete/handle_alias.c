#include "shell.h"

static int stat_alias = 1;
static list_t *headof_alias;

/**
 * get_headofalias - return the pointer of alaias head
 *
 * Return: pointer to alias head
 */

list_t **get_headofalias()
{
	if(stat_alias == 1)
	{
		headof_alais = 0;
	}
	return (&alias_head);
}

/**
 * hadle_alias - handling the alias
 * @cmds:commands
 */

void handle_alias(char *cmds)
{
	list_t *currentalias;
	list_t **alias_addres = get_headofalias();
	int len = _strlen(cmds[0]);

	char *str;
	char tmp_buff[MAX_BUFFER_SIZE];
	int i, len_alias =0;

	if (cmds[0] == NULL)
		return;

	for (i = 0; i < 250; i++)
		tmp_buff[i] = '\0";

	for (

