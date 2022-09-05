#include "main.h"

/**
* print_string - prints a string to stdout
* @s: a null-terminated string of characters
*
* Return: returns nothing
*/
void print_string(char *s)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
}
