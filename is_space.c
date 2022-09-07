#include "main.h"

/**
* is_space - checks if a line is only whitespace
* @line: line read from standard input
*
* Return: returns 0 if false, 1 if true
*/
int is_space(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i + 1] == '\0')
			break;
		if (line[i] != ' ')
		{
			return (0);
		}
	}
	return (1);
}
