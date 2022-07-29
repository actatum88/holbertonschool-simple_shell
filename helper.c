#include "simpleshell.h"

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

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

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
