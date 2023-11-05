#include "shell.h"

/**
 * main - the entry point for simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: always 0 (success).
 */


int main(int argc, char **argv)
{
	char *prompt = "#cisfun$ ";
	char *line;

	size_t n = 0;

	write(1, prompt,  11);
	getline(&line, &n, stdin);
	write(1, line, 1024);


	free(line);

	return (0);
}
