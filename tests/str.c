#include <stdio.h>
#include <string.h>

int main(void)
{
	int i = 0;
	char *str = "                          \n";

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i + 1] == '\0')
			break;
		if (str[i] != ' ')	
		{
			printf("Doesn't equal\n");
			return (1);
		}
	}	
	printf("It Equals\n");
	return (0);
}
