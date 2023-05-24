<<<<<<< HEAD
#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
=======
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
>>>>>>> 15b5ee9c68a9731b611c9ec6f1cc63aec45998c2
}
