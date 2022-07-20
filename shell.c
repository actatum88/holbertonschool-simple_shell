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

	while(1)
	{
		printf("($) ");

		getline(&buffer, &bufsize, stdin);

		if (strcmp(buffer, "exit\n") == 0)
			break;
		else
		{
			printf("Got to the command section!");
			/*command = make_av(buffer);
			if (execute(command) == -1)
			break; */
		}
	}
}
