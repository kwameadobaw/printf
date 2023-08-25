#include "main.h"
/**
 * _print_char - Print a character to a buffer
 * @buffer: The buffer to store the output
 * @remaining_size: Remaining space in the buffer
 * @args: THe va_list containing the character argument
 * Return: The number of characters written to the buffer
*/
int _print_char(char *buffer, size_t remaining_size, va_list args)
{
	char c = va_arg(args, int);

	if (remaining_size > 1)
	{
		buffer[0] = c;
		buffer[1] = '\0';
		return (1);
	}

	return (0);
}
