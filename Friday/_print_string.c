#include "main.h"
/**
 * _print_string - Print a string to a buffer
 * @buffer: The buffer to store the output
 * @remaining_size: Remaining space in the buffer
 * @args: The va_list containing the string argument
 * Return: The number of characters written to the buffer
*/
int _print_string(char *buffer, size_t remaining_size, va_list args)
{
	char *str = va_arg(args, char *);
	int chars_written = 0;
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0' && remaining_size > 1; i++)
	{
		buffer[i] = str[i];
		remaining_size--;
		chars_written++;
	}

	buffer[i] = '\0';
	return (chars_written);
}
