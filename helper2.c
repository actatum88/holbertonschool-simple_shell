#include "simpleshell.h"

void _strcpy(char *str1, char *str2)
{
	int i = 0;

	for(i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != '\n')
			str2[i] = str1[i];
	}
	str2[i] = '\0';
}

void _cpystr(char *str1, char **str2)
{
	char **str = &str1;
	int i = 0;
	
	for (i = 0; *str[i] != '\0'; i++)
	{
		str2[i] = str[i];
	}
	str2[i] = '\0';
}
