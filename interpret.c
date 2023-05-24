#include "simple_shell.h"

/**
 * interpreter - inteprets the given commands
 * @args: user supplied command arguments
 * Return: int
 */

int interpreter(char **args)
{
	struct stat sb;

	if (search_builtins(args) == 0)
		return (0);
	search(args);
	if (stat(args[0], &sb) == -1)
		return (-1);
	if (stat(args[0], &sb) == 0 && S_ISREG(sb.st_mode) == 0)
		return (-1);
	if (execution(args) == -1)
		return (-1);
	return (0);
}

/**
 * free_function - free memory allocations
 * @n: variable parameter count
 * @...: variable parameters
 * Return: void
 */

void free_function(int n, ...)
{
	char **dblptr;
	char *sglptr;
	va_list valist;
	int idx;

	va_start(valist, n);
	if (n == 1)
	{
		sglptr = va_arg(valist, char *);
		if (sglptr == NULL)
			return;
		free(sglptr);
	}
	if (n == 2)
	{
		dblptr = va_arg(valist, char **);
		if (dblptr == NULL)
			return;
		for (idx = 0; dblptr[idx] != NULL; idx++)
			free(dblptr[idx]);
		free(dblptr);
	}
	va_end(valist);
}

/**
 * err_mess - serves error messages
 * @argv: user inputed arguments
 * @args: interpreted arguments
 * Return: void
 */

void err_mess(char **argv, char **args)
{
	char *space = ": ";
	char *err1 = "not found";

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, err1, _strlen(err1));
	write(STDERR_FILENO, "\n", 1);
}
