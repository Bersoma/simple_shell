#include <stdio.h>

extern char **environ;

int main(int argc, char **argv, char **envp)
{

	printf("Address of env: %p\n", &envp);
	printf("Address of environ: %p\n", &environ);

	return (0);
}
