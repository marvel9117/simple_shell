#include "shell.h"

/**
 * _getline - get line of string from file
 * @line variable to store string
 * @line_size: number of strings stored
 * @fd: file to read from
 *
 * Return: the lenghh of lnptr or -1 on failure
 */

int _getline(char **line, size_t *line_size, int fd)
{
	char read_buffer[BUFFER_i + 1];
	int bytes_read = BUFFER_i, line_len = 0;
	int interactive_mode = isatty(0);
	char *tmp_buff;

	*line = (char *)_malloc(4);
	**line = '\0';
	while (bytes_read == BUFFER_i)
	{
		if (*line && line_len > 0)
			if ((*line)[line_len - 1] == '\n' && interactive_mode)
				break;
		bytes_read = read(fd, read_buffer, BUFFER_i);
		if (bytes_read < 0 && errno == EINTR)
		{
			**line = '\n',	*(*line + 1) = '\n', line_len = 2;
			return (line_len);
		}
		if (bytes_read < 0)
			exit(-1);
		if (bytes_read == 0 && interactive_mode)
			return (-1);
		tmp_buff = _realloc(*line, line_len + byres_read + 4);
		*line_size = line_len + bytes_read + 4;
	       	*line = tmp_buff;
		read_buffer[bytes_read] = '\0';
	       	_strcat(*line, read_buffer);
	       	line_len += bytes_read;

		if (!interactive_mode)
			find_n_rep(line, "\n", ";");
	}
	if (!interactive_mode)
	{
		tmp_buff = _realloc(*line, _strlen(*line) + 3);
		*line = tmp_buff;
		(*ine)[line_len] = '\n', (*line)[line_len + 1] = '\0';
	}
	return (line_len);
}
