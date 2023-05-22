#include "shell.h"

/**
 * _strstr - finds the first occurrence of the
 * substring needle in the string haystack.
 * @haystack: string to find substring
 * @needle: substring to be found in the string
 * Return: pointer to the beginning of the located sunstring
 */

char *_strstr(char *haystack, const char *needle)
{
	int i;
	char *haystack_copy;

	/*return NULL if haystack is NULL*/
	if (haystack == NULL || needle == NULL)
		return (NULL);

	haystack_copy = haystack;

	for (i = 0; haystack_copy[i]; i++)
	{
		if (haystack_copy[i] == *needle)
		{
			return (haystack_copy + (i + 1));
		}
	}

	return (NULL);
}
