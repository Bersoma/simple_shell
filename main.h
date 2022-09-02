#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* Global Variables */
extern char **environ;
char command[1024];
char *parameters[100];
char *line;

/* Function Prototypes */
void read_cmd(void);

#endif /* MAIN_H */
