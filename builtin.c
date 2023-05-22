#include "shell.h"

/**
 * _env - printing environmental variables
 * @av: user input comands
 * @lineptr: user input string
 * Return: always 1
 */

int _env(char **av, char *lineptr)
{
	size_t i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}

	freeLAP(av, lineptr, NULL);

	return (1);
}

/**
 * exit_shell - exit shell
 * @av: tokenized input command
 * @lineptr: user input command string
 * Return: Always 0
 */

int exit_shell(char **av, char *lineptr)
{
	freeLAP(av, lineptr, NULL);
	exit(0);
}

