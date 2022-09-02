#include "main.h"

/**
* read_cmd - updates the global variables command[] and parameters[]
* from standard input
*
* Return: returns nothing
*/
void read_cmd(void)
{
	int ret, i = 0, j = 0;
	size_t n = 0;
	char *arr[100], *token;

	line = NULL;

	ret = getline(&line, &n, stdin);
	if (ret == -1 || ret == 0)
	{
	/*	free(line);
		printf("\n");
	*/	_exit(0);
	}

	token = strtok(line, " \n");

	while (token != NULL)
	{
		arr[i++] = strdup(token);
		token = strtok(NULL, " \n");
	}

	strcpy(command, arr[0]);

	for (j = 0; j < i; j++)
		parameters[j] = arr[j];
	parameters[i] = NULL;
}
