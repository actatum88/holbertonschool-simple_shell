#include "simpleshell.h"

/**
 * main - core function of the shell
 * Return: 0
 */

int main(void)
{
	char *line;
	char **command;
	int builtinrun = 0;
	int write_var;
	(void)write_var;

	while (1)
	{
		/*line = linereset(line);*/
		if (isatty(STDIN_FILENO) == 1)
			write_var = write(1, "($) ", 4);
		line = _getline(stdin);
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		command = make_av(line);
		builtinrun = builtinchecker(command);
		if (builtinrun >= 1)
		{
			free(line);
			free(command);
			line = NULL;
		}
		if (builtinrun == -1)
		{
			free(line);
			free(command);
			_exit(errno);
		}
		if (builtinrun == 0)
		{
			if (execute(command) == -1)
			{
				free(line);
				line = NULL;
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		if (line != NULL)
			free(line);
		
	}
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

	if (command[0] == NULL)
		return (1);
	is_kid = fork();
	if (is_kid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			free(command);
			return (-1);
		}

	}

	else
	{
		do {
			waitpid(is_kid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(command);
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
	char delim[] = {' ', '\n'};

	toks = malloc(sizeof(char) * BUFFER);
	if (toks == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	tok = strtok(str, delim);

	for (i = 0; tok != NULL; i++)
	{
		toks[i] = tok;
		tok = strtok(NULL, delim);
	}
	toks[i] = NULL;
	return (toks);
}

/**
 * _getline - custom getline function to receive input from stdin
 * @fp: file ptr that points to stdin
 * Return: line from stdin
 */

char *_getline(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int write_var;
	(void)write_var;


	if (line != NULL)
		free(line);
	read = getline(&line, &len, fp);
	if (isatty(STDIN_FILENO) == 1)
	{
		if (read == -1)
		{
			free(line);
			write_var = write(1, "\n", 1);
			exit(EXIT_SUCCESS);
			return (0);
		}
	}
	if (isatty(STDIN_FILENO) != 1)
	{
		if (read == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
	}
	return (line);
}
