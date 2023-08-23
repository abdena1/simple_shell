#include "shell.h"
/**
 * execut - execute non built-in parsed command
 * @parse: 2 d array holding parsed user input
 *
 * Return: 1 on success
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

