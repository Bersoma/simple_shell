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

/* Global Variables */
extern char **environ;
char *arr[100];
int process_counter;
size_t n;
struct stat st;

/* Function Prototypes */
int read_cmd(char command[], char *parameters[], char *argv[]);
void free_arr(int count);
int exit_check(char *line, int ret, char *argv[]);

#endif /* MAIN_H */
