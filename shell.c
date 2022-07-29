#include "simpleshell.h"

/**
 * av - NULL terminated array of strings
 * ac - number of items in av
 */

int main(void)
{
	char *line;
	char **command;
	int builtinrun;
	int child;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "($) ", 4);
		line = _getline(stdin);
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}	
		command = make_av(line);
		builtinrun = builtinchecker(command);
		if (builtinrun == 0 || builtinrun == -1)
		{
			free(line);
			free(command);
			_exit(EXIT_SUCCESS);
		}
		child = execute(command);
		if (child == -1)
		{
				perror("Error");
				exit(EXIT_FAILURE);
		}
		free(line);
		free(command);
	}
	return (0);
}

int execute(char **command)
{
	pid_t is_kid;
	int status;

	is_kid = fork();

	if (is_kid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
			return (-1);
	free(command);
	exit(EXIT_FAILURE);
	}
	else if (is_kid < 0)
		perror("Error");
	else
	{
		do {
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
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	tok = strtok(str, "\n\t\r ");

	for (i = 0; tok != NULL; i++)
	{
		toks[i] = tok;
		tok = strtok(NULL, "\n\t\r ");
	}
	toks[i] = NULL;
	return (toks);
}

char *_getline(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, fp);
	if ( read == -1)
	{
		write(1, "\n", 1);
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
