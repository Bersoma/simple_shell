#include "main.h"

/**
* main - a simple command line interpreter
* @argc: the number of command-line arguments passed to the program
* @argv: an array of strings containing every command-line argument
*
* Description: A simple UNIX command-line interpreter (Shell)
* made by Igbinosa Ephraim
*
* Example:
*	Usage: echo "ls -a" | ./hsh
*
* Return: exits with 0 on Success, 1 on error
*/
int main(int argc, char *argv[])
{
	int ret, id, status, exit_status;
	char cmd[1024], command[1024], *parameters[100];

	process_counter = 0;
	(void) argc;
	while (1)
	{
		process_counter++;
		if (isatty(STDIN_FILENO))
			print_string("&-> ");

		ret = read_cmd(command, parameters, argv);
		if (ret == -2)
			continue;

		id = fork();
		if (id != 0)
		{
			waitpid(id, &status, 0);
			free_arr(ret);

			if (WIFEXITED(status))
			{
				exit_status = WEXITSTATUS(status);
				if (exit_status == 69)
					exit(0);
			}
		}
		else
		{
			_strcpy(cmd, command);
			execve(cmd, parameters, environ);
			free_arr(ret);
		}
	}
	 _exit(1);
}
