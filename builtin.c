#include "simple_shell.h"

/**
 * exit_function - function to free all memory allocations
 * before exiting program
 * @args: terminal passed arguments pointer
 * @line: unknown
 * Return: int
 */

int exit_function(char **args, char *line)
{
	int number;

	number = 0;
	if (args[1] != NULL)
		number = _atoi(args[1]);
	if (number == -1)
	{
		return (-1);
	}
	else
	{
		free_function(1, line);
		free_function(2, args);
		exit(number);
	}
}

/**
 * print_env - printing the OS environment
 * Return: 0 for success
 */

int print_env(void)
{
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		write(STDOUT_FILENO, environ[x], strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * sigign - determining the interactivity of the program
 * @sig: signal input
 * Return: void
 */

void sigign(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
