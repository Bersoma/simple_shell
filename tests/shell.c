#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	int r, i = 0, j;
	char *line = NULL, *token, *arg[50];
	char **arr;
	size_t n = 10;

	while(1)
	{
		i = 0;
		printf("#cisfun$ ");
		r = getline(&line, &n, stdin);
		if (r == -1)
		{
			free(line);
			break;
		}
		arr = malloc(sizeof(char *) * n);
		if (!arr)
		{
			free(line);
			printf("Malloc failed\n");
			return (1);
		}
		
		token = strtok(line, " \n");
		while (token != NULL)
		{
			arr[i++] = strdup(token);
			token = strtok(NULL, " \n");
		}
		for (j = 0; j < i; j++)
		{
			arg[j] = arr[j];
		}
		arg[i] = NULL;

		if (fork() != 0)
		{
			wait(NULL);
		}
		else
		{
			execve(arg[0], arg, environ);
		}

		for (j = 0; j < i; j++)
			free(arg[j]);		

		free(arr);
	}
	printf("Shell Exited\n");
	return(0);
}
