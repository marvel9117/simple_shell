#include "shell.h"
#include "error.h"

/**
 * print_error - print error message to the standard error stream
 *
 * @prog: A pointer to a string that represents the name of the program
 * or command associated with the error.
 *
 * @cmdr: A pointer to an integer that stores the number
 * of commands run by the program.
 *
 * @msg: A pointer to a string that represents the specific error message.
 *
 * Return: nothing
 */

void print_error(char *prog, int *cmdr, char *msg)
{
	char *numofcmd;
	static int *cmdsrun;
	static char *programname;

	if (!msg)
	{
		cmdsrun =  cmdr;
		programname = prog;
		return;
	}
	if (!cmdr || !prog)
	{
		_write(-1, NULL, 0);
		_write(2, programname, _strlen(programname) + 1);
		_write(2, ": ", 2);
		numofcmd = _itoaa(*cmdsrun);
		_write(2, numofcmd, _strlen(numofcmd));
		free(numofcmd);
		_write(2, ": ", 2);
		_write(2, prog, _strlen(prog));
		_write(2, ": ", 2);
		_write(2, msg, _strlen(msg));
		_write(2, "\n", 1);
		_write(2, NULL, 0);
	}
}

/**
 * perror_exit - print error and provides information about the type of error
 * that occured
 * @msg: Error message
 */

void err_ext(char *msg)
{
	perror(msg);

	exit(errno);
	/*exit status that provide info about the error that occured*/
}
