#include "main.h"

int _putchar(char c)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index = 0;
	static int buffer_size = BUFFER_SIZE;
	static int buffer_INDEX;

	if (buffer_INDEX == buffer_size - 1)
	{
		write(1, buffer, BUFFER_SIZE - 1);
	}

	buffer[buffer_index++] = c;
	return (1);
}
