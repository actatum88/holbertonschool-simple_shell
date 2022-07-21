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

char clear(void)
	{
		write(e[H/e[2Je[3J);
		return(0);
/*move the cursor to the top left corner*/
/*clear the screen, and clear the scrollback buffer/*
/*clears the terminal text , return 0 on success, -1 for error.*/
	}
}
