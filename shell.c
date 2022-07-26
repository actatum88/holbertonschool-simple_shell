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
char clear(void)
	{
	return(0);
/*move the cursor to the top left corner*/
/*clear the screen, and clear the scrollback buffer/*
/*clears the terminal text , return 0 on success, -1 for error.*/
	}


char **p_strtok(char* a_str, char delim)
		{
			char** result = 0;
			size_t count = 0;
			char* tmp = a_str;
			char* last_comma = 0;
			char* token;

			delim = ' ';
/* Count how many elements will be extracted */
			while (*tmp)
			{
				if (delim == *tmp)
				{
					count++;
					last_comma = tmp;
				}
				tmp++;
			}
/* Add space for trailing token. */
			count += last_comma < (a_str + strlen(a_str) - 1);
			count++;
/*Add space for terminating null string*/

			result = malloc(sizeof(char*) * count);
			if (result)
			{
				size_t idx = 0;
				token = strtok(a_str, &delim);
				while (token)
				{
					assert(idx < count);
					*(result +idx++) = strdup(token);
					token = strtok(0, &delim);
				}
				assert(idx == count -1);
				*(result + idx) = 0;
			}
			return (result);
		}
