#include "main.h"

/**
* print_ll - prints a linked list
* @head: the head of the linked list to be printed
*
* Return: returns nothing
*/
void print_ll(node *head)
{
	node *new = head;

	new = head;
	new = new->next;
	while (new)
	{
		printf("%s\n", new->str);
		new = new->next;
	}
}
