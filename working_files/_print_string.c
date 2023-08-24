#include "main.h"
/**
 * _print_string - Print a string to a buffer
 * @buffer: The buffer to store the output
 * @remaining_size: Remaining space in the buffer
 * @str: The string to print
 * Return: The number of characters written to the buffer
*/
int _print_string(char *buffer, size_t remaining_size, const char *str)
{
	int chars_written;
	chars_written = 0;

	while (*str && chars_written < (int)(remaining_size - 1))
	{
		buffer[chars_written++] = *str;
		str++;
	}

	buffer[chars_written] = '\0';
	return (chars_written);
}
