#include "shell.h"

/**
 * parse_input - Tokenizing an input string into an array of strings.
 * @input: The user input to parse
 * Return: Array of pointers to tokens.
 */

char **parse_input(char *input)
{
	char **tokns;
	char *tok;
	int i;
	int buffsize = BUFFSIZE;
	char **tmp;

	if (input == NULL)
		return (NULL);

	tokns = malloc(sizeof(char *) * buffsize);
	if (tokns == NULL)
	{
		perror("hsh: allocation error");
		return (NULL);
	}

	i = 0;
	tok = _strtok(input, " \t\n\r\a");
	while (tok != NULL)
	{
		tokns[i] = tok;
		i++;

		if (i >= buffsize)
		{
			buffsize += BUFFSIZE;
			tmp = _realloc(tokns, sizeof(char *) * buffsize);
			if (tmp == NULL)
			{
				perror("hsh: allocation error");
				free(tokns);
				return (NULL);
			}
			tokns = tmp;
		}
		tok = _strtok(NULL, "\t\n\r\a");
	}
	tokns[i] = NULL;

	return (tokns);
}

