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

		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			else
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		command = make_av(buffer);
		if (execute(command) == -1)
			break;
		builtinrun = builtinchecker(command);
		if (builtinrun == 0)
			break;
		if (builtinrun == -1)
			break;
	}
	free(buffer);

	return (0);
}

int execute(char **command)
{
	pid_t is_kid;
	int status;

	is_kid = fork();

	if (is_kid == 0)
	{
		if (execvp(command[0], command) == -1)
			perror("Error");
	exit(EXIT_FAILURE);
	}
	else if (is_kid < 0)
		perror("Error");
	else
	{
		do
		{
			waitpid(is_kid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

char **make_av(char *str)
{
	char **toks;
	char *tok;
	unsigned int i;

	toks = malloc(sizeof(char) * BUFFER);
	if (toks == NULL)
		exit(EXIT_FAILURE);
	tok = strtok(str, "\n\t\r ");

	for (i = 0; tok != NULL; i++)
	{
		toks[i] = tok;
		tok = strtok(NULL, "\n\t\r ");
	}
	toks[i] = NULL;
	return (toks);
}
