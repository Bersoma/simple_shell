#include "main.h"

/**
* exit_check - checks the return value of getline to determine
* if the EOF character (Ctrl-D) has been pressed i.e when
* getline returns -1
* @line: a string that contains characters read from standard input
* @ret: the return vslue of getline
* @argv: command-line arguments entered in the parant process
* @count: the number of strings in the global variable arr[]
*
* Description: the function also checks if the command entered by the
* user exists, using the stat function
*
* Return: returns 1 if the user entered a blank command, -2 if the user
* entered a command that does not exist
*/
int exit_check(char *line, int ret, char *argv[], int count)
{
	if (ret == -1)
	{
		if (isatty(STDIN_FILENO))
			printf("\n");

		free(line);
		_exit(69);
	}
	else if (ret == 1)
	{
		free(line);
		return (1);
	}

	if (count > 0)
	{
		if (strcmp(arr[0], "exit") == 0)
		{
			free(line);
			free_arr(count);
			_exit(69);
		}

		if (stat(arr[0], &st) != 0)
		{
			printf("%s: %d: %s: not found\n", argv[0], process_counter, arr[0]);
			free(line);
			free_arr(count);
			return (-2);
		}
	}
	return (ret);
}
