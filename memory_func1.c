#include "shell.h"

/**
 * free_pp - free pointer to pointer (double pointer)
 * @p: double pointer to be freed
 */

void free_pp(char **p)
{
	char **ptr = p;

	if (!p)
		return;

	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(p);
}


/**
 * _realloc - reallocates memory for a given pointer to a new size.
 * @ptr: pointer to null
 * @s: new size to reallocate
 *
 * Return: a new pointer allocated or -1 on faliure
 */

void *_realloc(void *ptr, unsigned int s)
{
	char *_newptr = (char *)_malloc(s);
	char *_ptr = (char *)ptr;
	void *pointer = NULL;
	int j = 0;

	if (!_ptr)
	{
		pointer = _newptr;
		return (pointer);
	}
	while (_ptr[j])
	{
		_newptr[j] = _ptr[j];
		j++;
	}
	_newptr[j] = '\0';
	pointer = (void *)_newptr;
	free(ptr);
	return (pointer);
}


/**
 * _malloc - function is used to allocate a block of memory
 * @s: number of bytes to be allocated
 * Return: a pointer to the first byte of the allocated memory or -1 on faliure
 */

void *_malloc(unsigned int s)
{
	char *ptr = malloc(s);
	void *_ptr = NULL;
	unsigned int j = 0;

	if (!ptr)
	{
		print_error(NULL, NULL, "ERROR ALLOCATING MEMORY");
		exit(-1);
	}
	while (j < s)
	{
		ptr[j] = '\0';
		j++;
	}
	_ptr = (void *)ptr;
	return (_ptr);
}

/**
 * _arlen - find length of a linked list
 * @n: first node in the list
 * Return: lenght of the list
 */

int _arlen(char **n)
{
	int j = 0;

	if (!n)
		return (j);

	while (*n)
		j++, n++;
	return (j);
}

/**
 * trim_spaces - is used to remove extra spaces from a given string.
 * it removes trsing from beginning and end of a given string
 * @str: pointer to the string to be modified
 * @strim: string to be trimed
 */

void trim_spaces(char **str, char *strim)
{
	char *new_str = _malloc(sizeof(char) * 1);
	char *input = strim;
	char *temp;
	int initial = 1, count = 1, index = 0;

	*new_str = '\0';
	while (*input)
	{
		if (*input == ' ' && initial)
			input++;
		else if (*input == ' ' && count)
			count++, input++;
		else if (*input != ' ')
		{
			temp = _malloc(sizeof(char) * (_strlen(new_str) + 3));
			if (!temp)
				exit(-1);
			_strcpy(temp, new_str);
			if (count > 1)
				temp[index] = ' ', index++;

			temp[index] = *input;
			temp[index + 1] = '\0';
			free(new_str);
			initial = 0, count = 1, new_str = temp, index++, input++;
		}
	}
	*str = new_str;
}

