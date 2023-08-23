#include "shell.h"
/**
 * *read_line - get iput of user as a string
 * Return: user input of a string
 */

char *read_line(void)
{
	size_t bufer = 0;
	char *ligne = NULL;

	if (getline(&ligne, &bufer, stdin) == -1)
	{
		free(ligne);
		exit(EXIT_SUCCESS);
	}
	return (ligne);
}
