#include "main.h"

/**
* exit_check - checks the return value of getline to determine
* if the EOF character (Ctrl-D) has been pressed i.e when 
* getline returns -1
* @line: a string that contains characters read from standard input
* @ret: the return vslue of getline
*
* Description: the function also checks if the command entered by the
* user exists, using the stat function
*
* Return: returns (nil)
*/
int exit_check(char *line, int ret, char *argv[])
{
	(void) **argv;

	if (ret == -1)
	{
		if (isatty(STDIN_FILENO)
			print("\n");

		free(line);
		_exit(69);
	}
	return (1);
}
