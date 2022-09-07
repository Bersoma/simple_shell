#include "main.h"

/**
* status_chk - checks if a program exists in the PATH
* @arr: an array of strings containing the command and arguments
* to the shell
*
* Return: nothing
*/
void status_chk(char *arr[])
{
	node head;

	printf("Called status check\n");
	linked_path(&head);

	(void) **arr;
}
