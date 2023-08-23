#include "shell.h"
/**
 * **_parse - parse input user string into a 2 d array
 * @string: user input to parse
 *
 * Return: 2 dim array of  user input
 */
char **_parse(char *string)
{
	int bufsize = TOK_BUFSIZE;
	char *tok;
	char **tokens = malloc(bufsize * sizeof(char *));
	int n = 0;

	if (!tokens)
	{
		perror("allocation error\n");
		exit(EXIT_FAILURE);
	}

	tok = strtok(string, TOK_DELIM);
	while (tok != NULL)
	{
		tokens[n] = tok;
		n++;
		tok = strtok(NULL, TOK_DELIM);
	}
	tokens[n] = NULL;
	free(tok);
	return (tokens);
}
