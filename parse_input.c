#include "shell.h"

/*
 * arg_count - Fuction that count the number of argument in an input string
 * @cmd_input: commandinputed as a string
 * @deli: delimeter that delimate the argument
 *
 * Return: count of argument in the string
 */

int arg_count(char *cmd_input, char *deli)
{
	char *token, *token_ptr;
	int count = 0;
	char *cmd_cpy = _strdup(cmd_input);

	token_ptr = cmd_cpy;
	while((token = strtok(token_ptr, deli)) != NULL)
	{
		count++;
		token_ptr = NULL;
	}
	free(cmd_cpy);

	return (count);
}

/**
 * parse_input - parse user input as an array of string
 * where element of the string represent each argument
 *
 * @cmd_input: The command sinput giving by user
 * @deli: Character that indicates the delimeter
 *
 * Return: Array of parsed argument
 */

char **parse_input(char *cmd_input, char *deli)
{
	char **arg, *tok, *tok_ptr;
	int i = 0;
	int count_arg = 0;
	char *str_cpy;

	if (cmd_input == NULL)
		err_ext("Error parsing the command\n");

	count_arg = arg_count(cmd_input, deli);
	arg = _malloc(sizeof(char *) * (count_arg + 1));

	str_cpy = _strdup(cmd_input);
	tok_ptr = str_cpy;
	for (i = 0; i < count_arg; i++)
	{
		tok = strtok(tok_ptr, deli);
		if (tok == NULL)
			break;
		tok_ptr = NULL;

		arg[i] = _strdup(tok);
	}

		free(str_cpy);

		return (arg);
}
