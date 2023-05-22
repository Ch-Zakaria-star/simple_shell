#include "shell.h"

/**
 * loop - run continuous loop
 * Return: 0 on success
 */

int loop(void)
{
	int status = 1;

	do {
		if (isatty(0))
			_puts("fsh$ ");
		status = readline();
	} while (status);
	return (0);
}
