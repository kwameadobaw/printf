#include "main.h"

int _putchar(char c)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index;

	if (buffer_index == (BUFFER_SIZE) - 1)
	{
		write(1, buffer, BUFFER_SIZE - 1);
		BUFFER_INDEX = 0;
	}

	buffer[buffer_indexx++] = c;
	return (1);
}
