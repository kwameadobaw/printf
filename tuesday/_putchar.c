#include "main.h"
/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: 1 on success, -1 on error
*/
int _putchar(char c)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index = 0;

	if (buffer_index == BUFFER_SIZE - 1)
	{
		write(1, buffer, buffer_index);
		buffer_index = 0;
	}

	buffer[buffer_index++] = c;
	return (1);
}
