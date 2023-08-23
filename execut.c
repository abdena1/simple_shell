#include "shell.h"
/**
<<<<<<< HEAD
 * execut - execute non built-in command parsed
 * @parse: 2 dim array taking user input parse
 * Return: 1 if success
=======
 * execut - execute non built-in parsed command
 * @parsed: 2d array holding parsed user input
 * designed to facilitate execution of non-built-in cmd parsed from user input
 * Return: 1 on success
>>>>>>> 078e2fdb72d54835e231165e4f027c9980db4b44
 */
int execut(char **parse)
{
	pid_t child_pid = fork();

		if (child_pid == 0)
		{
			if (execvp(parse[0], parse) == -1)
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

