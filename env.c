#include "simple_shell.h"

/**
 * find_path - searching for environment paths
 * @name: path to find
 * Return: path
 */

char *find_path(char *name)
{
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		if (_strcmp(environ[x], name) == 0)
			break;
		else if (environ[x + 1] == NULL)
			perror("find path");
	}
	return (environ[x]);
}
