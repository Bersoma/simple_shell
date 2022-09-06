#include "main.h"

/**
* free_arr - frees the gloval variable *arr[] from its strdp'd strings
* @count: the number of strings in the global variable *arr[]
* @arr: an array that contains the command and parameters entered
*
* Return: returns nothing
*/
void free_arr(int count, char *arr[])
{
	int i;

	for (i = 0; i < count; i++)
		free(arr[i]);
}
