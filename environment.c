#include "simpleshell.h"

/*
 * _printenv
 *@
 *Return:
 */

int main(int ac, char **av, char **env)
{
	while(*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return 0;
}
