#include "shell.h"
/**
 * promt - simple shell in C
 *
 * Return: 0 on success
 */
 void promt(char **av, char **env)
 {
	int i, status;
	char *strng = NULL;
	size_t n=0;
	ssize_t num_char;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;
	
	while (1)
	{
		if(isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		
				
		num_char = getline(&strng, &n, stdin);
		if (num_char == -1)
		{
			free(strng);
			exit(EXIT_FAILURE);
		}
		i=0;
		while (strng[i])
		{
			if (strng[i] == '\n')
				strng[i] = 0;
			i++;
		}
		argv[0] = strng;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(strng);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		else
			wait(&status);	
		}
	}
 }
