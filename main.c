#include "main.h"

/**
* main - a simple command line interpreter
* Return: returns 0 on Success, 1 on error
*/
int main(int argc, char *argv[])
{
/*	int id, status, exit_status; */
	int ret, id, status, exit_status;
	char cmd[1024], command[1024], *parameters[100];

	process_counter = 0;
	(void) argc;
	while (1)
	{
		process_counter++;
		/* Display Prompt */
		if (isatty(STDIN_FILENO))
			printf("&-> ");
		fflush(stdout);

		ret = read_cmd(command, parameters, argv);
		if (ret == -2)
		{
		/* printf("You entered no characters\n");*/
			continue;
		}

		if ((id = fork()) != 0)
		{
			/*printf("\nParent's Id: %d\n\n", getpid());*/
			waitpid(id, &status, 0);
			free_arr(ret);

			if (WIFEXITED(status))
			{
				exit_status = WEXITSTATUS(status);
				/*printf("Exit Status: %d\n", exit_status);*/
				if (exit_status == 69)
				{
					exit(0);
					/*kill(0, SIGINT);*/
				}
			}
		}
		else
		{
			strcpy(cmd, command);
			execve(cmd, parameters, environ);
			free_arr(ret);
		}
		if (strcmp(command, "exit") == 0)
		{
			/*free_arr();*/
			_exit(0);
		}
	}

	printf("Thanks for using my Shell :)\n============================\n");
	 _exit(1);
}
