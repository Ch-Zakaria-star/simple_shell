#include "shell.h"

/**
 *  my_getline - reading line of text
 *  @lineptr: size of memory block
 *  @n: adjust a variable that keeps the array’s size
 *  @stream: stream from which the file will be read
 *Return: number of characters read
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufferSize = 128, i = 0;
	int c;
	char *buffer, *newBuffer;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	buffer = (char *)malloc(bufferSize);
	if (buffer == NULL)
	{
		return (-1);
	}
	while ((c = my_fgetc(stream)) != EOF)
	{
		if (i >= bufferSize - 1)
		{
			bufferSize *= 2;
			newBuffer = (char *)realloc(buffer, bufferSize);
			if (newBuffer == NULL)
			{
				free(buffer);
				return (-1);
			}
			buffer = newBuffer;
		}
		buffer[i++] = c;
		if (c == '\n')
		{
			break;
		}
	}
	buffer[i] = '\0';
	*lineptr = buffer;
	*n = bufferSize;
	if (i == 0 && c == EOF)
	{
		free(buffer);
		return (-1);/* no characters read */
	}
	return (i); /* return number of characters read */
}

/**
 * my_fgetc - obtaining input from a file single character
 * @stream: pointer to a FILE
 * Return: string
 */
int my_fgetc(FILE *stream)
{
	int fd;
	unsigned char ch;
	ssize_t bytes_read;

	if (stream == NULL)
	{
		return (EOF);
	}
	fd = my_fileno(stream);
	bytes_read = read(fd, &ch, sizeof(unsigned char));

	if (bytes_read == 0)
	{
		return (EOF);
	}
	else if (bytes_read < 0)
	{
		return (EOF);
	}
	return (ch);
}

/**
 * my_fileno - describing the file
 * @stream: argument
 * Return: integer
 */
int my_fileno(FILE *stream)
{
	int fd = -1;

	if (stream != NULL)
	{
		struct _IO_FILE *file = (struct _IO_FILE *)stream;

		fd = file->_fileno;
	}
	return (fd);
}
