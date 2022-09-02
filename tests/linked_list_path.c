#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *str;
	struct node *next;
}
node;

int main(void)
{
	int i = 0;
	char *path = getenv("PATH");
	char *token;
	node head;
	node *new = &head;

	head.next = NULL;

	token = strtok(path, ":");

	while (token)
	{
		new->next = malloc(sizeof(node));
		if (!(new->next))
			return (1);
		new = new->next;
		new->str = token;
		new->next = NULL;

		token = strtok(NULL, ":");
	}
	new = &head;
	new = new->next;
	while(new)
	{
		printf("%s\n", new->str);
		new = new->next; 
	}

	return (0);
}
