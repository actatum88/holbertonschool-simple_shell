#include "simpleshell.h"

/**
 * builtinchecker - takes in a token to check against struct builtins
 * if there is a match it will execute the function
 * @toks: token to be checked
 * Return: 1 on success.
 */

#define NUMBER_OF_BUILTINS 2

// This is a list of the builtin functions. This list is in the static memory.
// The NUMBER_OF_BUILTINS macro must be kept in sync with the number of functions
// supported.
builtins_t builtin[NUMBER_OF_BUILTINS] = { // Give me 8 bytes for a single point.
	{"exit", _myexit},
	{"env", _printenv},
};

enum builtins_exec_status builtinchecker(char **tokens)
{
	enum builtins_exec_status status;
	unsigned int i;

	char* firstToken = tokens[0];

	if (firstToken == NULL) {
	  // The list of strings was empty, as the first string pointed to a null pointer.
		return (0);
	}

	if (firstToken[0] == '\0') {
		// The first string is empty.
		return (0);
	}

	for (i = 0; i < NUMBER_OF_BUILTINS; i++)
	{
		if (strcmp(firstToken, builtin[i].option) == 0)
		{
			status = (builtin[i].f)();
			return (status);
		}
	}
	return ExecStatusNoop;
}

/**
 * _printenv - prints the environ global variable
 * Return: 1 on success.
 */

enum builtins_exec_status _printenv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
	return ExecStatusSuccess;
}

/**
 * _myexit - exit function that returns 0 to break main.
 * Return: 0
 */

enum builtins_exec_status _myexit(void)
{
	return ExecStatusExit;
}

#undef NUMBER_OF_BUILTINS
