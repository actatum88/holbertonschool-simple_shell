#include "simpleshell.h"


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
	num = numbuilt(builtin);
	for (i = 0; i < num; i++)
	{
		if (strcmp(toks[0], builtin[i].option) == 0)
		{
			status = (builtin[i].f)();
			return (status);
		}
	}
	return (1);

}

int numbuilt(builtins_t builtin[])
{
	unsigned int i;

	for (i = 0; builtin[i].option != NULL; i++)
		;
	return (i);
}


/*
 * _printenv
 *@
 *Return:
 */

int _printenv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
	return (1);
}

int _myexit(void)
{
	return (-1);
}
