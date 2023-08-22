#include "main.h"
/**
 * _putchar - Writes a character to the output buffer
 * @c: The character to be written
 *
 * return: Return 1.
*/

int _putchar(char c)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index;

	if (buffer_index == (BUFFER_SIZE) - 1)
	{
		write(1, buffer, BUFFER_SIZE - 1);
		buffer_index = 0;
	}

	buffer[buffer_index++] = c;
	return (1);
}
