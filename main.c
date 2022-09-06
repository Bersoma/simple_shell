#include "main.h"

/**
* main - a simple command line interpreter
* @argc: the number of command-line arguments passed to the program
* @arg: an array of strings containing every command-line argument
*
* Description: A simple UNIX command-line interpreter (Shell)
* made by Igbinosa Ephraim
*
* Example:
*	Usage: echo "ls -a" | ./hsh
*
* Return: exits with 0 on Success, 1 on error
*/
int main(int argc, char *arg[])
{
	int ret, id, status, exit_status, pc = 0;
	char cmd[1024], cm[1024], *param[100], *arr[100];

	(void) argc;
	while (1)
	{
		pc++;
		if (isatty(STDIN_FILENO))
			print_string("&-> ");

		ret = read_cmd(cm, param, arg, pc, arr);
		if (ret == -2)
			continue;

		id = fork();
		if (id != 0)
		{
			waitpid(id, &status, 0);
			free_arr(ret, arr);

			if (WIFEXITED(status))
			{
				exit_status = WEXITSTATUS(status);
				if (exit_status == 69)
					exit(0);
			}
		}
		else
		{
			_strcpy(cmd, cm);
			if (execve(cmd, param, environ) == -1)
				handle_errors();
			free_arr(ret, arr);
		}
	}
	 _exit(1);
}
