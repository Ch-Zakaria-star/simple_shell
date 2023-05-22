#include "shell.h"

/**
 * my_strlen - determines the length of a string
 * @str: string
 * Return: length of the string
 */

size_t my_strlen(const char *str)
{
	size_t count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/**
 *my_strcpy - function to copy string
 * @dest: destination
 * @str: source
 * Return: string
 */

char *my_strcpy(char *dest, const char *str)
{
	char *p = dest;

	while (*str != '\0')
	{
		*p++ = *str++;
	}
	*p = '\0';
	return (dest);
}

/**
 *my_strcat - function to concatenate a string
 * @dest: destination
 * @src: source
 * Return: string
 */
char *my_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*ptr)
	{
		ptr++;
	}
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}

/**
 * my_strdup - function to duplicate a string
 * @str: string
 * Return: new_string
 */
char *my_strdup(const char *str)
{
	size_t length = my_strlen(str);
	char *new_str = malloc(length + 1);

	if (new_str == NULL)
	{
		return (NULL);
	}
	my_strcpy(new_str, str);
	return (new_str);
}
