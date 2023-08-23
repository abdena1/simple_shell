#include "shell.h"
/**
 * read_line - Read a line of user input from stdin.
 * The fction rd a ln of txt entered by user from the stdrd input.
 * uses dynamic mem allocation to store the input str and handles cases
 * where memory allocation or rd fails. The returned str should be freed
 * when it is no longer needed to prevent memory leaks.
 * Return: A dynamically allocated string containing the user's input.
 * Returns NULL on failure or upon reaching end-of-file.
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
