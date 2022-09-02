#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i, j;
	char d[] = " ";
	int n;
	int max = 0;
	char **arr;
	char *ar;
	for (i = 1; i < argc; i++)
	{
		n = strlen(argv[i]);

		if (n > max)
			max = n;
	}

	printf("The longest word is: %d letters\n", max);

	arr = malloc(sizeof(char) * (argc - 1));
	if (!arr)
		return (1);

	for (i = 0; i < (argc - 1); i++)
		arr[i] = malloc(sizeof(char) * max);

	for (i = 0



/*	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, d);
	}
*/
	return (0);
}
