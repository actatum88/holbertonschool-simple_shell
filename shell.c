#include "simpleshell.h"

/**
 * av - NULL terminated array of strings
 * ac - number of items in av
 */

int main (void)
{
	char *buffer = NULL;
	char **command;
	size_t bufsize = 0;
	int builtinrun;

	while(1)
	{
		printf("($) ");

		if (getline(&buffer, &bufsize, stdin) == 1)
			continue;
		command = make_av(buffer);
		if (execute(command) == -1)
			break;
		builtinrun = builtinchecker(command);
		if (builtinrun == 0)
			continue;
		if (builtinrun == -1)
			break;
	}
	free(buffer);

	return (0);
}

int execute(char **command)
{
	pid_t is_kid;

	is_kid = fork();

	if (is_kid != 0)
	{
		wait(NULL);
		return (0);
	}
/*	if (is_kid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			perror("Error: ");
			return (-1);
		}
	}
*/
	return (0);
}

char **make_av(char *str)
{
	char **toks;
	char *tok;
	unsigned int i;

	toks = malloc(sizeof(char) * BUFFER);
	if (toks == NULL)
		exit(-1);
	tok = strtok(str, "\n\t\r ");

	for (i = 0; tok != NULL; i++)
	{
		toks[i] = tok;
		tok = strtok(NULL, "\n\t\r ");
	}
	toks[i] = NULL;
	return (toks);
}
