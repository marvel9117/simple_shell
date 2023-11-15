#include "shell.h"

/**
 * _realloc - reallocates memory for a given pointer to a new size.
 * @ptr: pointer to reallocate memory
 * @s: new size to reallocate
 *
 * Return: Pointer to the reallocated memory  or NULL on faliure
 */

void *_realloc(void *ptr, unsigned int s)
{
	void *newptr;
	char *oldptr;
	char *new;
	unsigned int i;
	size_t old_size;

	if (ptr == NULL)
	{
		newptr = malloc(s);
		return (newptr);
	}

	old_size = get_block_size(ptr);

	newptr = malloc(s);
	if (newptr == NULL)
		return (NULL);

	oldptr = ptr;
	new = newptr;

	/*copy the content from old block to new block*/
	for (i = 0; i < old_size && i < s; i++)
	{
		new[i] = oldptr[i];
	}

	free(ptr); /*free old memory block*/
	return (newptr);
}


/**
 * get_block_size - Function to get size of an allocated block
 * @ptr: pointer to get the size of
 *
 * Return: size of the allocated bloack
 */

size_t get_block_size(void *ptr)
{
	size_t *block_ptr;

	if (ptr == NULL)
	{
		return (0);
	}
	block_ptr = ((size_t *)ptr) - 1;
	return (*block_ptr);
}
