#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "unistd.h"

extern char **environ;

int main(void)
{
	int i = 0;
	char *cmd = "/bin/ls";
	char *args[] = {"ls", "-l", "/tmp", NULL};

	printf("In main!\n");
	
	while (i < 5)
	{
		if (fork() != 0)
		{
			printf("Parent's id = %d\n", getpid());
			wait(NULL);
		}
		else
		{
			printf("I'm child[%d], my id = %d, and my parent's id = %d\n", i + 1, getpid(), getppid());
			execve(cmd, args, environ);
		}
		i++;
	}


	printf("Still in main!\n");
}

