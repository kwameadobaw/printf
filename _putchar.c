#include "main.h"

int _putchar(char c)
{
	if (buffer_INDEX == buffer_size - 1)
	{
		write(1, buffer, BUFFER_SIZE - 1);
		buffer_index = 0;
	}

	buffer[buffer_index++] = c;
	return (1);
}
