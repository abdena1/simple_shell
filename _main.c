#include "shell.h"
/**
 * main - Entry point for the simple shell loop.
 * This function is the central loop of the simple shell program.
 * It manages user input, command parsing, execution, and output.
 * The loop continues until the user exits the shell.
 * Return: 0 on successful execution.
 */
int main(void)
{
	char *ligne;
	int sttus = 1;
	char **argmv;

	while (sttus == 1)
	{
		if (isatty(fileno(stdin)))
			printf(":$ ");

		ligne = read_line();
		argmv = _parse(ligne);
		sttus = cmd_handler(argmv);

		free(ligne);
		free(argmv);
	}
	exit(EXIT_SUCCESS);
}
