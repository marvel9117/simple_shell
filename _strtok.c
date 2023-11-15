#include "shell.h"

/**
 * isdeli - check if character is a delimeter or not
 * @ch:  the character to evaluate
 * @deli: the character as delimeter
 *
 * Return: 1 if ch match a delimeter, 0 if not
 */

unsigned int isdeli(char ch, const char *deli)
{
	if (deli == NULL)
		return (0);

	while (*deli != '\0')
	{
		if (ch == *deli)
			return (1);
		deli++;
	}

	return (0);
}

/**
 * _strtok - breakes string into an individual token based on specified deli
 * @str: string to tokenize
 * @deli: the delimeter in which the string will be divided with
 *
 * Return: Pointer to the next token or null if there is no more token
 */

char *_strtok(char *str, char *deli)
{
	char *current_pos;
	char *start_tkn;
	static char *original_str;

	if (deli == NULL)
		return (NULL);

	if (str != NULL)
		current_pos = str;
	else
		current_pos = original_str;

	if (current_pos == NULL || *current_pos == '\0')
		return (NULL);

	start_tkn = current_pos;

	while (*current_pos != '\0')
	{
		if (isdeli(*current_pos, deli) == 1)
		{
			*current_pos = '\0';
			current_pos++;
			if (*current_pos != '\0')
				original_str = current_pos;
			else
				original_str = NULL;
			return (start_tkn);
		}
		current_pos++;
	}
	return (start_tkn);
}
