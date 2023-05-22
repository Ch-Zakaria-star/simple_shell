#include "shell.h"

/**
 * _getenv - determining the environment value
 * @variable: variable
 * Return: environment value
 */

char *_getenv(char *variable)
{
	size_t i, j;
	char *envstr;
	size_t len = my_strlen(variable);

	for (i = 0; environ[i]; i++)
	{
		envstr = environ[i];

		for (j = 0; j < len; j++)
		{
			if (envstr[j] == variable[j])
				continue;
			break;
		}
		if (envstr[j] == '=' && j == len)
			return (_strstr(envstr, "="));
	}

	return (NULL);
}
