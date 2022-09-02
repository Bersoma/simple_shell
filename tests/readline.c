#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	bool first = true;
	char *buf = NULL;
	size_t n = 10;

	do
	{
		if (!first)
			printf("%s", buf);
		printf("MySell>> ");
		first = false;
	}
	while(getline(&buf, &n, stdin) != -1);

	printf("Shell Exited\n");
	return(0);
}
