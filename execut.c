#include "shell.h"
/**
 * execut - Execute non-built-in command.
 * @parse: 2D array holding parsed user input.
 * This func is designed to exec non-built-in cmds parsed from user input.
 * It takes a 2-dimensional array called @parse as its param, which contains
 * the parsed components of the user's input command.
 * Return: 1 on success.
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

