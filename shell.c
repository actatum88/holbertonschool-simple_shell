#include "simpleshell.h"

/**
 * main - core function of the shell
 * Return: 0
 */

int main(void)
{
	char *line;
	char **command;
	int builtinrun;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "($) ", 4);
		line = _getline(stdin);
		if (line[0] == '\n')
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
		/* if (execute(command) == -1)
		{
			free(line);
			free(command);
			perror("Error");
			exit(EXIT_FAILURE);
		}*/
		free(line);
		free(command);
	}
	free(command);
	return (0);
}

/**
 * execute - fork function that creates child
 * @command: command the function receives to be executed
 * Return: 1 on success or EXIT on failure.
 */

int execute(char **command)
{
	pid_t is_kid;
	int status;
	/* char **envp == environ; */
	int i = 0;

	is_kid = fork();

	if (command[i] == NULL)
		return (1);
	if (is_kid == 0)
	{
		if (execve(command[i], command, NULL) == -1)
		{
			free(command);
			perror("Error");
			exit(EXIT_FAILURE);
		}

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

/**
 * make_av - creates an argument variable to be passed into the
 * builtin checker
 * @str: the received command from stdin to tokenized into an arg
 * Return: argument token
 */

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

/**
 * _getline - custom getline function to receive input from stdin
 * @fp: file pointer that points to stdin
 * Return: the read line from stdin.
 */

char *_getline(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, fp);
	if (read == -1)
	{
		write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
