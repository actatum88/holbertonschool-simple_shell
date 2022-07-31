#include "simpleshell.h"

/**
 * builtinchecker - takes in a token to check against struct builtins
 * if there is a match it will execute the function
 * @toks: token to be checked
 * Return: 1 on success.
 */

int builtinchecker(char **toks)
{
	int status;
	unsigned int num;
	unsigned int i;

	builtins_t builtin[] = {
		{"exit", _myexit},
		{"env", _printenv},
		{NULL, NULL},
	};

	if (toks[0] == NULL)
		return (1);
	if (*toks[0] == '\0')
		return (1);
	num = numbuilt(builtin);
	for (i = 0; i < num; i++)
	{
		if (_strcmp(*toks, builtin[i].option) == 0)
		{
			status = (builtin[i].f)();
			return (status);
		}
	}
	return (1);

}

/**
 * numbuilt - counts the number of builtins
 * @builtin: builts to count
 * Return: number of builtins to iterate through
 */

int numbuilt(builtins_t builtin[])
{
	unsigned int i;

	for (i = 0; builtin[i].option != NULL; i++)
		;
	return (i);
}


/**
 * _printenv - prints the environ global variable
 * Return: 1 on success.
 */

int _printenv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
	return (1);
}

/**
 * _myexit - exit function that returns 0 to break main.
 * Return: 0
 */

int _myexit(void)
{
	return (0);
}
