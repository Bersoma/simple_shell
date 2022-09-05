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
void _putchar(char c);
void print_int(int n);
void print_string(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int read_cmd(char command[], char *parameters[], char *argv[]);
void free_arr(int count);
int exit_check(char *line, int ret, char *argv[], int count);

#endif /* MAIN_H */
