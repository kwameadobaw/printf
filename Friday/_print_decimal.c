#include "main.h"
/**
 * _print_decimal - Print a decimal number to a buffer
 * @buffer: The buffer to store the output
 * @remaining_size: Remaining space in the buffer
 * @args: The va_list containing the integer argument
 * Return: The number of characters written to the buffer
*/
int _print_decimal(char *buffer, size_t remaining_size, va_list args)
{
	int n = va_arg(args, int);
	int chars_written = 0;

	if (n < 0)
	{
		if (remaining_size > 1)
		{
			buffer[0] = '-';
			buffer++;
			remaining_size--;
			chars_written++;
		}

		n = -n;
	}

	chars_written += _print_number(n, buffer, remaining_size);

	return (chars_written);
}
