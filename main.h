#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

/**
* struct node - a node structure for a linked
* list that holds every path in the PATH varaiable
* @str: a path in PATH
* @next: a pointer to the next node in the linked list
*/
typedef struct node
{
	char *str;
	struct node *next;
}
node;

/* Global Variables */
extern char **environ;

/* Function Prototypes */
void _putchar(char c);
void print_int(int n);
void print_string(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int read_cmd(char cm[], char *param[], char *arg[], int pc, char *arr[]);
void free_arr(int count, char *arr[]);
int ext_chk(char *line, int ret, char *arg[], int count, int pc, char *arr[]);
void handle_errors(void);
node *linked_path(void);

#endif /* MAIN_H */
