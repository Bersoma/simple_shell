#include <stdio.h>

extern char **environ;

int main(int argc, char **argv, char **envp)
{
	int i;
	
	for (i = 0; envp[i]; i++)
		printf("%s", envp[i]);

	return (0);
}
