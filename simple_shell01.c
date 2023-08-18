#include "shell.h"

/**
 * main - simple shell in C
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			printf("\n");
			break; /* Handle EOF (Ctrl+D) */
		}

		line[strlen(line) - 1] = '\0'; /* Remove newline character */

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* Child process */
			if (execlp(line, line, (char *)NULL) == -1)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */
			wait(NULL); /* Wait for child process to finish */
		}
	}

	free(line);
	return (0);
}
