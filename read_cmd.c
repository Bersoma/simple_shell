#include "main.h"

/**
* read_cmd - updates the global variables command[] and parameters[]
* from standard input
*
* Return: returns nothing
*/
int read_cmd(char command[], char *parameters[])
{
	int ret, i = 0, count = 0;
	size_t n = 0;
	char *token;
	char *line = NULL;

	ret = getline(&line, &n, stdin);
	fflush(stdin);
	if (ret == -1)
	{
		printf("\n");
		free(line);
		_exit(69);
	}
	else if (ret == 1)
	{
		free(line);
		return (-2);
	}	

	token = strtok(line, " \n");

	count = 0;
	while (token != NULL)
	{
		arr[count++] = strdup(token);
		token = strtok(NULL, " \n");
	}

	strcpy(command, arr[0]);

	for (i = 0; i < count; i++)
	{
		parameters[i] = arr[i];
	}
	parameters[count] = NULL;

	free(line);
	return (count);
}
