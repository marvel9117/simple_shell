/**
 * handle_comment - handle comment by deleting the cooment from buffer
 * @buffer:pointer to the string input
 *
 * Return: the buffer without comment
 */

char *handle_comment(char *buffer)
{
	char *nocomments = buffer;

	if (*buffer == '#')
	{
		*buffer = '\n';
		*(buffer + 1) = '\0';
	}
	while (buffer && *buffer)
	{
		if (*buffer == '#' && *(buffer - 1) == ' ')
		{
			*(buffer - 1) = '\n';
			*buffer = '\0';
		}
		buffer++;
	}
	return (nocomments);
}
