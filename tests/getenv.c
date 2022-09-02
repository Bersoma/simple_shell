#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name);

int main(int argc, char **argv, char **envp)
{
	char *p = getenv(argv[1]);
	char *p2;

	printf("Standard getenv: %s\n", p);

	p2 = _getenv(argv[1]);
	printf("My func's _getenv: %s\n", p2);

	return (0);
}

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
