#include "shell.h"
/**
 * main - simple shell in C
 *
 * Return: 0 on success
 */
int main(int ac, char**av, char **env)
{
	if (ac==1)
		promt(av, env);
	return (0);
}
