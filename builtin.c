<<<<<<< HEAD
#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: the structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes current directory process
 * @info: the structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
=======
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
>>>>>>> 15b5ee9c68a9731b611c9ec6f1cc63aec45998c2
	}
	return (0);
}

/**
<<<<<<< HEAD
 * _myhelp - changes current directory process
 * @info: the structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
=======
 * sigign - determining the interactivity of the program
 * @sig: signal input
 * Return: void
 */

void sigign(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
>>>>>>> 15b5ee9c68a9731b611c9ec6f1cc63aec45998c2
}
