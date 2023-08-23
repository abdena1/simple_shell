#ifndef SHELL_H
#define SHELL_H

/* library */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void promt(char **av, char **env);

#include <sys/types.h>
#define PATH_MAX_LENGTH 1024
#define MAX_COMMAND 10

#endif /* end of shell_h*/
