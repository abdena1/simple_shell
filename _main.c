#include "shell.h"
/**
 * main - loop of  simple shell
 * Return: 0 if  success.
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
