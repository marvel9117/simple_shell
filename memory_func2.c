#include "shell.h"

/**
 * _arrdup -  function that duplicates an array of strings
 * @src: source array to be duplicated
 * Return: a new array of duplicated strings(pointer to pointer of new array)
 */
char **_arrdup(char **src)
{
	char **temp = _malloc(sizeof(char *) * (_arlen(src) + 2));
	char **_temp = temp;

	while (*src)
		*_temp = _strdup(*src), _temp++, src++;

	*_temp = NULL;
	return (temp);

}
