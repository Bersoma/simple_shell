#include "main.h"

/**
* read_cmd - updates the variables command[] and parameters[] from stdin
* @cm: the first parameter entered into the shell
* @param: every other parameter entered
* @arg: command-line arguments entered in the parent process
* @pc: the process id of the shell
* @arr: an array that contains the command and parameters entered
*
* Description:
* Return: returns -2 to restart the while loop in main
* returns count on success
*/
int read_cmd(char cm[], char *param[], char *arg[], int pc, char *arr[])
{
	int ret, i = 0, count = 0;
	char *token, *line = NULL;
	size_t n;

	ret = getline(&line, &n, stdin);
	fflush(stdin);

	if (ext_chk(line, ret, arg, count, pc, arr) == 1)
		return (-2);

	token = strtok(line, " \n");

	count = 0;
	while (token != NULL)
	{
		arr[count++] = _strdup(token);
		token = strtok(NULL, " \n");
	}

	/* status_chk(arr); */
	if (ext_chk(line, ret, arg, count, pc, arr) == -2)
		return (-2);

	_strcpy(cm, arr[0]);

	for (i = 0; i < count; i++)
	{
		param[i] = arr[i];
	}
	param[count] = NULL;

	free(line);
	return (count);
}
