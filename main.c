#include "simple_shell.h"

/**
 * main - Program entry point
 * @argc: arguments count
 * @argv: terminal arguments parameters
 * Return: 0 for successful execution
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	int count;
	char *input;
	char **args;
	size_t size;

	signal(SIGINT, sigign);
	while (1)
	{
		input = NULL;
		size = 0;
		args = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		if (getline(&input, &size, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
		count = countargs(input);
		args = parser(input, count);
		if (_strcmp(args[0], "exit") == 0 &&
				(_strlen(args[0]) == _strlen("exit")))
		{
			if (exit_function(args, input) == -1)
				err_mess(argv, args);
		}
		else if (args != NULL && args[0] != NULL)
		{
			if (interpreter(args) == -1)
				err_mess(argv, args);
		}
		free_function(1, input);
		free_function(2, args);
	}
	return (0);
}
