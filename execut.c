#include "shell.h"
/**
 * execut - execute non built-in parsed command
 * @parsed: 2d array holding parsed user input
 * designed to facilitate execution of non-built-in cmd parsed from user input
 * Return: 1 on success
 */
int execut(char **parsed)
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		if (execvp(parsed[0], parsed) == -1)
			perror("unheard of");
		return (-1);
	}
	else if (child_pid < 0)
		perror("Fork error");
	else
	{
		wait(NULL);
	}
	return (1);
}
