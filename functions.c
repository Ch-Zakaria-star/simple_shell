#include "simple_shell.h"

/**
 * _strdup - duplicates a string
 * @s: string to duplicate
 * Return: duplcated string
 */

char *_strdup(char *s)
{
	char *ptr;
	int i, count;

	count = 0;
	if (s == NULL)
		return (NULL);
	count = _strlen(s);
	ptr = malloc(sizeof(char) * (count + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}

/**
 * _strconcat - concatinates two strings
 * @s1: first string
 * @s2: second string
 * Return: concatinated string
 */

char *_strconcat(char *s1, char *s2)
{
	char *strcon;
	int i, j, count;

	j = 0;
	count = _strlen(s1) + _strlen(s2) + 2;
	strcon = malloc(sizeof(char) * count);
	if (strcon == NULL)
		return (NULL);
	for (i = 0; s1 && s1[i] != '\0'; i++)
	{
		strcon[j] = s1[i];
		j++;
	}
	if (j != 0)
	{
		strcon[j] = '/';
		j++;
	}
	for (i = 0; s2 && s2[i] != '\0'; i++)
	{
		strcon[j] = s2[i];
		j++;
	}
	strcon[j] = '\0';
	free_function(1, s2);
	return (strcon);
}

/**
 * _strlen - finds the length of a given string
 * @s: string parameter
 * Return: length of the string
 */

int _strlen(char *s)
{
	int count;

	for (count = 0; s[count] != '\0'; count++)
		;
	return (count);
}

/**
 * _strcmp - compares two string
 * @s1: first string
 * @s2:  second string
 * Return: true if the same else 0 if not
 */

int _strcmp(char *s1, char *s2)
{
	int diff, index;

	diff = index = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		diff = s1[index] - s2[index];
		if (diff != 0)
			break;
		index++;
	}
	return (diff);
}

/**
 * _atoi - converts a string to integer type
 * @s: string to convert
 * Return: 1 on success or 0 if not
 */

int _atoi(char *s)
{
	int x;
	unsigned int number = 0;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] > '9' || s[x] < '0')
			return (-1);
	}
	for (x = 0; s[x] != '\0'; x++)
		number = number * 10 + (s[x] - '0');
	return (number);
}
