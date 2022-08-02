#include "simpleshell.h"

/**
 * _strcpy - copies str1 to str2.
 * @str1: string to be copied
 * @str2: new string.
 * Return: void
 */

void _strcpy(char *str1, char *str2)
{
	int i = 0;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != '\n')
			str2[i] = str1[i];
	}
	str2[i] = '\0';
}
