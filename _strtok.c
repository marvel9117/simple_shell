#include "shell.h"

/*static variable on the first call*/
static char *NEW_TOKEN_PTR = "";
static int NOINIT_TKNPTR = 1;

/**
 * isdeli - check if character is a delimeter or not
 * @ch:  the character to evaluate
 * @deli: the character as delimeter
 *
 * Return: 1 if ch is a delimeter, 0 if not
 */

int isdeli(char ch, char *deli)
{
	while(*deli != '\0')
	{
		if (ch == *deli)
			return (1);
		deli++;
	}

	return(0);
}

/**
 * _strtok - breakes string into an individual token
 * @str: string to tokenize
 * @deli: the delimeter in which the string will be divided with
 *
 * Return: Tokenized string
 */

char *_strtok(char *str, char *deli)
{
	char *curent_pos;
	char *start_tkn = NULL;

	if(NOINIT_TKNPTR == 1)
	{
		NEW_TOKEN_PTR = NULL;
		NOINIT_TKNPTR = 0;
	}

	if ((str == NULL && NEW_TOKEN_PTR == NULL) || (str != NULL && str[0] == '\0'))
		return (NULL);

	if (str != NULL)
		NEW_TOKEN_PTR = str;

	for (curent_pos = NEW_TOKEN_PTR; *curent_pos != '\0'; curent_pos++)
	{
		if(!isdeli(*curent_pos, deli))
		{
			start_tkn = curent_pos;
			while(*curent_pos != '\0' && !isdeli(*curent_pos, deli))
				curent_pos++;

			NEW_TOKEN_PTR = curent_pos;
			*curent_pos = '\0';

			return(start_tkn);
		}
	}

	return (NULL);
}
