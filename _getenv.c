#include "main.h"

/**
* _getenv - gets an environment variable
* @name: the name of the environment variable to get
*
* Return: returns a string containing the value of the variable
*/
char *_getenv(const char *name)
{
	int i = 0;
	char *token;

	while (environ[i])
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
		{
			return (strtok(NULL, "="));
		}
		i++;
	}

	return (NULL);
}
