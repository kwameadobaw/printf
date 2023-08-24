#include "main.h"
/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: 1 on success, -1 on error
*/
int _putchar(char c)
{
	if (buffer_index == buffer_size - 1)
	{
		write(1, buffer, BUFFER_SIZE - 1);
		buffer_index = 0;
	}

	buffer[buffer_index++] = c;
	return (1);
}
