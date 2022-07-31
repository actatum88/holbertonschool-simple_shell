#include "simpleshell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: the difference in characts between strings
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0, k = 0;

	while (s1[i] != '\0' || s2[j] != '\0')
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else if (s1[i] != s2[j])
		{
			k = s1[i] - s2[j];
			break;
		}
	}
	return (k);
}

/**
 * _strlen - counts lenght of string
 * @s: string to be counted
 * Return: length of string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _getenv - ...
 * @name: name of the environment path
 * Return: environment path on success, NULL on failure
 */

char *_getenv(const char *name)
{
	unsigned int i = 0;
	int check;
	int len = _strlen((char *)name);

	while (environ[i])
	{
		check = _strcmp(environ[i], (char *)name);
		if (check == 0)
			return (environ[i] + len + 1);
		i++;
	}
	return (NULL);
}

/**
 * _putchar - writes a character
 * @c: character to be written
 * Return: written character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
