#include "shell.h"
/**
 * main - simple shell in C
 *
 * Return: 0 on success
 */
int main(void)
{
	char *ligne = NULL;
	size_t len_n = 0;

	while (1)
	{
	printf("#cisfun$ ");
		if (getline(&ligne, &len_n, stdin) == -1)
		{
			printf("\n");
			break; /* Handle EOF (Ctrl+D) */
		}
		ligne[strlen(ligne) - 1] = '\0'; /* Remove newline character */
		pid_t proc_id = fork();
		char *args[] = {ligne, NULL};

		if (proc_id == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (proc_id == 0)
		{
			/* Child process */
			if (execve(ligne, args, NULL) == -1)
			{
				fprintf(stderr, "%s: No such file or directory\n", ligne);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */
			wait(NULL); /* Wait for child process to finish */
		}
	}
	return (0);
}
