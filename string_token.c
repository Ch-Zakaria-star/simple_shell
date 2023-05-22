#include "shell.h"

/**
 * _strtok - tokenizing a string
 * @str: string to be tokenized
 * @delim: delimiter charaters to delimit string by
 * Return: non-empty string
 */

char *_strtok(char *str, const char *delim)
{
	static char *updated_str = NULL;
	char *token;
	int i, j;

	if (!str && delim)
	{
		if (!updated_str)
			return (NULL);
		updated_str = skip_preceeding_delim(updated_str, delim);
		str = updated_str;
	}
	if (str && !updated_str)
	{
		str = skip_preceeding_delim(str, delim);/*skip pre delimiters*/
		updated_str = str;
	}
	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				token = updated_str;
				updated_str = str + i + 1;
				str[i] = '\0';
				return (token);
			}
		}

	}
	if (str[i] == '\0')
	{
		updated_str = NULL;
		token = updated_str;
		return (token);
	}
	return (NULL);
}

/**
 * skip_preceeding_delim - skips preceeding delimiter in a string
 * @str: string
 * @delim: delimiters
 * Return: pointer to string without preceeding delimiter
 */

char *skip_preceeding_delim(char *str, const char *delim)
{
	int signal = 0;
	int i, j, len;

	len = my_strlen(delim);

	for (i = 0; str[i];)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				str += 1;
				j = -1;
			}
			else if (j == len - 1)
			{
				signal = 1;
				break;
			}
		}
		if (signal == 1)
			break;
	}

	return (str);
}
