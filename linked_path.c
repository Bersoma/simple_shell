#include "main.h"

/**
* linked_path - adds every directory in PATH variable to a linked list
* @head: the head of the linked list
*
* Return: returns nothing
*/
void linked_path(node *head)
{
	char *path = _getenv("PATH");
	char *token;
	node *new = head;

	head->next = NULL;

	token = strtok(path, ":");

	while (token)
	{
		new->next = malloc(sizeof(node));
		if (!(new->next))
			return;
		new = new->next;
		new->str = token;
		new->next = NULL;

		token = strtok(NULL, ":");
	}
	new = head;
	new = new->next;
	while (new)
	{
		printf("%s\n", new->str);
		new = new->next;
	}
}
