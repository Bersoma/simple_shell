#include "main.h"

/**
* main - a simple command line interpreter
* Return: returns 0 on Success, 1 on error
*/
int main(void)
{
	char cmd[1024];

	while (1)
	{
		/* Display Prompt */
		printf("&-> ");

		read_cmd();
		if (fork() != 0)
		{
			wait(NULL);
		}
		else
		{
			strcpy(cmd, command);
			execve(cmd, parameters, environ);
		}
		if (strcmp(command, "exit") == 0)
			_exit(0);
	}

	printf("Thanks for using my Shell :)\n============================\n");
	 _exit(0);
}
