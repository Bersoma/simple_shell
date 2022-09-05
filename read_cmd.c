#include "main.h"

/**
* read_cmd - updates the variables command[] and parameters[] from stdin
* @command: the first parameter entered into the shell
* @parameters: every other parameter entered
* @argv: command-line arguments entered in the parent process
*
* Description:
* Return: returns nothing
*/
int read_cmd(char command[], char *parameters[], char *argv[])
{
	int ret, i = 0, count = 0;
	char *token, *line = NULL;

	ret = getline(&line, &n, stdin);
	fflush(stdin);

	if (exit_check(line, ret, argv, count) == 1)
		return (-2);

	token = strtok(line, " \n");

	count = 0;
	while (token != NULL)
	{
		arr[count++] = _strdup(token);
		token = strtok(NULL, " \n");
	}

	if (exit_check(line, ret, argv, count) == -2)
		return (-2);

	_strcpy(command, arr[0]);

	for (i = 0; i < count; i++)
	{
		parameters[i] = arr[i];
	}
	parameters[count] = NULL;

	free(line);
	return (count);
}
