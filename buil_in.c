#include "shell.h"
/**
 * cmd_handler - compare commands with built-in list
 * commands and calls execut function if not found in built-ins list
 * @parse: 2 dim array holding user input
 *
 * Return: -1 if user put "exit"
 *      1 other else
*/
int cmd_handler(char **parse)
{
	int switch_arg = 0, sttus = 0, n;
	char **env = environ;
	char *cmd_list[3];

	cmd_list[0] = "exit";
	cmd_list[1] = "cd";
	cmd_list[2] = "env";
	for (n = 0; n < 3; n++)
	{
		if (strcmp(parse[0], cmd_list[n]) == 0)
			switch_arg = n + 1;
	}
	switch (switch_arg)
	{
		case 1:
			return (-1);
		case 2:
			if (parse[1] == NULL)
				perror("too few arguments");
			else
			{
				if (chdir(parse[1]) != 0)
					perror("hsh");
			}
			return (1);
		case 3:
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			return (1);
		default:
		sttus = execut(parse);
		return (sttus);
	}
	return (0);
}
