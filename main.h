#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

/* Global Variables */
extern char **environ;
char *arr[100];

/* Function Prototypes */
int read_cmd(char command[], char *parameters[]);
void free_arr(int count);

#endif /* MAIN_H */
