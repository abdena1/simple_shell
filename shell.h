#ifndef SHELL_H
#define SHELL_H

/*library*/

#include <stdio.h>

#include <stdarg.h>

#include <unistd.h>

#include <stdlib.h>

#include <string.h>

#include <sys/wait.h>

/*define*/

#define MAXTOK 64

#define TOK_BUFSIZE 64

#define BUFFER 1024

#define TOK_DELIM " \n\t\r"

#define EXIT "exit\n"

/*integer*/

int execut(char **parsed);
int cmd_handler(char **parsed);

/*char*/

char **_parse(char *str);
char *read_line(void);

extern char **environ;

#endif /* end SHELL_H */
