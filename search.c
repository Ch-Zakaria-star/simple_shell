#include "simple_shell.h"

/**
 * search - searching for a given command
 * @args: command and arguments
 * Return:  0 for success
 */

int search(char **args)
{
	char **command = NULL;
	int count;
	char *hold;

	hold = _strdup(find_path("PATH"));
	if (hold == NULL)
		return (-1);
	count = countargs(hold);
	if (count == -1)
	{
		free_function(1, hold);
		return (-1);
	}
	edit_equal_sign(&hold);
	command = parser(hold, count);
	if (command == NULL)
	{
		free_function(1, hold);
		return (-1);
	}
	if (search_dirs(command, args) == -1)
	{
		free_function(1, hold);
		return (-1);
	}
	free_function(1, hold);
	return (0);
}

/**
 * search_builtins - searches for custom functions
 * @args: user command to execute
 * Return: 0 if command is not found, 1 if found
 */

int search_builtins(char **args)
{
	builtin builtins[] = {
		{"env", print_env},
		{NULL, NULL}
	};

	int x, check;

	check = 0;
	for (x = 0; builtins[x].name != NULL; x++)
	{
		if (_strcmp(builtins[x].name, args[0]) == 0 &&
				_strlen(builtins[x].name) == _strlen(args[0]))
			check = builtins[x].func();
	}
	if (builtins[x].name == NULL)
		return (-1);
	return (check);
}

/**
 * search_dirs - searches in the given path for matching files
 * @command: command to find
 * @args: contains the environment paths to search
 * Return: 0 for succes
 */

int search_dirs(char **command, char **args)
{
	char *cwd;
	int x;
	struct stat sb;

	cwd = getcwd(NULL, 0);
	for (x = 0; command[x] != NULL; x++)
	{
		if (args[0][0] == '/')
			break;
		if (_strcmp(args[0], "./") == 0)
			break;
		chdir(command[x]);
		if (stat(args[0], &sb) == 0)
		{
			args[0] = _strconcat(command[x], args[0]);
			if (args[0] == NULL)
			{
				free_function(1, cwd);
				free_function(2, command);
				return (-1);
			}
			break;
		}
	}
	chdir(cwd);
	free_function(1, cwd);
	if (command[x] == NULL)
	{
		free_function(2, command);
		return (-1);
	}
	free_function(2, command);
	return (0);
}
