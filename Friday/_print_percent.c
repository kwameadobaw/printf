#include "main.h"
/**
 * _print_percent - Print a percent sign to a buffer
 * @buffer: The buffer to store the output
 * @remaining_size: REmaining space in the buffer
 * @args: The va_list (not used)
 * Return: The number of characters written to the buffer
*/
int _print_percent(char *buffer, size_t remaining_size, va_list args)
{
	(void)args;

	if (remaining_size > 1)
	{
		buffer[0] = '%';
		buffer[1] = '\0';
		return (1);
	}

	return (0);
}
