#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buf;
	char c;
	size_t char_num, bufsize = 131072;


	buf = malloc(bufsize * sizeof(char));
	if (!buf)
	{
		perror("Malloc failed!");
		return (1);
	}

	printf("$ ");
	char_num = getline(&buf, &bufsize, stdin);
	printf("%s", buf);

	free(buf);
	return (0);
}
