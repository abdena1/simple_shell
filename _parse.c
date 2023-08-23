#include "shell.h"
/**
 * _parse - Parse input user string into an array of tokens.
 * @string: User input to parse.
 * This function takes a user input string and tokenizes it based on whitespace
 * and delimiter characters. It dynamically allocates memory for each token and
 * creates an array of pointers to these tokens. The tokens are separated by
 * whitespace characters like space, tab, newlin,...
 * The last element of the array is set to NULL to indicate the end.
 * Return: Array of dynamically allocated tokens.
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
