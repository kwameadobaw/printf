#include "main.h"
/**
 * _print_unsigned - Print an unsigned integer to a buffer
 * @buffer: The buffer to store the output
 * @remaining_size: Remaining space in the buffer
 * @args: The va_list containing the unsigned integer argument 
 * Return: The number of characters written to the buffer
*/
int _print_unsigned(char *buffer, size_t remaining_size, va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (_print_number_base(n, 10, 0, buffer, remaining_size));
}
